project(WntrReasoning)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRREASONING_MAJOR_VERSION 0)
set(WNTRREASONING_MINOR_VERSION 0)
set(WNTRREASONING_MICRO_VERSION 1)
set(WNTRREASONING_VERSION
    ${WNTRREASONING_MAJOR_VERSION}.${WNTRREASONING_MINOR_VERSION}${WNTRREASONING_MICRO_VERSION})
set(WNTRREASONING_UUID "fb71babe-1bd9-11e1-a53b-020054746872")

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(WntrData 0.01 REQUIRED)
find_package(Qt4 COMPONENTS
    QtCore
    REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB WNTRREASONING_SHPP "src/*.hpp")
file(GLOB WNTRREASONING_SCPP "src/*.cpp")
QT4_WRAP_CPP(MOC_CODE "${WNTRREASONING_SHPP}")

include("${QT_USE_FILE}")

## Main variables
set(WNTRREASONING_INCLUDE_DIRS "${WNTRDATA_INCLUDE_DIRS}"
    ${Qt_INCLUDE_DIRS})
set(WNTRREASONING_LIBRARIES "${WNTRDATA_LIBRARIES}"
    ${QT_LIBRARIES})
set(WNTRREASONING_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrReasoning" CACHE PATH "CMake directory.")
    
include_directories(${WNTRREASONING_INCLUDE_DIRS})

## Targets
add_library(wintermute-plugin-mining SHARED
    ${WNTRREASONING_SHPP}
    ${WNTRREASONING_SCPP})

set_target_properties(wintermute-plugin-mining PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wintermute-plugin-mining
    ${WNTRREASONING_LIBRARIES})

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRREASONING_UUID}.spec" @ONLY)

configure_file("cmake/WntrReasoningConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfig.cmake" @ONLY)

configure_file("cmake/WntrReasoningConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfigVersion.cmake" @ONLY)

## Installs

install(TARGETS wintermute-plugin-mining
    EXPORT WntrReasoningLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrReasoningConfigVersion.cmake"
    DESTINATION "${WNTRREASONING_CMAKE_DIR}")

install(EXPORT WntrReasoningLibraryDepends
    DESTINATION "${WNTRREASONING_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRREASONING_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
