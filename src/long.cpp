#include "NMEA0183/nmea0183.h"
#pragma hdrstop

void LONGITUDE::Empty( void ) noexcept
{
   Longitude = 0.0;
   Easting   = EASTWEST::EW_Unknown;
}

bool LONGITUDE::IsDataValid( void ) const noexcept
{
   if ( Easting not_eq EASTWEST::East and Easting not_eq EASTWEST::West )
   {
      return( false );
   }

   return( true );
}

void LONGITUDE::Parse( int position_field_number, int east_or_west_field_number, SENTENCE const& sentence ) noexcept
{
   // Thanks go to Eric Parsonage (ericpa@mpx.com.au) for finding a nasty
   // little bug that used to live here.

   double position = 0.0;

   position = sentence.Double( position_field_number );

   auto east_or_west = sentence.Field( east_or_west_field_number );

   Set( position, east_or_west );
}

void LONGITUDE::Set( double position, std::string_view east_or_west ) noexcept
{
   Longitude  = position;
   Coordinate = position;

   if (east_or_west.empty() == true)
   {
       Easting = EASTWEST::EW_Unknown;
       return;
   }

   if ( east_or_west[ 0 ] == 'E' )
   {
      Easting = EASTWEST::East;
   }
   else if ( east_or_west[ 0 ] == 'W' )
   {
      Easting = EASTWEST::West;
   }
   else
   {
      Easting = EASTWEST::EW_Unknown;
   }
}

void LONGITUDE::Write( SENTENCE& sentence ) const noexcept
{
   char temp_string[ 80 ];

   std::size_t number_of_characters = ::sprintf( temp_string, "%08.2f", Longitude );
   sentence += std::string_view(temp_string, number_of_characters );
   
   if ( Easting == EASTWEST::East )
   {
      sentence += STRING_VIEW("E");
   }
   else if ( Easting == EASTWEST::West )
   {
      sentence += STRING_VIEW("W");
   }
   else
   {
      /*
      ** Thanks to Jan-Erik Eriksson (Jan-Erik.Eriksson@st.se) for
      ** finding and fixing a bug here
      */

      sentence += STRING_VIEW("");
   }
}

LONGITUDE const& LONGITUDE::operator = ( LONGITUDE const& source ) noexcept
{
   Longitude = source.Longitude;
   Easting   = source.Easting;

   return( *this );
}
