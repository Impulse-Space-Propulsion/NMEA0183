#if ! defined( SATELLITE_DATA_CLASS_HEADER )

#define SATELLITE_DATA_CLASS_HEADER

class SATELLITE_DATA
{
   public:

      inline SATELLITE_DATA() noexcept {};

      /*
      ** Data
      */

      int SatelliteNumber{ 0 };
      int ElevationDegrees{ 0 };
      int AzimuthDegreesTrue{ 0 };
      int SignalToNoiseRatio{ -1 };

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual void Parse( int field_number, SENTENCE const& sentence ) noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual SATELLITE_DATA const& operator = ( SATELLITE_DATA const& source ) noexcept;
};

#endif // SATELLITE_DATA_CLASS_HEADER
