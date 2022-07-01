#if ! defined( MANUFACTURER_CLASS_HEADER )

#define MANUFACTURER_CLASS_HEADER

class MANUFACTURER
{
   public:

      inline MANUFACTURER() noexcept {};
      MANUFACTURER( std::string_view mnemonic, std::string_view company_name );

      std::string Mnemonic;
      std::string CompanyName;
};

#endif // MANUFACTURER_CLASS_HEADER
