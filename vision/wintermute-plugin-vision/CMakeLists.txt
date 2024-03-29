project(WntrVision)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRVISION_MAJOR_VERSION 0)
set(WNTRVISION_MINOR_VERSION 0)
set(WNTRVISION_MICRO_VERSION 1)
set(WNTRVISION_UUID "bc2cd1e8-1d04-42e4-a765-acb6858b4459")
set(WNTRVISION_VERSION
    ${WNTRVISION_MAJOR_VERSION}.${WNTRVISION_MINOR_VERSION}${WNTRVISION_MICRO_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 COMPONENTS
	QtCore REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB WNTRVISION_SHPP "src/*.hpp")
file(GLOB WNTRVISION_SCPP "src/*.cpp")
QT4_WRAP_CPP(WNTRVISION_SCPP "${WNTRVISION_SHPP}")

include("${QT_USE_FILE}")
## Main variables
set(WNTRVISION_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${Qt_INCLUDE_DIRS})
set(WNTRVISION_LIBRARIES "${WINTERMUTE_LIBRARIES}"
    ${QT_LIBRARIES})

#
include_directories(${WNTRVISION_INCLUDE_DIRS})

## Targets
add_library(wintermute-plugin-vision SHARED
    ${WNTRVISION_SHPP}
    ${WNTRVISION_SCPP})

set_target_properties(wintermute-plugin-vision PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wintermute-plugin-vision
    ${WNTRVISION_LIBRARIES})

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRVISION_UUID}.spec" @ONLY)

## Installs
install(TARGETS wintermute-plugin-vision
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRVISION_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
