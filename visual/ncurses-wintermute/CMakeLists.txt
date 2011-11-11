project(NCursesWintermute)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(NCURSESWINTERMUTE_MAJOR_VERSION 0)
set(NCURSESWINTERMUTE_MINOR_VERSION 0)
set(NCURSESWINTERMUTE_MICRO_VERSION 1)
set(NCURSESWINTERMUTE_UUID "910d44d4-028b-11e1-bba1-4dab9016640f")
set(NCURSESWINTERMUTE_VERSION
    ${NCURSESWINTERMUTE_MAJOR_VERSION}.${NCURSESWINTERMUTE_MINOR_VERSION}${NCURSESWINTERMUTE_MICRO_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")


include(WintermuteDefaults)
include(WintermuteMacros)

find_package(WntrFrontend 0.01 REQUIRED)
find_package(Curses REQUIRED)
find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 4.4.3 COMPONENTS
     QtCore
     REQUIRED)

file(GLOB NCURSESWINTERMUTE_SHPP "src/*.hpp")
file(GLOB NCURSESWINTERMUTE_SCPP "src/*.cpp")
file(GLOB CMAKE_MODULES "${PROJECT_SOURCE_DIR}/cmake/Modules/*.cmake")

## Qt4
QT4_WRAP_CPP(NCURSESWINTERMUTE_SCPP "${NCURSESWINTERMUTE_SHPP}")
include("${QT_USE_FILE}")

## Main variables
set(VS_KEYWORD Qt4VSv1.0)
set(VS_SCC_PROJECTNAME "nCurses for Wintermute")
set(NCURSESWINTERMUTE_LIB_DIR "${WINTER_PLUGIN_INSTALL_DIR}")
set(NCURSESWINTERMUTE_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/ncurses")
set(NCURSESWINTERMUTE_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${WNTRFRONTEND_INCLUDE_DIRS}
    ${Qt_INCLUDE_DIRS})
set(NCURSESWINTERMUTE_LIBRARIES ${QT_LIBRARIES} ${WINTERMUTE_LIBRARIES} ${WNTRFRONTEND_LIBRARIES})
set(NCURSESWINTERMUTE_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/NCursesWintermute" CACHE PATH "CMake directory.")


include_directories(${NCURSESWINTERMUTE_INCLUDE_DIRS})

## Targets
add_library(wntrgui SHARED ${NCURSESWINTERMUTE_SCPP})

set_target_properties(ncurses-wintermute PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(ncurses-wintermute ${NCURSESWINTERMUTE_LIBRARIES})

## Configs
configure_file("${PROJECT_SOURCE_DIR}/config.hpp.in"
    "${PROJECT_SOURCE_DIR}/src/config.hpp")

configure_file("cmake/NCursesWintermuteConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/NCursesWintermuteConfig.cmake" @ONLY)

configure_file("cmake/NCursesWintermuteConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/NCursesWintermuteConfigVersion.cmake" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
   "${PROJECT_BINARY_DIR}/InstallFiles/${NCURSESWINTERMUTE_UUID}.spec" @ONLY)

## Installs
install(TARGETS ncurses-wintermute
    EXPORT NCursesWintermuteLibraryDepends
    LIBRARY DESTINATION "${NCURSESWINTERMUTE_LIB_DIR}"
    RENAME NCURSESWINTERMUTE_UUID)

install(EXPORT NCursesWintermuteLibraryDepends
    DESTINATION "${NCURSESWINTERMUTE_CMAKE_DIR}")

install(FILES
    "${PROJECT_BINARY_DIR}/InstallFiles/NCursesWintermuteConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/NCursesWintermuteConfigVersion.cmake"
    DESTINATION "${NCURSESWINTERMUTE_CMAKE_DIR}")

install(FILES ${NCURSESWINTERMUTE_SHPP}
    DESTINATION "${NCURSESWINTERMUTE_INCLUDE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${NCURSESWINTERMUTE_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
