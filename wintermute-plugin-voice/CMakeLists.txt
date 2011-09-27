project(WntrVoice)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRVOICE_MAJOR_VERSION 0)
set(WNTRVOICE_MINOR_VERSION 0)
set(WNTRVOICE_MICRO_VERSION 1)
set(WNTRVOICE_UUID "0811f9f2-ba0a-4f04-9965-00a05629c11e")
set(WNTRVOICE_VERSION
    "${WNTRVOICE_MAJOR_VERSION}.${WNTRVOICE_MINOR_VERSION}${WNTRVOICE_MICRO_VERSION}")

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 COMPONENTS
    QtCore
    Phonon
    REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB WNTRVOICE_SHPP "src/*.hpp")
file(GLOB WNTRVOICE_SCPP "src/*.cpp")
file(GLOB CMAKE_MODULES "${PROJECT_SOURCE_DIR}/cmake/Modules/*.cmake")
QT4_WRAP_CPP(MOC_CODE "${WNTRVOICE_SHPP}")

include("${QT_USE_FILE}")
#
# Main variables
#
set(WNTRVOICE_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/wntrvoice")
set(WNTRVOICE_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${WNTRVOICE_INCLUDE_DIR}
    ${Qt_INCLUDE_DIRS})
set(WNTRVOICE_LIBRARIES ${QT_LIBRARIES})
set(WNTRVOICE_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrVoice" CACHE PATH "CMake directory.")

#
#
#
include_directories(${WNTRVOICE_INCLUDE_DIRS})

#
# Targets
#
add_library(wntrvoice SHARED
    ${WNTRVOICE_SHPP}
    ${WNTRVOICE_SCPP}
    ${MOC_CODE})

set_target_properties(wntrvoice PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wntrvoice
    ${WNTRVOICE_LIBRARIES})

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/wntrvoice.spec" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/wntrvoice.pc.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/wntrvoice.pc" @ONLY)

configure_file("cmake/WntrVoiceConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfig.cmake" @ONLY)

configure_file("cmake/WntrVoiceConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfigVersion.cmake" @ONLY)
#
# Installs
#

install(TARGETS wntrvoice
    EXPORT WntrVoiceLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}"
    RENAME WNTRVOICE_UUID)

install(EXPORT WntrVoiceLibraryDepends
    DESTINATION "${WNTRVOICE_CMAKE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/wntrvoice.pc"
    DESTINATION "${WINTER_LIB_INSTALL_DIR}/pkgconfig/")

install(FILES
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfigVersion.cmake"
    DESTINATION "${WNTRVOICE_CMAKE_DIR}")

install(FILES ${WNTRVOICE_SHPP}
    DESTINATION "${WNTRVOICE_INCLUDE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/wntrvoice.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
