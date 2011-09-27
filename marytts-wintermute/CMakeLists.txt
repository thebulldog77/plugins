project(MaryTTS_Plugin)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(MARYTTS_PLUGIN_MAJOR_VERSION 0)
set(MARYTTS_PLUGIN_MINOR_VERSION 0)
set(MARYTTS_PLUGIN_MICRO_VERSION 1)
set(MARYTTS_PLUGIN_UUID "4947f2d8-69f6-477a-9069-80c2ad2f8725")
set(MARYTTS_PLUGIN_VERSION
    ${MARYTTS_PLUGIN_MAJOR_VERSION}.${MARYTTS_PLUGIN_MINOR_VERSION}${MARYTTS_PLUGIN_MICRO_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(WntrVoice REQUIRED)
find_package(Qt4 COMPONENTS
    QtCore
    REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB MARYTTS_PLUGIN_SHPP "src/*.hpp")
file(GLOB MARYTTS_PLUGIN_SCPP "src/*.cpp")
QT4_WRAP_CPP(MOC_CODE "${MARYTTS_PLUGIN_SHPP}")

include("${QT_USE_FILE}")
#
# Main variables
#
set(MARYTTS_PLUGIN_INCLUDE_DIRS "${WNTRVOICE_INCLUDE_DIRS}"
    ${Qt_INCLUDE_DIRS})
set(MARYTTS_PLUGIN_LIBRARIES "${WNTRVOICE_LIBRARIES}"
    ${QT_LIBRARIES})

#
#
#
include_directories(${MARYTTS_PLUGIN_INCLUDE_DIRS})

#
# Targets
#
add_library(marytts-plugin SHARED
    ${MARYTTS_PLUGIN_SHPP}
    ${MARYTTS_PLUGIN_SCPP}
    ${MOC_CODE})

set_target_properties(marytts-plugin PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(marytts-plugin
    ${MARYTTS_PLUGIN_LIBRARIES})

## The end-file should be the _same exact_ name as your library file (bug)
configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/marytts-plugin.spec" @ONLY)
#
# Installs
#

install(TARGETS marytts-plugin
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/marytts-plugin.spec"
DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
