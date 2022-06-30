#if ! defined( VTG_CLASS_HEADER )

#define VTG_CLASS_HEADER

class VTG : public RESPONSE
{
   public:

      inline VTG() noexcept : RESPONSE(STRING_VIEW("VTG")) {}

      /*
      ** Data
      */

      double TrackDegreesTrue{ 0.0 };
      double TrackDegreesMagnetic{ 0.0 };
      double SpeedKnots{ 0.0 };
      double SpeedKilometersPerHour{ 0.0 };

      /*
      ** Methods
      */

      void Empty( void ) noexcept override;
      bool Parse( SENTENCE const& sentence ) noexcept override;
      bool Write( SENTENCE& sentence ) const noexcept override;

      /*
      ** Operators
      */

      virtual VTG const& operator = ( VTG const& source ) noexcept;
};

#endif // VTG_CLASS_HEADER