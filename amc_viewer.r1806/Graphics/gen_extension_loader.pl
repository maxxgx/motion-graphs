#!/usr/bin/perl -w

#
# Usage: ./gen_extension_loader.pl <path/to/glext.h>
#
# Dumps the code to load (a hell of a lot) of gl extensions.
#

if (@ARGV != 1) {
	print "Yo, give me the path to glext.h\n";
	exit(1);
}

open GLEXT, "<", $ARGV[0];

@ext_names = ();
$current_ext_name = "";
$current_ext_short = "";
%functions = ();

while ($line = <GLEXT>) {
	chomp $line;
	if ($line =~ /^#ifndef GL_VERSION_/) {
		$current_ext_name = "NO";
	} elsif ($line =~ /^#ifndef (GL_([A-Z]+)_[a-z0-9_]+)/) {
		$current_ext_name = $1;
		$current_ext_short = $2;
		push @ext_names, $current_ext_name;
		$functions{$current_ext_name} = { }; #create anon hash?
	}
	if ($current_ext_name ne "NO") {
		if ($line =~ /^GLAPI ([^\s]+) APIENTRY ([a-zA-Z0-9]+)/) {
			$current_ext_name ne "" or die "Function outside of extension: $1 $2";
			$name = $2;
			$mangled_name = "PFN" . (uc $name) . "PROC";
			$functions{$current_ext_name}{$mangled_name}{'type'} = $1;
			$functions{$current_ext_name}{$mangled_name}{'name'} = $name;
		}
		if ($line =~ /^typedef ([^\s]+) \(APIENTRYP ([A-Z0-9]+)/) {
			defined $functions{$current_ext_name}{$2} or die "Couldn't locate $1 $2";
			$functions{$current_ext_name}{$2}{'type'} eq $1 or die "Types don't match for $2: $1, ${functions{$current_ext_name}{$2}{'type'}}";
			$functions{$current_ext_name}{$2}{'ok'} = 1;
		}
	}
}

close GLEXT;

print "Writing header...\n";

open HPP, ">", "GLExtensions.hpp";

print HPP <<EOF;
#ifndef GRAPHICS_GLEXTENSIONS_HPP
#define GRAPHICS_GLEXTENSIONS_HPP
//This header is all about getting your extensions properly managed.
//It is automatically generated. Don't be editing!

#include <Graphics/Graphics.hpp>
#undef __glext_h_
#undef GL_GLEXT_VERSION
#include "glext.h"
#undef GL_GLEXT_VERSION //and after soas no to conflict with SDL (yes, this is hacky)

//Use this macro to request an extension: (that is, it may be loaded and it
//may not. Check with have().

#define REQUEST_GL_EXTENSION( NAME )  \\
using namespace NAME ## _NAMESPACE;   \\
namespace {                           \\
class NAME ## _RequestClass {         \\
public:                               \\
	NAME ## _RequestClass() {         \\
		NAME ## _INTERNALS::request(); \\
	}                                 \\
} NAME ## _request;                   \\
} //end anon namespace

//Use this macro to require an extension: (code will fail in graphics::init()
//if macro used at global scope, otherwise inside function...)

#define REQUIRE_GL_EXTENSION( NAME )   \\
using namespace NAME ## _NAMESPACE;    \\
namespace {                            \\
class NAME ## _RequireClass {          \\
public:                                \\
	NAME ## _RequireClass() {          \\
		NAME ## _INTERNALS::require(); \\
	}                                  \\
} NAME ## _require;                    \\
} //end anon namespace

//--------------------------------------------

//Now on to the guts of the thing...
EOF

foreach my $extension (sort keys %functions) {
	print HPP <<EOF;

//  ...for $extension:
namespace ${extension}_NAMESPACE {
EOF
	foreach my $func (sort keys %{$functions{$extension}}) {
		$functions{$extension}{$func}{'ok'} or die "$func isn't marked as ok.";
		print HPP "\textern " . $func . " " . $functions{$extension}{$func}{'name'} . ";\n";
	}
	my $short = $extension;
	$short =~ s/^GL_//;
	print HPP <<EOF;

	extern bool have_${short}(); //<- for your use.

	//internal book-keeping stuff:
	class ${extension}_INTERNALS {
	public:
		//(calls auto-defer to graphics::init() if needed -- spiffy, huh?
		static void require(); //sees if it can load, then asserts have().
		static void request(); //tries to load.
	};
} //${extension}_NAMESPACE
EOF
}

print HPP <<EOF;
#endif //GRAPHICS_GLEXTENSIONS_HPP
EOF

close HPP;

print "Writing source...\n";

open CPP, ">", "GLExtensions.cpp";

print CPP <<EOF;
//This is auto-generated code, just like GLExtensions.hpp. Watch out!
#include "GLExtensions.hpp"
#include <iostream>
#include <assert.h>

using std::cerr;
using std::endl;
EOF

foreach my $extension (sort keys %functions) {
	my $short = $extension;
	$short =~ s/^GL_//;
	print CPP <<EOF;

//  ...for $extension:
namespace ${extension}_NAMESPACE {
EOF
	foreach my $func (sort keys %{$functions{$extension}}) {
		print CPP $func . " " . $functions{$extension}{$func}{'name'} . " = NULL;\n";
	}
	print CPP <<EOF;
	namespace {
		bool loaded = false;
		void load() {
			loaded = true
EOF
	foreach my $func (sort keys %{$functions{$extension}}) {
		print CPP "\t\t\t && (" . $functions{$extension}{$func}{'name'} . " = ($func)SDL_GL_GetProcAddress(\"" . $functions{$extension}{$func}{'name'} . "\"))\n";
	}
	print CPP <<EOF;
		;
		}
		void assert_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading required extension ${extension} fails." << endl;
			}
			assert(loaded);
		}
		void optional_load(void *) {
			load();
			if (!loaded) {
				cerr << "Loading (optional) extension ${extension} fails." << endl;
			}
		}
	}
	bool have_${short}() {
		return loaded;
	}
	void ${extension}_INTERNALS::require() {
		if (Graphics::initialized()) {
			assert_load(NULL);
		} else {
			Graphics::on_init(assert_load, NULL);
		}
	}
	void ${extension}_INTERNALS::request() {
		if (Graphics::initialized()) {
			optional_load(NULL);
		} else {
			Graphics::on_init(optional_load, NULL);
		}
	}
} //namespace ${extension}_NAMESPACE
EOF
}

close CPP;

