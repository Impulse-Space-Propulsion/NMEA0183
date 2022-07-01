#if ! defined( FREQUENCY_AND_MODE_CLASS_HEADER )

#define FREQUENCY_AND_MODE_CLASS_HEADER

class FREQUENCY_AND_MODE
{
   public:

      inline FREQUENCY_AND_MODE() noexcept {};

      /*
      ** Data
      */

      double              Frequency{ 0.0 };
      COMMUNICATIONS_MODE Mode{ COMMUNICATIONS_MODE::CommunicationsModeUnknown };

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual void Parse( int field_number, SENTENCE const& sentence ) noexcept;
      virtual void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual FREQUENCY_AND_MODE const& operator = ( FREQUENCY_AND_MODE const& source ) noexcept;
};

#endif // FREQUENCY_AND_MODE_CLASS_HEADER
