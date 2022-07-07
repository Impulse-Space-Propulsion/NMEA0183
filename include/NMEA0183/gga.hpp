#if ! defined( GGA_CLASS_HEADER )

#define GGA_CLASS_HEADER

class GGA : public RESPONSE
{
   public:

      inline GGA() noexcept : RESPONSE(STRING_VIEW("GGA")) {}

      /*
      ** Data
      */

      std::string UTCTime;
      time_t      Time{ 0 };
      LATLONG     Position;
      int         GPSQuality{ 0 };
      int         NumberOfSatellitesInUse{ 0 };
      double      HorizontalDilutionOfPrecision{ 0.0 };
      double      AntennaAltitudeMeters{ 0.0 };
      double      GeoidalSeparationMeters{ 0.0 };
      double      AgeOfDifferentialGPSDataSeconds{ 0.0 };
      int         DifferentialReferenceStationID{ 0 };

      /*
      ** Methods
      */

      void Empty( void ) noexcept override;
      std::string PlainEnglish( void ) const noexcept override;
      bool Parse( SENTENCE const& sentence ) noexcept override;
      bool Write( SENTENCE& sentence ) const noexcept override;

      /*
      ** Operators
      */

      virtual GGA const& operator = ( GGA const& source ) noexcept;
};

#endif // GGA_CLASS_HEADER
