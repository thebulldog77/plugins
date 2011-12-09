project(WntrVisual)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRVISUAL_MAJOR_VERSION 0)
set(WNTRVISUAL_MINOR_VERSION 1)
set(WNTRVISUAL_UUID "5f0741d0-026b-11e1-8f4e-5999c633b9c0")
set(WNTRVISUAL_VERSION "${WNTRVISUAL_MAJOR_VERSION}.${WNTRVISUAL_MINOR_VERSION}")

list(APPEND CMAKE_MODULE_PATH "cmake/modules")


include(WintermuteDefaults)
include(WintermuteMacros)

find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 4.4.3 COMPONENTS
		 QtDBus
		 QtCore
		 REQUIRED)

file(GLOB WNTRVISUAL_SHPP "src/*.hpp")
file(GLOB WNTRVISUAL_SCPP "src/*.cpp")
file(GLOB WNTRVISUAL_QRC "ui/*.qrc")
file(GLOB WNTRVISUAL_UI "ui/*.ui")
file(GLOB WNTRVISUAL_UI_FILES "ui/*")
file(GLOB CMAKE_MODULES "${PROJECT_SOURCE_DIR}/cmake/Modules/*.cmake")

## Qt4
QT4_WRAP_CPP(WNTRVISUAL_SCPP "${WNTRVISUAL_SHPP}")
QT4_WRAP_UI(WNTRVISUAL_SCPP "${WNTRVISUAL_UI}")
QT4_ADD_RESOURCES(WNTRVISUAL_SQRC "${WNTRVISUAL_QRC}")
include("${QT_USE_FILE}")

## Main variables
set(VS_KEYWORD Qt4VSv1.0)
set(VS_SCC_PROJECTNAME "Wintermute Visual")
set(WNTRVISUAL_LIB_DIR "${WINTER_PLUGIN_INSTALL_DIR}")
set(WNTRVISUAL_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/visual")
set(WNTRVISUAL_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
                ${WNTRVISUAL_INCLUDE_DIR}
                "${WINTER_PLUGIN_DATA_INSTALL_DIR}/visual"
		${Qt_INCLUDE_DIRS})
set(WNTRVISUAL_LIBRARIES ${QT_LIBRARIES} ${WINTERMUTE_LIBRARIES} ${WNTRVISUAL_LIBRARIES})
set(WNTRVISUAL_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrVisual" CACHE PATH "CMake directory.")

include_directories(${WNTRVISUAL_INCLUDE_DIRS})

## Targets
add_library(wplugin-visual SHARED ${WNTRVISUAL_SCPP} ${WNTRVISUAL_SQRC})

set_target_properties(wplugin-visual PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wplugin-visual ${WNTRVISUAL_LIBRARIES})

## Configs
configure_file("${PROJECT_SOURCE_DIR}/config.hpp.in"
    "${PROJECT_SOURCE_DIR}/src/config.hpp")

configure_file("cmake/WntrVisualConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVisualConfig.cmake" @ONLY)

configure_file("cmake/WntrVisualConfigVersion.cmake.in"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVisualConfigVersion.cmake" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
     "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRVISUAL_UUID}.spec" @ONLY)

## Installs
install(TARGETS wplugin-visual
    EXPORT WntrVisualLibraryDepends
    LIBRARY DESTINATION "${WNTRVISUAL_LIB_DIR}"
    RENAME WNTRVISUAL_UUID)

install(EXPORT WntrVisualLibraryDepends
    DESTINATION "${WNTRVISUAL_CMAKE_DIR}")

install(FILES
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVisualConfig.cmake"
    "${PROJECT_BINARY_DIR}/InstallFiles/WntrVisualConfigVersion.cmake"
    DESTINATION "${WNTRVISUAL_CMAKE_DIR}")

install(FILES ${WNTRVISUAL_SHPP}
    DESTINATION "${WNTRVISUAL_INCLUDE_DIR}")

install(FILES ${CMAKE_MODULES}
    DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRVISUAL_UUID}.spec"
    DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")

install(FILES ${WNTRVISUAL_UI_FILES}
    DESTINATION "${WINTER_PLUGIN_DATA_INSTALL_DIR}/visual")
