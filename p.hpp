#if ! defined( P_CLASS_HEADER )

#define P_CLASS_HEADER

class P : public RESPONSE
{
   public:

      inline P() noexcept : RESPONSE(STRING_VIEW("P")) {}

      /*
      ** Data
      */

      MANUFACTURER_LIST Manufacturers;

      std::string Sentence;
      std::string Source;
      std::string CompanyName;

      /*
      ** Methods
      */

      void Empty( void ) noexcept override;
      bool Parse( SENTENCE const& sentence ) noexcept override;
      bool Write( SENTENCE& sentence ) const noexcept override;

      /*
      ** Operators
      */

      virtual P const& operator = ( P const& source ) noexcept;
};

#endif // P_CLASS_HEADER
