#include "NMEA0183/nmea0183.h"

void RADAR_DATA::Empty( void ) noexcept
{
   OriginRangeFromOwnShip       = 0.0;
   OriginBearingDegreesFromZero = 0.0;
   VariableRangeMarkerRange     = 0.0;
   BearingLineDegreesFromZero   = 0.0;
}

void RADAR_DATA::Parse( int first_field_number, SENTENCE const& sentence ) noexcept
{
   OriginRangeFromOwnShip       = sentence.Double( first_field_number );
   OriginBearingDegreesFromZero = sentence.Double( first_field_number + 1 );
   VariableRangeMarkerRange     = sentence.Double( first_field_number + 2 );
   BearingLineDegreesFromZero   = sentence.Double( first_field_number + 3 );
}

void RADAR_DATA::Write( SENTENCE& sentence ) const noexcept
{
   sentence += OriginRangeFromOwnShip;
   sentence += OriginBearingDegreesFromZero;
   sentence += VariableRangeMarkerRange;
   sentence += BearingLineDegreesFromZero;
}

RADAR_DATA const& RADAR_DATA::operator = ( RADAR_DATA const& source ) noexcept
{
   OriginRangeFromOwnShip       = source.OriginRangeFromOwnShip;
   OriginBearingDegreesFromZero = source.OriginBearingDegreesFromZero;
   VariableRangeMarkerRange     = source.VariableRangeMarkerRange;
   BearingLineDegreesFromZero   = source.BearingLineDegreesFromZero;

   return( *this );
}
