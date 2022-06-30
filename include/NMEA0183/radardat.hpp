#if ! defined( RADAR_DATA_CLASS_HEADER )

#define RADAR_DATA_CLASS_HEADER

class RADAR_DATA
{
   public:

      inline RADAR_DATA() noexcept {};

      /*
      ** Data
      */

      double OriginRangeFromOwnShip{ 0.0 };
      double OriginBearingDegreesFromZero{ 0.0 };
      double VariableRangeMarkerRange{ 0.0 };
      double BearingLineDegreesFromZero{ 0.0 };

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual void Parse( int field_number, SENTENCE const& sentence ) noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual RADAR_DATA const& operator = ( RADAR_DATA const& source ) noexcept;
};

#endif // RADAR_DATA_CLASS_HEADER
