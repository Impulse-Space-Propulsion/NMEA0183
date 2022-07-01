#if ! defined( LORAN_TIME_DIFFERENCE_CLASS_HEADER )

#define LORAN_TIME_DIFFERENCE_CLASS_HEADER

enum class LORAN_SIGNAL_STATUS
{
   LoranUnknown = 0,
   LoranValid,
   LoranBlinkWarning,
   LoranCycleWarning,
   LoranSignalToNoiseRatioWarning
};

class LORAN_TIME_DIFFERENCE
{
   public:

      inline LORAN_TIME_DIFFERENCE() noexcept {};

      /*
      ** Data
      */

      double              Microseconds{ 0.0 };
      LORAN_SIGNAL_STATUS SignalStatus{ LORAN_SIGNAL_STATUS::LoranUnknown };

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual void Parse( int field_number, SENTENCE const& sentence ) noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual LORAN_TIME_DIFFERENCE const& operator = ( LORAN_TIME_DIFFERENCE const& source ) noexcept;
};

#endif // LORAN_TIME_DIFFERENCE_CLASS_HEADER
