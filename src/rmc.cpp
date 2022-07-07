<<<<<<< HEAD:rmc.cpp
#include "nmea0183.h"
#pragma hdrstop
=======
#include "NMEA0183/nmea0183.h"
>>>>>>> 7049222a73ef9d6ebd2e977807d27bcdd09a2403:src/rmc.cpp

void RMC::Empty( void ) noexcept
{
   UTCTime.clear();
   Time                       = 0;
   IsDataValid                = NMEA0183_BOOLEAN::NMEA_Unknown;
   Position.Empty();
   SpeedOverGroundKnots       = 0.0;
   TrackMadeGoodDegreesTrue   = 0.0;
   Date.clear();
   MagneticVariation          = 0.0;
   MagneticVariationDirection = EASTWEST::EW_Unknown;
   FAAMode                    = FAA_MODE::ModeUnknown;
}

bool RMC::Parse( SENTENCE const& sentence ) noexcept
{
   /*
   ** RMC - Recommended Minimum Navigation Information
   **                                                            12
   **        1         2 3       4 5        6 7   8   9    10  11|
   **        |         | |       | |        | |   |   |    |   | |
   ** $--RMC,hhmmss.ss,A,llll.ll,a,yyyyy.yy,a,x.x,x.x,xxxx,x.x,a*hh<CR><LF>
   **
   ** Field Number: 
   **  1) UTC Time
   **  2) Status, V = Navigation receiver warning
   **  3) Latitude
   **  4) N or S
   **  5) Longitude
   **  6) E or W
   **  7) Speed over ground, knots
   **  8) Track made good, degrees true
   **  9) Date, ddmmyy
   ** 10) Magnetic Variation, degrees
   ** 11) E or W
   ** 12) FAA Mode (version 2.3)
   ** 13) Checksum
   */

   /*
   ** First we check the checksum...
   */

    int checksum_field = 12;

   // Version 2.3 of the standard has things different

   FAAMode = sentence.FAAMode(12);

   if (FAAMode != FAA_MODE::ModeUnknown)
   {
       checksum_field = 13;
   }

   auto const check = sentence.IsChecksumBad(checksum_field);

   if (check == NMEA0183_BOOLEAN::True)
   {
       SetErrorMessage(STRING_VIEW("Invalid Checksum"));
       return(false);
   }

   if (check == NMEA0183_BOOLEAN::NMEA_Unknown)
   {
       SetErrorMessage(STRING_VIEW("Missing Checksum"));
       return(false);
   }

   UTCTime                    = sentence.Field( 1 );
   Time                       = sentence.Time( 1 );
   IsDataValid                = sentence.Boolean( 2 );
   Position.Parse( 3, 4, 5, 6, sentence );
   SpeedOverGroundKnots       = sentence.Double( 7 );
   TrackMadeGoodDegreesTrue   = sentence.Double( 8 );
   Date                       = sentence.Field( 9 );
   MagneticVariation          = sentence.Double( 10 );
   MagneticVariationDirection = sentence.EastOrWest( 11 );

   return( true );
}

std::string RMC::PlainEnglish( void ) const noexcept
{
   std::string return_string(STRING_VIEW("At "));
   std::string const time_string = ctime(&Time);
   return_string.append(time_string.substr(0, time_string.length() - 1));
   return_string.append(STRING_VIEW(" you were at "));
   return_string.append(Position.PlainEnglish());
   return_string.append(STRING_VIEW(", making "));
   return_string.append(std::to_string(SpeedOverGroundKnots));
   return_string.append(STRING_VIEW(" knots, track made good "));
   return_string.append(std::to_string(TrackMadeGoodDegreesTrue));
   return_string.append(STRING_VIEW(" degrees true."));

   return( return_string );
}

bool RMC::Write( SENTENCE& sentence ) const noexcept
{
   /*
   ** Let the parent do its thing
   */
   
   RESPONSE::Write( sentence );

   sentence += UTCTime;
   sentence += IsDataValid;
   Position.Write( sentence );
   // sentence += Position;
   sentence += SpeedOverGroundKnots;
   sentence += TrackMadeGoodDegreesTrue;
   sentence += Date;
   sentence += MagneticVariation;
   sentence += MagneticVariationDirection;
   sentence += FAAMode;

   sentence.Finish();

   return( true );
}

RMC const& RMC::operator = ( RMC const& source ) noexcept
{
   UTCTime                    = source.UTCTime;
   Time                       = source.Time;
   IsDataValid                = source.IsDataValid;
   Position                   = source.Position;
   SpeedOverGroundKnots       = source.SpeedOverGroundKnots;
   TrackMadeGoodDegreesTrue   = source.TrackMadeGoodDegreesTrue;
   Date                       = source.Date;
   MagneticVariation          = source.MagneticVariation;
   MagneticVariationDirection = source.MagneticVariationDirection;
   FAAMode                    = source.FAAMode;

  return( *this );
}