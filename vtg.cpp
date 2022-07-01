#include "nmea0183.h"
#pragma hdrstop

void VTG::Empty( void ) noexcept
{
   TrackDegreesTrue       = 0.0;
   TrackDegreesMagnetic   = 0.0;
   SpeedKnots             = 0.0;
   SpeedKilometersPerHour = 0.0;
}

bool VTG::Parse( SENTENCE const& sentence ) noexcept
{
   /*
   ** VTG - Track made good and Ground speed
   **
   **        1   2 3   4 5	 6 7   8 9
   **        |   | |   | |	 | |   | |
   ** $--VTG,x.x,T,x.x,M,x.x,N,x.x,K*hh<CR><LF>
   **
   ** Field Number: 
   **  1) Track Degrees
   **  2) T = True
   **  3) Track Degrees
   **  4) M = Magnetic
   **  5) Speed Knots
   **  6) N = Knots
   **  7) Speed Kilometers Per Hour
   **  8) K = Kilometers Per Hour
   **  9) Checksum
   */

   /*
   ** First we check the checksum...
   */

   if ( sentence.IsChecksumBad( 9 ) == NMEA0183_BOOLEAN::True )
   {
       SetErrorMessage(STRING_VIEW("Invalid Checksum"));
       return( false );
   } 

   TrackDegreesTrue       = sentence.Double( 1 );
   TrackDegreesMagnetic   = sentence.Double( 3 );
   SpeedKnots             = sentence.Double( 5 );
   SpeedKilometersPerHour = sentence.Double( 7 );

   return( true );
}

bool VTG::Write( SENTENCE& sentence ) const noexcept
{
   /*
   ** Let the parent do its thing
   */
   
   RESPONSE::Write( sentence );

   sentence += TrackDegreesTrue;
   sentence += STRING_VIEW("T");
   sentence += TrackDegreesMagnetic;
   sentence += STRING_VIEW("M");
   sentence += SpeedKnots;
   sentence += STRING_VIEW("N");
   sentence += SpeedKilometersPerHour;
   sentence += STRING_VIEW("K");

   sentence.Finish();

   return( true );
}

VTG const& VTG::operator = ( VTG const& source ) noexcept
{
   TrackDegreesTrue       = source.TrackDegreesTrue;
   TrackDegreesMagnetic   = source.TrackDegreesMagnetic;
   SpeedKnots             = source.SpeedKnots;
   SpeedKilometersPerHour = source.SpeedKilometersPerHour;

   return( *this );
}