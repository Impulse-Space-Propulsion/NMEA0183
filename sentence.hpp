#if ! defined( SENTENCE_CLASS_HEADER )

#define SENTENCE_CLASS_HEADER

class LATLONG;

class SENTENCE
{
   public:

      inline SENTENCE() noexcept {};

      /*
      ** Data
      */

      std::string Sentence;

      /*
      ** Methods
      */

      virtual NMEA0183_BOOLEAN Boolean( int field_number ) const noexcept;
      virtual uint8_t ComputeChecksum( void ) const noexcept;
      virtual COMMUNICATIONS_MODE CommunicationsMode( int field_number ) const noexcept;
      virtual double Double( int field_number ) const noexcept;
      virtual EASTWEST EastOrWest( int field_number ) const noexcept;
      virtual std::string_view Field( int field_number ) const noexcept;
      virtual void Finish( void ) noexcept;
      virtual uint16_t GetNumberOfDataFields( void ) const noexcept;
      virtual int Integer( int field_number ) const noexcept;
      virtual NMEA0183_BOOLEAN IsChecksumBad( int checksum_field_number ) const noexcept;
      virtual LEFTRIGHT LeftOrRight( int field_number ) const noexcept;
      virtual NORTHSOUTH NorthOrSouth( int field_number ) const noexcept;
      virtual REFERENCE Reference( int field_number ) const noexcept;
      virtual time_t Time( int field_number ) const noexcept;
      virtual TRANSDUCER_TYPE TransducerType( int field_number ) const noexcept;
      virtual FAA_MODE FAAMode(int field_number) const noexcept;

      /*
      ** Operators
      */

      operator std::string() const noexcept;
      operator std::string_view() const noexcept;
      virtual SENTENCE const& operator  = ( SENTENCE const& source ) noexcept;
      virtual SENTENCE const& operator  = ( std::string_view source ) noexcept;
      virtual SENTENCE const& operator += ( std::string_view source ) noexcept;
      virtual SENTENCE const& operator += ( double const value ) noexcept;
      virtual SENTENCE const& operator += ( int const value ) noexcept;
      virtual SENTENCE const& operator += ( COMMUNICATIONS_MODE const mode ) noexcept;
      virtual SENTENCE const& operator += ( EASTWEST const easting ) noexcept;
      virtual SENTENCE const& operator += ( LATLONG const& source ) noexcept;
      virtual SENTENCE const& operator += ( NMEA0183_BOOLEAN const boolean ) noexcept;
      virtual SENTENCE const& operator += ( NORTHSOUTH const northing ) noexcept;
      virtual SENTENCE const& operator += ( time_t const time ) noexcept;
      virtual SENTENCE const& operator += ( TRANSDUCER_TYPE const transducer ) noexcept;
      virtual SENTENCE const& operator += ( LEFTRIGHT const left_or_right ) noexcept;
      virtual SENTENCE const& operator += ( REFERENCE const a_reference ) noexcept;
};

#endif // SENTENCE_CLASS_HEADER
