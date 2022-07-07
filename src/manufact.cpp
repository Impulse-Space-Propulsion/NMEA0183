#include "NMEA0183/nmea0183.h"

MANUFACTURER::MANUFACTURER( std::string_view mnemonic, std::string_view company_name )
{
   Mnemonic    = mnemonic;
   CompanyName = company_name;
}
