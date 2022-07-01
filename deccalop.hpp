#if ! defined( LINE_OF_POSITION_CLASS_HEADER )

#define LINE_OF_POSITION_CLASS_HEADER

class LINE_OF_POSITION
{
   public:

      inline LINE_OF_POSITION() noexcept {};

      /*
      ** Data
      */

      std::string      ZoneID;
      double           LineOfPosition{ 0.0 };
      NMEA0183_BOOLEAN MasterLine{ NMEA0183_BOOLEAN::NMEA_Unknown };

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual void Parse( int field_number, SENTENCE const& sentence ) noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual LINE_OF_POSITION const& operator = ( LINE_OF_POSITION const& source ) noexcept;
};

#endif // LINE_OF_POSITION_CLASS_HEADER
