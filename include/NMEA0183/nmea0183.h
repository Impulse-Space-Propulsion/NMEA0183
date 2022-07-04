#if ! defined( NMEA_0183_HEADER )

#define NMEA_0183_HEADER

/*
** Now include the math stuff for some calculations in the COORDINATE class
*/

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <charconv>
#include <math.h>
#include <time.h>
#include <inttypes.h>

#define STRING_VIEW(_x)  std::string_view(  _x, std::size(_x) - 1)

/*
** Turn off the warning about precompiled headers, it is rather annoying
*/

#if ! defined( CARRIAGE_RETURN )
#define CARRIAGE_RETURN (0x0D)
#endif

#if ! defined( LINE_FEED )
#define LINE_FEED       (0x0A)
#endif

enum class NMEA0183_BOOLEAN
{
   NMEA_Unknown = 0,
   True,
   False
};

enum class LEFTRIGHT
{
   LR_Unknown = 0,
   Left,
   Right
};

enum class EASTWEST
{
   EW_Unknown = 0,
   East,
   West
};

enum class NORTHSOUTH
{
   NS_Unknown = 0,
   North,
   South
};

enum class REFERENCE
{
   ReferenceUnknown = 0,
   BottomTrackingLog,
   ManuallyEntered,
   WaterReferenced,
   RadarTrackingOfFixedTarget,
   PositioningSystemGroundReference
};

enum class COMMUNICATIONS_MODE
{
   CommunicationsModeUnknown         = 0,
   F3E_G3E_SimplexTelephone          = 'd',
   F3E_G3E_DuplexTelephone           = 'e',
   J3E_Telephone                     = 'm',
   H3E_Telephone                     = 'o',
   F1B_J2B_FEC_NBDP_TelexTeleprinter = 'q',
   F1B_J2B_ARQ_NBDP_TelexTeleprinter = 's',
   F1B_J2B_ReceiveOnlyTeleprinterDSC = 'w',
   A1A_MorseTapeRecorder             = 'x',
   A1A_MorseKeyHeadset               = '{',
   F1C_F2C_F3C_FaxMachine            = '|'
};

enum class TRANSDUCER_TYPE
{
   TransducerUnknown   = 0,
   AngularDisplacementTransducer = 'A',
   TemperatureTransducer         = 'C',
   LinearDisplacementTransducer  = 'D',
   FrequencyTransducer           = 'F',
   HumidityTransducer            = 'H',
   ForceTransducer               = 'N',
   PressureTransducer            = 'P',
   FlowRateTransducer            = 'R',
   TachometerTransducer          = 'T',
   VolumeTransducer              = 'V'
};

enum class FAA_MODE
{
    ModeUnknown = 0,
    Autonomous = 'A',
    Differential = 'D',
    Estimated = 'E',
    NotValid = 'N',
    Simulated = 'S',
    Manual = 'M'
};

/*
** Misc Function Prototypes
*/

inline uint32_t HexValue(std::string_view hex_string) noexcept
{
    uint32_t return_value = 0;

    (void)std::from_chars(&hex_string[0], &hex_string[0] + hex_string.length(), return_value, 16);

    return(return_value);
}

std::string expand_talker_id( std::string_view talker ) noexcept;
std::string Hex( uint32_t const value ) noexcept;
std::string talker_id( std::string_view sentence ) noexcept;
time_t ctime( int const year, int const month, int const day, int const hour, int const minute, int const second) noexcept;

#include "NMEA0183/nmea0183.hpp"

#endif // NMEA0183_HEADER
