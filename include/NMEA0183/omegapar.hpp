#if ! defined( OMEGA_PAIR_CLASS_HEADER )

#define OMEGA_PAIR_CLASS_HEADER

class OMEGA_PAIR
{
   public:

       inline OMEGA_PAIR() noexcept {};

      /*
      ** Data
      */

      std::string Name;
      int         LaneNumber{ 0 };
      int         CentilaneNumber{ 0 };

      /*
      ** Methods
      */

      void Empty( void ) noexcept;
      void Parse( int field_number, SENTENCE const& sentence ) noexcept;
      void Write( SENTENCE& sentence ) const noexcept;

      /*
      ** Operators
      */

      virtual OMEGA_PAIR const& operator = ( OMEGA_PAIR const& source ) noexcept;
};

#endif // OMEGA_PAIR_CLASS_HEADER
