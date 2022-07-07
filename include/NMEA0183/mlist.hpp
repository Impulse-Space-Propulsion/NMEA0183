#if ! defined( MANUFACTURER_LIST_CLASS_HEADER )

#define MANUFACTURER_LIST_CLASS_HEADER

class MANUFACTURER_LIST
{
   public:

      inline MANUFACTURER_LIST() noexcept {};

      /*
      ** Data
      */

      std::vector<MANUFACTURER> ManufacturerTable;

      /*
      ** Methods
      */

      virtual void Empty( void ) noexcept;
      virtual void Fill( void ) noexcept;
      virtual std::string const& Find( std::string_view mnemonic ) noexcept;

      /*
      ** Operators
      */

      virtual std::string const& operator [] (std::string_view mnemonic) noexcept;
};

#endif // MANUFACTURER_LIST_CLASS_HEADER
