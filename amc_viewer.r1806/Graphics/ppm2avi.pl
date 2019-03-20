#!/usr/bin/perl -w
#
# Render ppm files into an avi.
#



my $framerate = 24;
my @files = ();
my @transforms = ();

while (@ARGV > 0) {
	my $arg = shift(@ARGV);
	if ($arg eq "-framerate") {
		(@ARGV > 0) || die "-framerate without a rate given.";
		$framerate = shift @ARGV;
		$framerate += 0;
		($framerate >= 0) || die "framerate of '$framerate' isn't valid!";
	} elsif ($arg eq "-transform") {
		(@ARGV > 0) || die "-transform without a transform given.";
		my $trans = shift @ARGV;
		if ($trans eq "vflip") {
			push @transforms, "pamflip -topbottom";
		} else {
			die "Unknown transform '$trans' given.";
		}
	} elsif ($arg eq "--") {
		@files = (@files, @ARGV);
		last;
	} elsif ($arg =~ /^-/) {
		die "Unrecognized argument '$arg'";
	} else {
		push @files, $arg;
	}
}

if (@files != 2) {
	die "Expecting exactly two files, (one the input pattern, one the output) to be given.";
}

my $input = $files[0];
my $output = $files[1];

($output =~ /\.avi$/) || die "Output file must end in .avi";

$input =~ s/X+/*/ || die "Input file should have a string of X's in it.";

$input =~ s/\.ppm$// || die "Input should have ppm extension.";


print "Transforming files matching '$input.ppm' to movie '$output'.\n";
print "  Frame rate: $framerate.\n";
print "  Transformations: " . join(", ", @transforms) . ".\n";

foreach my $in (<$input.ppm>) {
	my $out = $in;
	$out =~ s/.ppm$/.png/ || die "Bad filename '$in'";
	print "Converting $in\n";
	my @commands = (@transforms, "pnmtopng");
	$commands[0] = $commands[0] . " $in";
	my $command = join(" | ", @commands) . " > $out";
	system($command);
	system("convert $out $out");
}

#Convert png sequence to .avi:

my $command = "mencoder mf://$input.png -mf fps=$framerate -o $output -ffourcc DX50 -ovc lavc -lavcopts vcodec=mpeg4:mbd=1:trell:aic:vbitrate=2000";

print $command . "\n";

system($command);
