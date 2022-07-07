#if ! defined( LATLONG_CLASS_HEADER )

#define LATLONG_CLASS_HEADER

class SENTENCE;

class COORDINATE
{
   public:

      inline COORDINATE() noexcept {}
     ~COORDINATE() { Coordinate = 0.0; }

      double Coordinate{ 0.0 };

      double GetDecimalDegrees( void ) const noexcept;
      double GetDecimalMinutes( void ) const noexcept;
      double GetDecimalSeconds( void ) const noexcept;

      inline int GetWholeDegrees(void) const noexcept
      {
          return(static_cast<int>(::floor(GetDecimalDegrees())));
      }

      inline int GetWholeMinutes(void) const noexcept
      {
          return(static_cast<int>(::floor(GetDecimalMinutes())));
      }

      int GetWholeSeconds(void) const noexcept
      {
          return(static_cast<int>(::floor(GetDecimalSeconds())));
      }
};

class LATITUDE : public COORDINATE
{
   public:

       inline LATITUDE() noexcept : Latitude(0.0), Northing(NORTHSOUTH::NS_Unknown) {}

      /*
      ** Data
      */

      double Latitude{ 0.0 };
      NORTHSOUTH Northing{ NORTHSOUTH::NS_Unknown };

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual bool IsDataValid( void ) const noexcept;
      virtual void Parse( int PositionFieldNumber, int NorthingFieldNumber, SENTENCE const& LineToParse ) noexcept;
      virtual void Set( double Position, std::string_view Northing ) noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual LATITUDE const& operator = (LATITUDE const& source) noexcept;
};

class LONGITUDE : public COORDINATE
{
   public:

       inline LONGITUDE() noexcept : Longitude(0.0), Easting(EASTWEST::EW_Unknown) {}

      /*
      ** Data
      */

      double Longitude{ 0.0 };

      EASTWEST Easting{ EASTWEST::EW_Unknown };

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual bool IsDataValid( void ) const noexcept;
      virtual void Parse( int PositionFieldNumber, int EastingFieldNumber, SENTENCE const& LineToParse ) noexcept;
      virtual void Set( double Position, std::string_view Easting ) noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual LONGITUDE const& operator = ( LONGITUDE const& source ) noexcept;
};

class LATLONG
{
   public:

      inline LATLONG() noexcept {};

      /*
      ** Data
      */

      LATITUDE  Latitude;
      LONGITUDE Longitude;

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual bool Parse( int LatitudePostionFieldNumber, int NorthingFieldNumber, int LongitudePositionFieldNumber, int EastingFieldNumber, SENTENCE const& LineToParse ) noexcept;
      virtual std::string PlainEnglish( void ) const noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual LATLONG const& operator = ( LATLONG const& source ) noexcept;
};

#endif // LATLONG_CLASS_HEADER
