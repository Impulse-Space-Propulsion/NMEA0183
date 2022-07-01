#if ! defined( GLL_CLASS_HEADER )

#define GLL_CLASS_HEADER

class GLL : public RESPONSE
{
   public:

      inline GLL() noexcept : RESPONSE(STRING_VIEW("GLL")) {}

      /*
      ** Data
      */

      std::string      UTCTime;
      time_t           Time{ 0 };
      NMEA0183_BOOLEAN IsDataValid{ NMEA0183_BOOLEAN::NMEA_Unknown };
      LATLONG          Position;

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

      virtual GLL const& operator = ( GLL const& source ) noexcept;
};

#endif // GLL_CLASS_HEADER
