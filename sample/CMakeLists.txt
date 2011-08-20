project(WntrPlugin)
cmake_minimum_required(VERSION 2.8)

set(WNTRPLUGIN_MAJOR_VERSION 0)
set(WNTRPLUGIN_MINOR_VERSION 01)
set(WNTRPLUGIN_VERSION
    ${WNTRPLUGIN_MAJOR_VERSION}.${WNTRPLUGIN_MINOR_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")


find_package(Wintermute 0.01 REQUIRED)
find_package(Qt 4.4.3 COMPONENTS
    QtCore
    REQUIRED)

include(WinterDefaults)
include(WinterLibsDependencies)
include(WinterMacros)

file(GLOB WNTRPLUGIN_SHPP "include/*.hpp")
file(GLOB WNTRPLUGIN_SCPP "src/*.cpp")
QT4_WRAP_CPP(WNTRPLUGIN_SHPP "${WNTRPLUGIN_SCPP}")

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
    ${WNTRPLUGIN_SCPP})

set_target_properties(wntrplugin PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wntrplugin
    ${WNTRPLUGIN_LIBRARIES})

#
# Installs
#

install(TARGETS wntrplugin
    LIBRARY DESTINATION "${WINTER_LIB_INSTALL_DIR}/wntr")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")
