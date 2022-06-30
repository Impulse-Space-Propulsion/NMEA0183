cmake_minimum_required(VERSION 3.13)

project(NMEA0183Lib VERSION 0.1 DESCRIPTION "A Library of GPS standard NMEA 0183 sentences" LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)

include(GNUInstallDirs)

add_library(NMEA0183Lib STATIC)

set_target_properties(NMEA0183Lib 
  PROPERTIES 
  WINDOWS_EXPORT_ALL_SYMBOLS TRUE
  POSITION_INDEPENDENT_CODE TRUE
  )

target_sources(NMEA0183Lib
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/deccalop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/freqmode.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gll.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/long.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/manufact.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/nmea0183.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/p.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ratiopls.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/rmc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sentence.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vtg.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/expid.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gga.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/latlong.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lorantd.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mlist.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/omegapar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/radardat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/response.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/satdat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/talkerid.cpp
  )
 
 if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
   # using Clang
   target_compile_options(NMEA0183Lib PRIVATE -Wall -Werror)
 elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
   # using GCC
   target_compile_options(NMEA0183Lib PRIVATE -Wall -Werror -Wno-stringop-overread)
 elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
   # using Intel C++
 elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
   # using Visual Studio C++
   target_compile_options(NMEA0183Lib PRIVATE /W3)
 else()
   # catchall
   target_compile_options(NMEA0183Lib PRIVATE -Wall -Werror)
 endif()
 
 target_include_directories(NMEA0183Lib 
   PUBLIC
     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
     $<INSTALL_INTERFACE:include>
   PRIVATE src
   )
 
 # 'make install' to the correct locations (provided by GNUInstallDirs).
 install(TARGETS NMEA0183Lib EXPORT NMEA0183LibConfig
     ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
     LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
     RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
 install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})