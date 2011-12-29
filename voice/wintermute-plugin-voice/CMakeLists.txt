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
find_package(Qt4 REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

## Variables
set(WNTRVOICE_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/voice")
set(WNTRVOICE_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${WNTRVOICE_INCLUDE_DIR}
    ${Qt_INCLUDE_DIRS})
set(WNTRVOICE_LIBRARIES ${QT_LIBRARIES} ${WINTERMUTE_LIBRARIES})
set(WNTRVOICE_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrVoice" CACHE PATH "CMake directory.")

include("${QT_USE_FILE}")
add_subdirectory(src)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRVOICE_UUID}.spec" @ONLY)

configure_file("cmake/WntrVoiceConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfig.cmake" @ONLY)

configure_file("cmake/WntrVoiceConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfigVersion.cmake" @ONLY)
    
## Installs
install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVoiceConfigVersion.cmake"
    DESTINATION "${WNTRVOICE_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRVOICE_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
