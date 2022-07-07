#include "NMEA0183/nmea0183.h"

void LATLONG::Empty( void ) noexcept
{
   Latitude.Empty();
   Longitude.Empty();
}

bool LATLONG::Parse( int LatitudePositionFieldNumber, int NorthingFieldNumber, int LongitudePositionFieldNumber, int EastingFieldNumber, SENTENCE const& LineToParse ) noexcept
{
   Latitude.Parse(  LatitudePositionFieldNumber, NorthingFieldNumber, LineToParse );
   Longitude.Parse( LongitudePositionFieldNumber, EastingFieldNumber, LineToParse );

   if ( Latitude.IsDataValid() == true and Longitude.IsDataValid() == true )
   {
      return( true );
   }
   else
   {
      return( false );
   }
}

std::string LATLONG::PlainEnglish( void ) const noexcept
{
   char temp_string[256];

   std::size_t number_of_characters = ::sprintf( temp_string, "Latitude %d %.5f", Latitude.GetWholeDegrees(), Latitude.GetDecimalMinutes() );

   std::string return_string(temp_string, number_of_characters);

   if ( Latitude.Northing == NORTHSOUTH::North )
   {
      return_string.append(STRING_VIEW(" North, Longitude "));
   }
   else
   {
      return_string.append(STRING_VIEW(" South, Longitude "));
   }

   number_of_characters = ::sprintf( temp_string, "%d %.5f", Longitude.GetWholeDegrees(), Longitude.GetDecimalMinutes() );

   return_string.append(temp_string, number_of_characters);

   if ( Longitude.Easting == EASTWEST::East )
   {
      return_string.append(STRING_VIEW(" East"));
   }
   else
   {
      return_string.append(STRING_VIEW(" West"));
   }

   return( return_string );
}

void LATLONG::Write( SENTENCE& sentence ) const noexcept
{
   Latitude.Write( sentence );
   Longitude.Write( sentence );
}

LATLONG const& LATLONG::operator = ( LATLONG const& source ) noexcept
{
   Latitude  = source.Latitude;
   Longitude = source.Longitude;

   return( *this );
}
