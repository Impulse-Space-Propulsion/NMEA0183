#include "NMEA0183/nmea0183.h"
#pragma hdrstop

void RESPONSE::SetContainer( NMEA0183 *container ) noexcept
{
   container_p = container;
}

void RESPONSE::SetErrorMessage(std::string_view error_message) noexcept
{
   ErrorMessage  = Mnemonic;
   ErrorMessage.append(STRING_VIEW(", "));
   ErrorMessage.append(error_message);
}

bool RESPONSE::Write( SENTENCE& sentence ) const noexcept
{
   /*
   ** All NMEA0183 sentences begin with the mnemonic...
   **
   ** Thanks to Jan-Erik Eriksson (Jan-Erik.Eriksson@st.se) for
   ** finding and fixing a bug here
   */

   sentence = "$" + DataSource + Mnemonic;

   return( true );
}

std::string RESPONSE::PlainEnglish( void ) const noexcept
{
   std::string return_string;

   return( return_string );
}
