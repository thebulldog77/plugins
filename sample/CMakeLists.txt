project(WntrPlugin)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRPLUGIN_MAJOR_VERSION 0)
set(WNTRPLUGIN_MINOR_VERSION 01)
set(WNTRPLUGIN_UUID "00000000-0000-0000-0000-000000000000")
set(WNTRPLUGIN_VERSION
    ${WNTRPLUGIN_MAJOR_VERSION}.${WNTRPLUGIN_MINOR_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 COMPONENTS
    QtCore
    REQUIRED)

include(WinterLibsDependencies) #Need this for plug-in
include(WinterDefaults)
include(WinterMacros)

file(GLOB WNTRPLUGIN_SHPP "include/*.hpp")
file(GLOB WNTRPLUGIN_SCPP "src/*.cpp")
QT4_WRAP_CPP(MOC_CODE "${WNTRPLUGIN_SHPP}")

include("${QT_USE_FILE}")
#
# Main variables
#
set(WNTRPLUGIN_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${Qt_INCLUDE_DIRS})
set(WNTRPLUGIN_LIBRARIES "${WINTERMUTE_LIBRARIES}"
    ${QT_LIBRARIES})

#
#
#
include_directories(${WNTRPLUGIN_INCLUDE_DIRS}
    "${PROJECT_SOURCE_DIR}/include")

#
# Targets
#
add_library(wntrplugin SHARED
    ${WNTRPLUGIN_SHPP}
    ${WNTRPLUGIN_SCPP}
    ${MOC_CODE})

set_target_properties(wntrplugin PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wntrplugin
    ${WNTRPLUGIN_LIBRARIES})

## The end-file should be the _same exact_ name as your library file (bug)
configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/wntrplugin.spec" @ONLY)
#
# Installs
#

install(TARGETS wntrplugin
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/wntrplugin.spec"
DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
