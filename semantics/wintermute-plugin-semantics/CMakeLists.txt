project(WntrSemanticsProject)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRSEMANTICS_MAJOR_VERSION 0)
set(WNTRSEMANTICS_MINOR_VERSION 0)
set(WNTRSEMANTICS_MICRO_VERSION 1)
set(WNTRSEMANTICS_UUID "c990985e-0f12-11e1-9857-020054746872")
set(WNTRSEMANTICS_VERSION
    "${WNTRSEMANTICS_MAJOR_VERSION}.${WNTRSEMANTICS_MINOR_VERSION}${WNTRSEMANTICS_MICRO_VERSION}")

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

## Variables
set(WNTRSEMANTICS_LIB_DIR "${WINTER_PLUGIN_INSTALL_DIR}")
set(WNTRSEMANTICS_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/semantics")
set(WNTRSEMANTICS_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
    ${WNTRSEMANTICS_INCLUDE_DIR}
    ${Qt_INCLUDE_DIRS})
set(WNTRSEMANTICS_LIBRARIES ${QT_LIBRARIES} ${WINTERMUTE_LIBRARIES})
set(WNTRSEMANTICS_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrSemantics" CACHE PATH "CMake directory.")

include("${QT_USE_FILE}")
add_subdirectory(src)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRSEMANTICS_UUID}.spec" @ONLY)

configure_file("cmake/WntrSemanticsConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrSemanticsConfig.cmake" @ONLY)

configure_file("cmake/WntrSemanticsConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrSemanticsConfigVersion.cmake" @ONLY)

## Installs
install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/WntrSemanticsConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrSemanticsConfigVersion.cmake"
    DESTINATION "${WNTRSEMANTICS_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRSEMANTICS_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
