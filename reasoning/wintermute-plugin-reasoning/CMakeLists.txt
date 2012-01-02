project(WntrReasoningApi)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRREASONING_MAJOR_VERSION 0)
set(WNTRREASONING_MINOR_VERSION 1)
set(WNTRREASONING_VERSION "${WNTRREASONING_MAJOR_VERSION}.${WNTRREASONING_MINOR_VERSION}")
set(WNTRREASONING_UUID "fb71babe-1bd9-11e1-a53b-020054746872")

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.1 REQUIRED)
find_package(WntrData 0.1 REQUIRED)
find_package(Qt4 4.7.4 COMPONENTS
    QtCore
    REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)
include("${QT_USE_FILE}")

add_subdirectory(src)


include("${QT_USE_FILE}")

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRREASONING_UUID}.spec" @ONLY)

configure_file("cmake/WntrReasoningConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfig.cmake" @ONLY)

configure_file("cmake/WntrReasoningConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfigVersion.cmake" @ONLY)

## Installs
install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfigVersion.cmake"
    DESTINATION "${WNTRREASONING_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRREASONING_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
