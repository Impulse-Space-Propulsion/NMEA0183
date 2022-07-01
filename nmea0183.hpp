#if ! defined( NMEA_0183_CLASS_HEADER )

#define NMEA_0183_CLASS_HEADER

/*
** General Purpose Classes
*/

#include "sentence.hpp"
#include "response.hpp"
#include "latlong.hpp"
#include "lorantd.hpp"
#include "manufact.hpp"
#include "mlist.hpp"
#include "omegapar.hpp"
#include "deccalop.hpp"
#include "ratiopls.hpp"
#include "radardat.hpp"
#include "satdat.hpp"
#include "freqmode.hpp"

/*
** Response Classes
*/

#include "gga.hpp"
#include "gll.hpp"
#include "rmc.hpp"
#include "vtg.hpp"
#include "p.hpp"

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
      HOW TO USE THIS CLASS
      Normally, you don't care about most sentences.
      Modify the declaration of this class (or copy this class to your own
      class) and get rid of the sentences you don't care about. For example,
      if you're interfacing with a device that will NEVER produce an AAM sentence,
      get rid of the Aam member. Don't have code that will never be called.
      */

      /*
      ** NMEA 0183 Sentences we understand
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
