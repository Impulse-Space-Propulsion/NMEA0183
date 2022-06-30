#include "NMEA0183/nmea0183.h"
#pragma hdrstop

void OMEGA_PAIR::Empty( void ) noexcept
{
   Name.clear();
   LaneNumber      = 0;
   CentilaneNumber = 0;
}

void OMEGA_PAIR::Parse( int first_field_number, SENTENCE const& sentence ) noexcept
{
   Name            = sentence.Field( first_field_number );
   LaneNumber      = sentence.Integer( first_field_number + 1 );
   CentilaneNumber = sentence.Integer( first_field_number + 2 );
}

void OMEGA_PAIR::Write( SENTENCE& sentence ) const noexcept
{
   sentence += Name;
   sentence += LaneNumber;
   sentence += CentilaneNumber;
}

OMEGA_PAIR const& OMEGA_PAIR::operator = ( OMEGA_PAIR const& source ) noexcept
{
   Name            = source.Name;
   LaneNumber      = source.LaneNumber;
   CentilaneNumber = source.CentilaneNumber;

   return( *this );
}
