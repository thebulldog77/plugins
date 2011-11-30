project(PocketSphinx-Wintermute)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(POCKETSPHINX_PLUGIN_MAJOR_VERSION 0)
set(POCKETSPHINX_PLUGIN_MINOR_VERSION 0)
set(POCKETSPHINX_PLUGIN_MICRO_VERSION 1)
set(POCKETSPHINX_PLUGIN_UUID "d4e44182-c94f-4b33-868a-432a8026d908")
set(POCKETSPHINX_PLUGIN_VERSION
    ${POCKETSPHINX_PLUGIN_MAJOR_VERSION}.${POCKETSPHINX_PLUGIN_MINOR_VERSION}${POCKETSPHINX_PLUGIN_MICRO_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(WntrVoice 0.01 REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Qt4 COMPONENTS
    QtCore
    REQUIRED)

pkg_search_module(SPHINX REQUIRED pocketsphinx)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB POCKETSPHINX_PLUGIN_SHPP "src/*.hpp")
file(GLOB POCKETSPHINX_PLUGIN_SCPP "src/*.cpp")
QT4_WRAP_CPP(POCKETSPHINX_PLUGIN_SCPP "${POCKETSPHINX_PLUGIN_SHPP}")

include("${QT_USE_FILE}")

## Variables
set(POCKETSPHINX_PLUGIN_INCLUDE_DIRS "${PocketSphinxPlugin_INCLUDE_DIRS}"
    ${SPHINX_INCLUDE_DIRS}
    ${WNTRVOICE_INCLUDE_DIRS}
    ${Qt_INCLUDE_DIRS})
set(POCKETSPHINX_PLUGIN_LIBRARIES "${PocketSphinxPlugin_LIBRARIES}"
    ${SPHINX_LIBRARIES}
    ${WNTRVOICE_LIBRARIES}
    ${QT_LIBRARIES})
set(POCKETSPHINX_PLUGIN_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/pocketsphinx-wintermute")

include_directories(${POCKETSPHINX_PLUGIN_INCLUDE_DIRS})

#
# Targets
#
add_library(pocketsphinx-wintermute SHARED
    ${POCKETSPHINX_PLUGIN_SHPP}
    ${POCKETSPHINX_PLUGIN_SCPP})

set_target_properties(pocketsphinx-wintermute PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(pocketsphinx-wintermute
    ${POCKETSPHINX_PLUGIN_LIBRARIES})

configure_file("${PROJECT_SOURCE_DIR}/config.hpp.in"
    "${PROJECT_SOURCE_DIR}/src/config.hpp" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${POCKETSPHINX_PLUGIN_UUID}.spec" @ONLY)

configure_file("cmake/PocketSphinxPluginConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/PocketSphinxPluginConfig.cmake" @ONLY)

configure_file("cmake/PocketSphinxPluginConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/PocketSphinxPluginConfigVersion.cmake" @ONLY)

## Installs

install(TARGETS pocketsphinx-wintermute
    EXPORT PocketSphinxPluginLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/PocketSphinxPluginConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/PocketSphinxPluginConfigVersion.cmake"
    DESTINATION "${POCKETSPHINX_PLUGIN_CMAKE_DIR}")

install(EXPORT PocketSphinxPluginLibraryDepends
    DESTINATION "${POCKETSPHINX_PLUGIN_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${POCKETSPHINX_PLUGIN_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
