#if ! defined( RESPONSE_CLASS_HEADER )

#define RESPONSE_CLASS_HEADER

class NMEA0183;

class RESPONSE
{
   private:

       NMEA0183 * container_p{ nullptr };

   public:

      inline RESPONSE(std::string_view id) noexcept : Mnemonic(id), DataSource(STRING_VIEW("GP")) {}

      std::string const Mnemonic;

      /*
      ** Data
      */

      std::string DataSource;
      std::string ErrorMessage;
      std::string Talker;

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept = 0;
      virtual bool Parse( SENTENCE const& sentence ) noexcept = 0;
      virtual std::string PlainEnglish( void ) const noexcept;
      virtual void SetErrorMessage( std::string_view message ) noexcept;
      virtual void SetContainer( NMEA0183 * container ) noexcept;
      virtual bool Write( SENTENCE& sentence ) const noexcept;
};

class GENERIC_RESPONSE : public RESPONSE
{
public:

    inline GENERIC_RESPONSE(std::string_view id) noexcept : RESPONSE(id) {}
    void Empty(void) noexcept override {}
    bool Parse(SENTENCE const& ) noexcept override { return(true); }
    bool Write(SENTENCE& ) const noexcept override { return(true); }

};

#endif // RESPONSE_CLASS_HEADER
