#include "NMEA0183/nmea0183.h"
#pragma hdrstop

std::string talker_id( std::string_view sentence ) noexcept
{
   std::string return_string;

   if ( sentence.length() >= 3 )
   {
      if ( sentence[ 0 ] == '$' )
      {
         return_string = sentence.substr( 1, 2 );
      }
   }

   return( return_string );
}
