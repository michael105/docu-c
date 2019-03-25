#!/bin/perl -w
#

my @F;
my $fp;

sub grab{
		my $t = shift;
		my @a;
		while ( !( $F[$fp] =~ s/^\.$t (.*)\n/$1/ ) && ( $F[$fp++] ) ) {};
		do {
				push @a,$F[$fp]
		} while (( $F[$fp++] ) && ( $F[$fp] =~ s/^\.$t (.*).\n/$1/ ) );

		return( @a );
}


sub parse{

	 print "-", grab( "Nm" ), " := ", grab ("Nd");
	 # library = "Lb"
	 # files = "In"
	 grab( "!^Ft" );
	 while ( $F[$fp] =~ s/^.Ft (.*)\n/$1/ ){
			 print $F[$fp];
			 $fp ++;
			 $F[$fp] =~ /^.Fn (.*)\n/;
			 print $1;
			 $fp ++;
	 }


}
	

foreach my $fn ( @ARGV ){
		open $fh, "<", $fn or die;
		@F = <$fh>;
		close $fh;
		$fp = 0;
		parse( );
}


