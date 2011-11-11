project(WntrMining)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRMINING_MAJOR_VERSION 0)
set(WNTRMINING_MINOR_VERSION 0)
set(WNTRMINING_MICRO_VERSION 1)
set(WNTRMINING_VERSION
    ${WNTRMINING_MAJOR_VERSION}.${WNTRMINING_MINOR_VERSION}${WNTRMINING_MICRO_VERSION})
set(WNTRMINING_UUID "5011b904-72d9-4a6b-a7b3-bf1f6fefb6a0")

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(WntrData 0.01 REQUIRED)
find_package(Qt4 COMPONENTS
    QtCore
    REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB WNTRMINING_SHPP "src/*.hpp")
file(GLOB WNTRMINING_SCPP "src/*.cpp")
QT4_WRAP_CPP(MOC_CODE "${WNTRMINING_SHPP}")

include("${QT_USE_FILE}")

## Main variables
set(WNTRMINING_INCLUDE_DIRS "${WNTRDATA_INCLUDE_DIRS}"
    ${Qt_INCLUDE_DIRS})
set(WNTRMINING_LIBRARIES "${WNTRDATA_LIBRARIES}"
    ${QT_LIBRARIES})
set(WNTRMINING_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrMining" CACHE PATH "CMake directory.")
    
include_directories(${WNTRMINING_INCLUDE_DIRS})

## Targets
add_library(wntrmining SHARED
    ${WNTRMINING_SHPP}
    ${WNTRMINING_SCPP})

set_target_properties(wntrmining PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wntrmining
    ${WNTRMINING_LIBRARIES})

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRMINING_UUID}.spec" @ONLY)

configure_file("cmake/WntrMiningConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrMiningConfig.cmake" @ONLY)

configure_file("cmake/WntrMiningConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrMiningConfigVersion.cmake" @ONLY)

## Installs

install(TARGETS wntrmining
    EXPORT WntrMiningLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/WntrMiningConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrMiningConfigVersion.cmake"
    DESTINATION "${WNTRMINING_CMAKE_DIR}")

install(EXPORT WntrMiningLibraryDepends
    DESTINATION "${WNTRMINING_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRMINING_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
