project(WntrMining-Zeitgeist)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(ZEITGEISTWINTERMUTE_MAJOR_VERSION 0)
set(ZEITGEISTWINTERMUTE_MINOR_VERSION 0)
set(ZEITGEISTWINTERMUTE_MICRO_VERSION 1)
set(ZEITGEISTWINTERMUTE_VERSION
    ${ZEITGEISTWINTERMUTE_MAJOR_VERSION}.${ZEITGEISTWINTERMUTE_MINOR_VERSION}${ZEITGEISTWINTERMUTE_MICRO_VERSION})
set(ZEITGEISTWINTERMUTE_UUID "b706c449-552d-4acb-8f4a-e5897e7251ca")


list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(QZeitgeist REQUIRED)
find_package(Qt4 COMPONENTS
    QtCore
    REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB ZEITGEISTWINTERMUTE_SHPP "src/*.hpp")
file(GLOB ZEITGEISTWINTERMUTE_SCPP "src/*.cpp")
QT4_WRAP_CPP(MOC_CODE "${ZEITGEISTWINTERMUTE_SHPP}")

include("${QT_USE_FILE}")

## Main variables
set(ZEITGEISTWINTERMUTE_INCLUDE_DIRS "${WNTRMINING_INCLUDE_DIRS}"
    ${Qt_INCLUDE_DIRS})
set(ZEITGEISTWINTERMUTE_LIBRARIES "${WNTRMINING_LIBRARIES}"
    ${QT_LIBRARIES})
set(ZEITGEISTWINTERMUTE_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/ZeitgeistWintermute" CACHE PATH "CMake directory.")

include_directories(${ZEITGEISTWINTERMUTE_INCLUDE_DIRS})

## Targets
add_library(wintermute-plugin-mining SHARED
    ${ZEITGEISTWINTERMUTE_SHPP}
    ${ZEITGEISTWINTERMUTE_SCPP})

set_target_properties(wintermute-plugin-mining PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wintermute-plugin-mining
    ${ZEITGEISTWINTERMUTE_LIBRARIES})

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${ZEITGEISTWINTERMUTE_UUID}.spec" @ONLY)

configure_file("cmake/ZeitgeistWintermuteConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/ZeitgeistWintermuteConfig.cmake" @ONLY)

configure_file("cmake/ZeitgeistWintermuteConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/ZeitgeistWintermuteConfigVersion.cmake" @ONLY)

## Installs

install(TARGETS wintermute-plugin-mining
    EXPORT ZeitgeistWintermuteLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/ZeitgeistWintermuteConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/ZeitgeistWintermuteConfigVersion.cmake"
    DESTINATION "${ZEITGEISTWINTERMUTE_CMAKE_DIR}")

install(EXPORT ZeitgeistWintermuteLibraryDepends
    DESTINATION "${ZEITGEISTWINTERMUTE_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${ZEITGEISTWINTERMUTE_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
