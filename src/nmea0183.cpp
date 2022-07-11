#include "NMEA0183/nmea0183.h"

#if defined (__WIN32__)
  #define timegm _mkgmtime
#endif

static inline bool is_less_than(RESPONSE const * left, RESPONSE const * right) noexcept
{
    return(left->Mnemonic < right->Mnemonic);
}

NMEA0183::NMEA0183()
{
   m_Initialize();

   m_ResponseTable.push_back( static_cast<RESPONSE *>(&Gga) );
   m_ResponseTable.push_back( static_cast<RESPONSE *>(&Gll) );
   m_ResponseTable.push_back( static_cast<RESPONSE *>(&Rmc) );
   m_ResponseTable.push_back( static_cast<RESPONSE *>(&Vtg) );

   std::sort(std::begin(m_ResponseTable), std::end(m_ResponseTable), is_less_than);

   m_SetContainerPointers();
}

void NMEA0183::m_Initialize( void ) noexcept
{
   ErrorMessage.clear();
}

void NMEA0183::m_SetContainerPointers( void ) noexcept
{
   for (auto& entry : m_ResponseTable)
   {
       entry->SetContainer(this);
   }
}

/*
** Public Interface
*/

bool NMEA0183::IsGood( void ) const noexcept
{
   /*
   ** NMEA 0183 sentences begin with $ and and with CR LF
   */

   if ( m_Sentence.Sentence[ 0 ] not_eq '$' )
   {
      return( false );
   }

   /*
   ** Next to last character must be a CR
   */

   if ( m_Sentence.Sentence[ m_Sentence.Sentence.length() - 2 ] not_eq CARRIAGE_RETURN )
   {
      return( false );
   }

   if ( m_Sentence.Sentence[m_Sentence.Sentence.length() - 1 ] not_eq LINE_FEED )
   {
      return( false );
   }

   return( true );
}

bool NMEA0183::Parse( void ) noexcept
{
   bool return_value = false;

   if (IsGood())
   {
       auto mnemonic = m_Sentence.Field(0);

       /*
       ** See if this is a proprietary field
       */

       if (mnemonic[0] == 'P')
       {
           mnemonic = std::string_view("P",1);
       }
       else
       {
           mnemonic = mnemonic.substr(mnemonic.length() - 3, 3);
       }

       /*
       ** Set up our default error message
       */

       ErrorMessage.clear();

       LastSentenceIDReceived = mnemonic;

       /*
       ** Do a Binary Search to call the appropriate function
       */

       GENERIC_RESPONSE needle(mnemonic);

       auto iterator = std::lower_bound(std::begin(m_ResponseTable), std::end(m_ResponseTable), &needle, is_less_than);

       if (iterator not_eq std::end(m_ResponseTable) and (*iterator)->Mnemonic.compare(mnemonic) == 0)
       {
           return_value = (*iterator)->Parse(m_Sentence);

           /*
           ** Set your ErrorMessage
           */

           if (return_value == true)
           {
               /*
               ** Now that we sucessfully parsed a sentence, record stuff *about* the transaction
               */

               ErrorMessage.assign(STRING_VIEW("No Error"));
               LastSentenceIDParsed = (*iterator)->Mnemonic;
               TalkerID = talker_id(m_Sentence);
               ExpandedTalkerID = expand_talker_id(TalkerID);
               PlainText = (*iterator)->PlainEnglish();
           }
           else
           {
               ErrorMessage = (*iterator)->ErrorMessage;
           }
       }
       else
       {
           ErrorMessage = mnemonic;
           ErrorMessage.append(STRING_VIEW(" is an unknown type of sentence"));
           return_value = false;
       }
   }

   return( return_value );
}

void NMEA0183::SetSentence(std::string_view source) noexcept
{
    m_Sentence = source;
}

void NMEA0183::GetSentence(std::string& destination) const noexcept
{
    destination = m_Sentence;
}

time_t ctime(int const year, int const month, int const day, int const hour, int const minute, int const second) noexcept
{
    struct tm gtime;

    gtime.tm_sec = second;
    gtime.tm_min = minute;
    gtime.tm_hour = hour;
    gtime.tm_mday = day;
    gtime.tm_mon = month;
    gtime.tm_year = year - 1900;
    gtime.tm_wday = 0;
    gtime.tm_yday = 0;
    gtime.tm_isdst = 0;

    return(timegm(&gtime));
}
