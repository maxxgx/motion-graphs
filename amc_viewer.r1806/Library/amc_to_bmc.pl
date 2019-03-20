#!/usr/bin/perl -w
#
# Convert 'amc' to 'bmc' -- a binary variant.
#

my $skel;
my $motion;

if (@ARGV == 2) {
	($motion, $skel) = @ARGV;
} elsif (@ARGV == 1) {
	$motion = $ARGV[0];
	$skel = $motion;
	if (!($skel =~ s/_\d+\.amc$/\.asf/) || !(-e $skel)) {
		print "$skel (deduced from $motion) doesn't exist!\n";
		exit;
	}
} else {
	print "Please pass the name of an amc file and, optionally, the name of an asf file.\n";
	exit;
}

my $outfile = $motion;
$outfile =~ s/\.amc$/.bmc/;

if (!(-e $skel)) {
	print "Skeleton file '$skel' doesn't exist.\n";
	exit;
}

if (!(-e $motion)) {
	print "Motion file '$motion' doesn't exist.\n";
	exit;
}

#Removed: probably all the .bmc we generated anyway.
#if (-e $outfile) {
#	print "Output file '$outfile' already exists!\n";
#	exit;
#}

open OUTFILE, ">", $outfile;

open SKEL, "<", $skel;

my %dof; #degree-of-freedom count for each bone
my %children; #children array for each bone.

$dof{"root"} = 6; #root always has six dof, as far as I'm concerned.
$children{"root"} = [];

while (defined($line = <SKEL>) && !($line =~ /^:bonedata/)) {
	#get to bone data.
}

while (defined($line = <SKEL>) && ($line =~ /begin/)) {
	my $name = "";
	my @dof = ();
	while (defined($line = <SKEL>) && !($line =~ /end/)) {
		chomp($line);
		$line =~ s/\r$//;
		if ($line =~ /^\s*name\s+([^\s]+)/) {
			$name = $1;
		} elsif ($line =~ s/^\s*dof\s+//) {
			while ($line =~ s/^([r][xyz])\s*//) {
				push @dof, uc($1);
			}
		} else {
			#ignore.
		}
	}
	$name ne "" || die "Bone with no name!";
	!(exists $dof{$name}) || die "Bone $name with duplicate name!";
	$children{$name} = [];
	$dof{$name} = scalar(@dof);
}
if (!($line =~ /^:hierarchy/)) {
	while (defined($line = <SKEL>) && !($line =~ /^:hierarchy/)) {
		#get to hierarchy.
	}
}
while (defined($line = <SKEL>) && !($line =~ /^\s*begin/)) {
	#get to hierarchy begin.
}
while (defined($line = <SKEL>) && !($line =~ /^\s*end/)) {
	chomp($line);
	($line =~ s/^\s*([^\s]+)//) || die "can't get first name in '$line'!";
	my $name = $1;
	(exists $children{$name}) || die "bone '$name' doesn't seem to exist!";
	while ($line =~ s/^\s*([^\s]+)//) {
		push @{$children{$name}}, $1;
	}
}

my %bone_order;
my %dof_index;
my @stack = ("root");
my $count = 0;
my $dof_count = 0;
#print "Bone order:\n";
my $header = "";
while (@stack) {
	my $p = pop @stack;
#	print $count . ": " . $p . " (" . $dof{$p} . " DOF @ $dof_count)\n";
	$header .= pack("Z*N", $p, $dof{$p});
	$bone_order{$p} = $count;
	$dof_index{$p} = $dof_count;
	++$count;
	$dof_count += $dof{$p};
	push @stack, reverse sort @{$children{$p}};
}

close SKEL;

print OUTFILE pack("a4Na4N", "bmcD", 0, "skel", length($header) + 8);
print OUTFILE $header;

#Important variables from here on out:
#$dof_count, so we know how big to make the frames.
#%dof_index, so we know where to put data in each frame.
#%dof, so we can check each bone's dof.

open MOTION, "<", $motion;

my $frame = 1;
my @dof_array;
my $frame_template = "a4Nd$dof_count";
for (1 .. $dof_count) {
	push @dof_array, 0;
}
while (defined($line = <MOTION>) && !($line =~ /^$frame/)) {
	#seek to first frame
}
while (1) {
	++$frame;
	my %value_arrays;
	my $dof_read = 0;
	while (defined($line = <MOTION>) && !($line =~ /^$frame/)) {
		($line =~ s/^([^\s]+)\s+//) || die "Expecting a bone name in '$line'.\n";
		my $name = $1;
		my @values = ();
		while ($line =~ s/^([^\s]+)\s+//) {
			push @values, ($1 + 0);

		}
		scalar(@values) == $dof{$name} || die "Frame " . ($frame - 1) . ": got the wrong number of values (" . scalar(@values) . ", expecting " . $dof{$name} . ") for $name.";
		for my $i (0 .. scalar(@values)-1) {
			$dof_array[$i+$dof_index{$name}] = $values[$i];
		}
		$dof_read += @values;
	}

	$dof_read == $dof_count || die "Read $dof_read, expecting $dof_count.";

	print OUTFILE pack($frame_template, "fram", $frame - 2, @dof_array);

	if (!(defined($line))) {
		last;
	}
}
close MOTION;

#print "Read " . ($frame - 1) . " frames.\n";

close OUTFILE;
open OUTFILE, "+<", $outfile;
seek OUTFILE, 4, 0; #seek to frame number.
print OUTFILE pack("N", $frame - 1);
close OUTFILE;


