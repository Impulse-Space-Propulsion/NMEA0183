#include "nmea0183.h"
#pragma hdrstop

std::string Hex( uint32_t const value ) noexcept
{
   char temp_string[ 65 ];

   std::size_t const number_of_characters = ::sprintf( temp_string, "%04" PRIX32, static_cast<unsigned long>(value) );

   return( std::string(temp_string, number_of_characters) );
}
