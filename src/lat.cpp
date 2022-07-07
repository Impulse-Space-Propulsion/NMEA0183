<<<<<<< HEAD:lat.cpp
#include "nmea0183.h"
#pragma hdrstop
=======
#include "NMEA0183/nmea0183.h"
>>>>>>> 7049222a73ef9d6ebd2e977807d27bcdd09a2403:src/lat.cpp

void LATITUDE::Empty( void ) noexcept
{
   Latitude = 0.0;
   Northing = NORTHSOUTH::NS_Unknown;
}

bool LATITUDE::IsDataValid( void ) const noexcept
{
   if ( Northing not_eq NORTHSOUTH::North and Northing not_eq NORTHSOUTH::South )
   {
      return( false );
   }

   return( true );
}

void LATITUDE::Parse( int position_field_number, int north_or_south_field_number, SENTENCE const& sentence ) noexcept
{
   // Thanks go to Eric Parsonage (ericpa@mpx.com.au) for finding a nasty
   // little bug that used to live here.

   double const position = sentence.Double( position_field_number );

   auto north_or_south = sentence.Field( north_or_south_field_number );

   Set( position, north_or_south );
}

void LATITUDE::Set( double position, std::string_view north_or_south ) noexcept
{
   Latitude   = position;
   Coordinate = position;

   if (north_or_south.empty() == true)
   {
       Northing = NORTHSOUTH::NS_Unknown;
       return;
   }

   if ( north_or_south[ 0 ] == 'N' )
   {
      Northing = NORTHSOUTH::North;
   }
   else if ( north_or_south[ 0 ] == 'S' )
   {
      Northing = NORTHSOUTH::South;
   }
   else
   {
      Northing = NORTHSOUTH::NS_Unknown;
   }
}

void LATITUDE::Write( SENTENCE& sentence ) const noexcept
{
   char temp_string[ 80 ];

   std::size_t const number_of_characters = ::sprintf( temp_string, "%07.3f", Latitude );
   sentence += std::string_view( temp_string, number_of_characters);

   if ( Northing == NORTHSOUTH::North )
   {
      sentence += STRING_VIEW("N");
   }
   else if ( Northing == NORTHSOUTH::South )
   {
      sentence += STRING_VIEW("S");
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

LATITUDE const& LATITUDE::operator = ( LATITUDE const& source ) noexcept
{
   Latitude = source.Latitude;
   Northing = source.Northing;

   return( *this );
}

// COORDINATE stuff

// Coordinates are in the format dddmm.ddd
// For example, 76 degrees 46.887 minutes would be 7646.887

double COORDINATE::GetDecimalDegrees( void ) const noexcept
{
   int degrees = static_cast<int>(::floor( Coordinate ));
   int minutes = degrees % 100;

   double throw_away = 0.0;

   double fractional_minutes = ::modf( Coordinate, &throw_away );

   degrees -= minutes;
   degrees /= 100;

   double return_value = degrees;
   return_value += static_cast<double>( static_cast<double>(minutes) / static_cast<double>(60.0) );
   return_value += static_cast<double>( static_cast<double>(fractional_minutes) / static_cast<double>(60.0) );

   return( return_value );
}

double COORDINATE::GetDecimalMinutes( void ) const noexcept
{
   int degrees = static_cast<int>(::floor( Coordinate ));
   int minutes = degrees % 100;

   double throw_away = 0.0;

   double fractional_minutes = ::modf( Coordinate, &throw_away );

   double return_value = static_cast<double>(minutes);
   return_value += fractional_minutes;

   return( return_value );
}

double COORDINATE::GetDecimalSeconds( void ) const noexcept
{
   double minutes = GetDecimalMinutes();

   double throw_away = 0.0;

   double fractional_minutes = ::modf( minutes, &throw_away );

   double return_value = static_cast<double>( static_cast<double>(fractional_minutes) * static_cast<double>(60.0) );

   return( return_value );
}
