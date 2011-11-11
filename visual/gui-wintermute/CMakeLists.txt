project(WntrGui)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(WNTRGUI_MAJOR_VERSION 0)
set(WNTRGUI_MINOR_VERSION 0)
set(WNTRGUI_MICRO_VERSION 1)
set(WNTRGUI_UUID "78345566-cb12-11e0-b159-f51bb9111288")
set(WNTRGUI_VERSION
		${WNTRGUI_MAJOR_VERSION}.${WNTRGUI_MINOR_VERSION}${WNTRGUI_MICRO_VERSION})

list(APPEND CMAKE_MODULE_PATH "cmake/modules")


include(WintermuteDefaults)
include(WintermuteMacros)

find_package(WntrFrontend 0.01 REQUIRED)
find_package(WntrData 0.01 REQUIRED)
find_package(WntrLing 0.01 REQUIRED)
find_package(WntrNtwk 0.01 REQUIRED)
find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 4.4.3 COMPONENTS
		 QtGui
		 QtDBus
		 QtCore
		 REQUIRED)

file(GLOB WNTRGUI_SHPP "src/*.hpp")
file(GLOB WNTRGUI_SCPP "src/*.cpp")
list(APPEND WNTRGUI_SCPP "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/frontend/qrc_res.cxx")
message("${WNTRGUI_SCPP}")
file(GLOB WNTRGUI_UIC "ui/*.ui")
file(GLOB WNTRGUI_QRC "ui/*.qrc")
file(GLOB CMAKE_MODULES "${PROJECT_SOURCE_DIR}/cmake/Modules/*.cmake")

## Qt4
QT4_WRAP_CPP(WNTRGUI_SCPP "${WNTRGUI_SHPP}")
QT4_WRAP_UI(WNTRGUI_SCPP "${WNTRGUI_UIC}")
QT4_ADD_RESOURCES(WNTRGUI_SCPP "${WNTRGUI_QRC}")
include("${QT_USE_FILE}")

## Main variables
set(VS_KEYWORD Qt4VSv1.0)
set(VS_SCC_PROJECTNAME "Wintermute Graphics")
set(WNTRGUI_LIB_DIR "${WINTER_PLUGIN_INSTALL_DIR}")
set(WNTRGUI_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/gui")
set(WNTRGUI_INCLUDE_DIRS "${WINTERMUTE_INCLUDE_DIRS}"
		${WNTRFRONTEND_INCLUDE_DIRS}
		${WNTRLING_INCLUDE_DIRS}
		${WNTRDATA_INCLUDE_DIRS}
		${WNTRNTWK_INCLUDE_DIRS}
		${Qt_INCLUDE_DIRS})
set(WNTRGUI_LIBRARIES ${QT_LIBRARIES} ${WINTERMUTE_LIBRARIES} ${WNTRFRONTEND_LIBRARIES} ${WNTRLING_LIBRARIES} ${WNTRNTWK_LIBRARIES} ${WNTRDATA_LIBRARIES})
set(WNTRGUI_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrGui" CACHE PATH "CMake directory.")


include_directories(${WNTRGUI_INCLUDE_DIRS})

## Targets
add_library(gui-wintermute SHARED ${WNTRGUI_SCPP})

set_target_properties(gui-wintermute PROPERTIES
		VERSION ${GENERIC_LIB_VERSION}
		SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(gui-wintermute ${WNTRGUI_LIBRARIES})

## Configs
configure_file("${PROJECT_SOURCE_DIR}/config.hpp.in"
		"${PROJECT_SOURCE_DIR}/src/config.hpp")

configure_file("cmake/WntrGuiConfig.cmake.in"
		"${PROJECT_BINARY_DIR}/InstallFiles/WntrGuiConfig.cmake" @ONLY)

configure_file("cmake/WntrGuiConfigVersion.cmake.in"
		"${PROJECT_BINARY_DIR}/InstallFiles/WntrGuiConfigVersion.cmake" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
	 "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRGUI_UUID}.spec" @ONLY)

## Installs
install(TARGETS gui-wintermute
		EXPORT WntrGuiLibraryDepends
		LIBRARY DESTINATION "${WNTRGUI_LIB_DIR}"
		RENAME WNTRGUI_UUID)

install(EXPORT WntrGuiLibraryDepends
		DESTINATION "${WNTRGUI_CMAKE_DIR}")

install(FILES
		"${PROJECT_BINARY_DIR}/InstallFiles/WntrGuiConfig.cmake"
		"${PROJECT_BINARY_DIR}/InstallFiles/WntrGuiConfigVersion.cmake"
		DESTINATION "${WNTRGUI_CMAKE_DIR}")

install(FILES ${WNTRGUI_SHPP}
		DESTINATION "${WNTRGUI_INCLUDE_DIR}")

install(FILES ${CMAKE_MODULES}
		DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRGUI_UUID}.spec"
		DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
