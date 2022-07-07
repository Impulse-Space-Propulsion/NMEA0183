<<<<<<< HEAD:satdat.cpp
#include "nmea0183.h"
#pragma hdrstop
=======
#include "NMEA0183/nmea0183.h"
>>>>>>> 7049222a73ef9d6ebd2e977807d27bcdd09a2403:src/satdat.cpp

void SATELLITE_DATA::Empty( void ) noexcept
{
   SatelliteNumber    = 0;
   ElevationDegrees   = 0;
   AzimuthDegreesTrue = 0;
   SignalToNoiseRatio = (-1);
}

void SATELLITE_DATA::Parse( int first_field_number, SENTENCE const& sentence ) noexcept
{
   SatelliteNumber    = sentence.Integer( first_field_number );
   ElevationDegrees   = sentence.Integer( first_field_number + 1 );
   AzimuthDegreesTrue = sentence.Integer( first_field_number + 2 );

   auto field_data = sentence.Field( first_field_number + 3 );

   if ( field_data.empty() == true )
   {
      SignalToNoiseRatio = (-1);
   }
   else
   {
      SignalToNoiseRatio = sentence.Integer( first_field_number + 3 );
   }
     
}

void SATELLITE_DATA::Write( SENTENCE& sentence ) const noexcept
{
   sentence += SatelliteNumber;
   sentence += ElevationDegrees;
   sentence += AzimuthDegreesTrue;

   if ( SignalToNoiseRatio == (-1) )
   {
      sentence += STRING_VIEW("");
   }
   else
   {
      sentence += SignalToNoiseRatio;
   }
}

SATELLITE_DATA const& SATELLITE_DATA::operator = ( SATELLITE_DATA const& source ) noexcept
{
   SatelliteNumber    = source.SatelliteNumber;
   ElevationDegrees   = source.ElevationDegrees;
   AzimuthDegreesTrue = source.AzimuthDegreesTrue;
   SignalToNoiseRatio = source.SignalToNoiseRatio;

   return( *this );
}
