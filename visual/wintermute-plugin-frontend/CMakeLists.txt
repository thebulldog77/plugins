project(WntrFrontend)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRFRONTEND_MAJOR_VERSION 0)
set(WNTRFRONTEND_MINOR_VERSION 0)
set(WNTRFRONTEND_MICRO_VERSION 1)
set(WNTRFRONTEND_UUID "5f0741d0-026b-11e1-8f4e-5999c633b9c0")
set(WNTRFRONTEND_VERSION
    ${WNTRFRONTEND_MAJOR_VERSION}.${WNTRFRONTEND_MINOR_VERSION}${WNTRFRONTEND_MICRO_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")


include(WintermuteDefaults)
include(WintermuteMacros)

find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 4.4.3 COMPONENTS
     QtDBus
     QtCore
     REQUIRED)

file(GLOB WNTRFRONTEND_SHPP "src/*.hpp")
file(GLOB WNTRFRONTEND_SCPP "src/*.cpp")
file(GLOB WNTRFRONTEND_QRC "ui/*.qrc")
file(GLOB CMAKE_MODULES "${PROJECT_SOURCE_DIR}/cmake/Modules/*.cmake")

## Qt4
QT4_WRAP_CPP(WNTRFRONTEND_SCPP "${WNTRFRONTEND_SHPP}")
QT4_ADD_RESOURCES(WNTRFRONTEND_SQRC "${WNTRFRONTEND_QRC}")
include("${QT_USE_FILE}")

## Main variables
set(VS_KEYWORD Qt4VSv1.0)
set(VS_SCC_PROJECTNAME "Wintermute Frontend")
set(WNTRFRONTEND_LIB_DIR "${WINTER_PLUGIN_INSTALL_DIR}")
set(WNTRFRONTEND_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/frontend")
set(WNTRFRONTEND_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${WNTRFRONTEND_INCLUDE_DIRS}
    ${Qt_INCLUDE_DIRS})
set(WNTRFRONTEND_LIBRARIES ${QT_LIBRARIES} ${WINTERMUTE_LIBRARIES} ${WNTRFRONTEND_LIBRARIES})
set(WNTRFRONTEND_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrFrontend" CACHE PATH "CMake directory.")


include_directories(${WNTRFRONTEND_INCLUDE_DIRS})

## Targets
add_library(wntrfrontend SHARED ${WNTRFRONTEND_SCPP} ${WNTRFRONTEND_SQRC})

set_target_properties(wntrfrontend PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wntrfrontend ${WNTRFRONTEND_LIBRARIES})

## Configs
configure_file("${PROJECT_SOURCE_DIR}/config.hpp.in"
    "${PROJECT_SOURCE_DIR}/src/config.hpp")

configure_file("cmake/WntrFrontendConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrFrontendConfig.cmake" @ONLY)

configure_file("cmake/WntrFrontendConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrFrontendConfigVersion.cmake" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
   "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRFRONTEND_UUID}.spec" @ONLY)

## Installs
install(TARGETS wntrfrontend
    EXPORT WntrFrontendLibraryDepends
    LIBRARY DESTINATION "${WNTRFRONTEND_LIB_DIR}"
    RENAME WNTRFRONTEND_UUID)

install(EXPORT WntrFrontendLibraryDepends
    DESTINATION "${WNTRFRONTEND_CMAKE_DIR}")

install(FILES
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrFrontendConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrFrontendConfigVersion.cmake"
    DESTINATION "${WNTRFRONTEND_CMAKE_DIR}")

install(FILES ${WNTRFRONTEND_SHPP} ${WNTRFRONTEND_SQRC}
    DESTINATION "${WNTRFRONTEND_INCLUDE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRFRONTEND_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
