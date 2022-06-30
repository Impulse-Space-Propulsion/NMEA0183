#if ! defined( RMC_CLASS_HEADER )

#define RMC_CLASS_HEADER

class RMC : public RESPONSE
{
   public:

      inline RMC() noexcept : RESPONSE(STRING_VIEW("RMC")) {}

      /*
      ** Data
      */

      std::string      UTCTime;
      time_t           Time{ 0 };
      NMEA0183_BOOLEAN IsDataValid{ NMEA0183_BOOLEAN::NMEA_Unknown };
      LATLONG          Position;
      double           SpeedOverGroundKnots{ 0.0 };
      double           TrackMadeGoodDegreesTrue{ 0.0 };
      std::string      Date;
      double           MagneticVariation{ 0.0 };
      EASTWEST         MagneticVariationDirection{ EASTWEST::EW_Unknown };
      FAA_MODE         FAAMode{ FAA_MODE::ModeUnknown };

      /*
      ** Methods
      */

      void Empty( void ) noexcept override;
      bool Parse( SENTENCE const& sentence ) noexcept override;
      std::string PlainEnglish( void ) const noexcept override;
      bool Write( SENTENCE& sentence ) const noexcept override;

      /*
      ** Operators
      */

      virtual RMC const& operator = ( RMC const& source ) noexcept;
};

#endif // RMC_CLASS_HEADER