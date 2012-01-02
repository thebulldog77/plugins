cmake_minimum_required(VERSION 2.8)

file(GLOB WNTRREASONING_SHPP "*.hpp")
file(GLOB WNTRREASONING_SCPP "*.cpp")
QT4_WRAP_CPP(MOC_CODE "${WNTRREASONING_SHPP}")
 
## Main variables
set(WNTRREASONING_INCLUDE_DIRS "${WNTRDATA_INCLUDE_DIRS}"
    ${WINTERMUTE_INCLUDE_DIRS}
    ${QT_INCLUDE_DIR})
set(WNTRREASONING_LIBRARIES "${WNTRDATA_LIBRARIES}"
    ${WINTERMUTE_LIBRARIES}
    ${QT_LIBRARIES})
set(WNTRREASONING_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrReasoning" CACHE PATH "CMake directory.")

include_directories(${WNTRREASONING_INCLUDE_DIRS})

## Targets
add_library(wplugin-reasoning SHARED
    ${WNTRREASONING_SHPP}
    ${WNTRREASONING_SCPP})

set_target_properties(wplugin-reasoning PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wplugin-reasoning
    ${WNTRREASONING_LIBRARIES})

## Installs
install(TARGETS wplugin-reasoning
    EXPORT WntrReasoningLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(EXPORT WntrReasoningLibraryDepends
    DESTINATION "${WNTRREASONING_CMAKE_DIR}")
