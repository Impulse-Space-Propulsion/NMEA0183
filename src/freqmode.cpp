#include "NMEA0183/nmea0183.h"
#pragma hdrstop

void FREQUENCY_AND_MODE::Empty( void ) noexcept
{
   Frequency = 0.0;
   Mode      = COMMUNICATIONS_MODE::CommunicationsModeUnknown;
}

void FREQUENCY_AND_MODE::Parse( int first_field_number, SENTENCE const& sentence ) noexcept
{
   Frequency = sentence.Double( first_field_number );
   Mode      = sentence.CommunicationsMode( first_field_number + 1 );
}

void FREQUENCY_AND_MODE::Write( SENTENCE& sentence ) const noexcept
{
   sentence += Frequency;
   sentence += Mode;
}

FREQUENCY_AND_MODE const& FREQUENCY_AND_MODE::operator = ( FREQUENCY_AND_MODE const& source ) noexcept
{
   Frequency = source.Frequency;
   Mode      = source.Mode;

   return( *this );
}
