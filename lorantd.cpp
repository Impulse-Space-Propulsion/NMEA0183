#include "nmea0183.h"
#pragma hdrstop

void LORAN_TIME_DIFFERENCE::Empty( void ) noexcept
{
   Microseconds = 0.0;
   SignalStatus = LORAN_SIGNAL_STATUS::LoranUnknown;
}

void LORAN_TIME_DIFFERENCE::Parse( int first_field_number, SENTENCE const& sentence ) noexcept
{
   Microseconds = sentence.Double( first_field_number );

   auto field_data = sentence.Field( first_field_number + 1 );

   if (field_data.length() == 1)
   {
       if (field_data[0] == 'B')
       {
           SignalStatus = LORAN_SIGNAL_STATUS::LoranBlinkWarning;
       }
       else if (field_data[0] == 'C')
       {
           SignalStatus = LORAN_SIGNAL_STATUS::LoranCycleWarning;
       }
       else if (field_data[0] == 'S')
       {
           SignalStatus = LORAN_SIGNAL_STATUS::LoranSignalToNoiseRatioWarning;
       }
       else if (field_data[0] == 'A')
       {
           SignalStatus = LORAN_SIGNAL_STATUS::LoranValid;
       }
       else
       {
           SignalStatus = LORAN_SIGNAL_STATUS::LoranUnknown;
       }
   }
   else
   {
       SignalStatus = LORAN_SIGNAL_STATUS::LoranUnknown;
   }
}

void LORAN_TIME_DIFFERENCE::Write( SENTENCE& sentence ) const noexcept
{
   sentence += Microseconds;

   switch( SignalStatus )
   {
   case LORAN_SIGNAL_STATUS::LoranValid:
      
         sentence += STRING_VIEW("A");
         break; 

   case LORAN_SIGNAL_STATUS::LoranBlinkWarning:
      
         sentence += STRING_VIEW("B");
         break; 

   case LORAN_SIGNAL_STATUS::LoranCycleWarning:
      
         sentence += STRING_VIEW("C");
         break; 

   case LORAN_SIGNAL_STATUS::LoranSignalToNoiseRatioWarning:
      
         sentence += STRING_VIEW("S");
         break; 

      default:

         sentence += STRING_VIEW("");
   }
}

LORAN_TIME_DIFFERENCE const& LORAN_TIME_DIFFERENCE::operator = ( LORAN_TIME_DIFFERENCE const& source ) noexcept
{
   Microseconds = source.Microseconds;
   SignalStatus = source.SignalStatus;

   return( *this );
}
