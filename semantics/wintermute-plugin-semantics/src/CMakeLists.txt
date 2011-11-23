project(WntrSemanticsLib)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB WNTRSEMANTICS_SOURCES "*.cpp")
file(GLOB WNTRSEMANTICS_HEADERS "*.hpp")
QT4_WRAP_CPP(WNTRSEMANTICS_SOURCES ${WNTRSEMANTICS_HEADERS})
include_directories(${WNTRSEMANTICS_INCLUDE_DIRS})

## Targets

add_library(wntrsemantics SHARED ${WNTRSEMANTICS_SOURCES})

set_target_properties(wntrsemantics PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wntrsemantics ${WNTRSEMANTICS_LIBRARIES})

## Installs
install(TARGETS wntrsemantics
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}"
    COMPONENT bin)

install(FILES ${WNTRSEMANTICS_HEADERS}
    DESTINATION "${WINTER_INCLUDE_INSTALL_DIR}"
    COMPONENT dev)

