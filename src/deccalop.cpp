#include "NMEA0183/nmea0183.h"

void LINE_OF_POSITION::Empty( void ) noexcept
{
   ZoneID.clear();
   LineOfPosition = 0.0;
   MasterLine     = NMEA0183_BOOLEAN::NMEA_Unknown;
}

void LINE_OF_POSITION::Parse( int first_field_number, SENTENCE const& sentence ) noexcept
{
   ZoneID         = sentence.Field(   first_field_number );
   LineOfPosition = sentence.Double(  first_field_number + 1 );
   MasterLine     = sentence.Boolean( first_field_number + 2 );
}

void LINE_OF_POSITION::Write( SENTENCE& sentence ) const noexcept
{
   sentence += ZoneID;
   sentence += LineOfPosition;
   sentence += MasterLine;
}

LINE_OF_POSITION const& LINE_OF_POSITION::operator = ( LINE_OF_POSITION const& source ) noexcept
{
   ZoneID         = source.ZoneID;
   LineOfPosition = source.LineOfPosition;
   MasterLine     = source.MasterLine;

   return( *this );
}
