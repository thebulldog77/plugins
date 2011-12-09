## This is the top-level CMakeLists.txt file for the project.
## Typically a CMakeLists.txt file accompanies each sub-directory
## (except for build and cmake directories). The following are
## variables that need to be replaced.
##
## *** Delete this when implementing plug-in. ***
## 
## [[PROJECTNAME]] = The name of this project. This isn't
## 	the name of the library or executable but is typically
## 	used by IDEs. There's a format used by APIs and backends.
## 	Backends: wntr-<PLUGIN_ALIAS>
## 	APIS:	  wplugin-<PLUGIN_ALIAS>
##	See [[PLUGIN_ALIAS]] for more information.
##
## [[PLUGIN_UUID]] = The UUID representing this plug-in. You should
## 	generate this once and leave it alone after that.
##
## [[PLUGIN_NICK]] = A short-name used throughout the CMake build
## 	system to present a namespace.


project([[PROJECTNAME]])
cmake_minimum_required(VERSION 2.8)

# Although this doesn't do much now, we leave it in to permit further implementations
# to support simplified CMake builds for plug-ins.
set(WINTERMUTE_IS_PLUGIN ON)
set([[PLUGIN_NICK]]_MAJOR_VERSION 0)
set([[PLUGIN_NICK]]_MINOR_VERSION 1)
set([[PLUGIN_NICK]]_UUID "[[PLUGIN_UUID]]")
set([[PLUGIN_NICK]]_VERSION "${[[PLUGIN_NICK]]_MAJOR_VERSION}.${[[PLUGIN_NICK]]_MINOR_VERSION}")

list(APPEND CMAKE_MODULE_PATH "cmake/modules")

## This imports Wintermute-specific build variables.
include(WintermuteDefaults)
include(WintermuteMacros)

find_package(Wintermute 0.1 REQUIRED)
find_package(Qt4 4.7.4 COMPONENTS
	QtCore
	REQUIRED)

file(GLOB [[PLUGIN_NICK]]_SHPP "src/*.hpp")
file(GLOB [[PLUGIN_NICK]]_SCPP "src/*.cpp")
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
