#include "NMEA0183/nmea0183.h"
#pragma hdrstop

void P::Empty( void ) noexcept
{
   Sentence.clear();
   Source.clear();
}

bool P::Parse( SENTENCE const& sentence ) noexcept
{
   /*
   ** This is where parsing of proprietary sentences will go...
   */

   Sentence = sentence;

   auto temp_string = sentence.Field( 0 );

   Source      = temp_string.substr( 1, 3 );
   CompanyName = Manufacturers.Find( Source );

   return( true );
}

bool P::Write( SENTENCE& sentence ) const noexcept
{
   /*
   ** Let the parent do its thing
   */
   
   RESPONSE::Write( sentence );

   sentence += Sentence;

   sentence.Finish();

   return( true );
}

P const& P::operator = ( P const& source ) noexcept
{
   Sentence = source.Sentence;

   return( *this );
}
