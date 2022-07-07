#include "NMEA0183/nmea0183.h"

void RATIO_AND_PULSE::Empty( void ) noexcept
{
   SignalToNoiseRatio = 0;
   PulseShapeECD      = 0;
}

void RATIO_AND_PULSE::Parse( int first_field_number, SENTENCE const& sentence ) noexcept
{
   SignalToNoiseRatio = sentence.Integer( first_field_number );
   PulseShapeECD      = sentence.Integer( first_field_number + 1 );
}

void RATIO_AND_PULSE::Write( SENTENCE& sentence ) const noexcept
{
   sentence += SignalToNoiseRatio;
   sentence += PulseShapeECD;
}

RATIO_AND_PULSE const& RATIO_AND_PULSE::operator = ( RATIO_AND_PULSE const& source ) noexcept
{
   SignalToNoiseRatio = source.SignalToNoiseRatio;
   PulseShapeECD      = source.PulseShapeECD;

   return( *this );
}
