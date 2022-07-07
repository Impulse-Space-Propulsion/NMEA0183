#if ! defined( NMEA_0183_CLASS_HEADER )

#define NMEA_0183_CLASS_HEADER

/*
** General Purpose Classes
*/

#include "NMEA0183/sentence.hpp"
#include "NMEA0183/response.hpp"
#include "NMEA0183/latlong.hpp"
#include "NMEA0183/lorantd.hpp"
#include "NMEA0183/manufact.hpp"
#include "NMEA0183/mlist.hpp"
#include "NMEA0183/omegapar.hpp"
#include "NMEA0183/deccalop.hpp"
#include "NMEA0183/ratiopls.hpp"
#include "NMEA0183/radardat.hpp"
#include "NMEA0183/satdat.hpp"
#include "NMEA0183/freqmode.hpp"

/*
** Response Classes
*/

#include "NMEA0183/gga.hpp"
#include "NMEA0183/gll.hpp"
#include "NMEA0183/rmc.hpp"
#include "NMEA0183/vtg.hpp"
#include "NMEA0183/p.hpp"

class NMEA0183
{
   private:

      SENTENCE m_Sentence;

      void m_Initialize( void ) noexcept;

   protected:

      std::vector<RESPONSE *> m_ResponseTable;

      void m_SetContainerPointers( void ) noexcept;

   public:

      NMEA0183();

      /*
      ** NMEA 0183 Sentences (more in full cloned dir as needed)
      */

      GGA Gga;
      GLL Gll;
      RMC Rmc;
      VTG Vtg;
      P   Proprietary;

      std::string ErrorMessage; // Filled when Parse returns FALSE
      std::string LastSentenceIDParsed; // ID of the lst sentence successfully parsed
      std::string LastSentenceIDReceived; // ID of the last sentence received, may not have parsed successfully
      std::string PlainText; // A human-readable string of text that explains what just happened

      std::string TalkerID;
      std::string ExpandedTalkerID;

      virtual bool IsGood( void ) const noexcept;
      virtual bool Parse( void ) noexcept;
      virtual void SetSentence(std::string_view source) noexcept;
      virtual void GetSentence(std::string& destination) const noexcept;

      inline NMEA0183& operator << (std::string_view source) noexcept
      {
          SetSentence(source);
          return(*this);
      }

      inline NMEA0183& operator >> (std::string& destination) noexcept
      {
          GetSentence(destination);
          return(*this);
      }
};

#endif // NMEA_0183_CLASS_HEADER
