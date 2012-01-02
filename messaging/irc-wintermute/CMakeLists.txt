project(WntrMessaging-IRC)
cmake_minimum_required(VERSION 2.8)

find_package(Wintermute 0.1 REQUIRED)
find_package(Qt4 4.7 COMPONENTS
    QtCore
    QtXml
    REQUIRED)
find_library(IRCLIB ircclient)
#find_package(WntrMessaging 0.1 REQUIRED)

include("${QT_USE_FILE}")
include(WintermuteDefaults)
include(WintermuteMacros)

set(IRCWNTR_UUID "afa601c8-33f1-11e1-b64b-020054746872")
set(IRCWNTR_VERSION_MAJOR 0)
set(IRCWNTR_VERSION_MINOR 1)
set(IRCWNTR_VERSION "${IRCWNTR_VERSION_MAJOR}.${IRCWNTR_VERSION_MINOR}")
set(IRCWNTR_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/irc-wintermute")
set(IRCWNTR_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${Boost_INCLUDE_DIRS}
    ${IRCWNTR_INCLUDE_DIR}
    ${QT_INCLUDE_DIRS})

set(IRCWNTR_LIBRARIES
    ${WINTERMUTE_LIBRARIES}
    ${QT_LIBRARIES})

set(IRCWNTR_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/irc-wintermute" CACHE PATH "CMake directory.")
add_subdirectory(src)
