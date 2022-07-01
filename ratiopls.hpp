#if ! defined( RATIO_AND_PULSE_CLASS_HEADER )

#define RATIO_AND_PULSE_CLASS_HEADER

class RATIO_AND_PULSE
{
   public:

      inline RATIO_AND_PULSE() noexcept {};

      /*
      ** Data
      */

      int SignalToNoiseRatio{ 0 };
      int PulseShapeECD{ 0 };

      /*
      ** Methods
      */

      void Empty( void ) noexcept;
      void Parse( int field_number, SENTENCE const& sentence ) noexcept;
      void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual RATIO_AND_PULSE const& operator = ( RATIO_AND_PULSE const& source ) noexcept;
};

#endif // RATIO_AND_PULSE_CLASS_HEADER
