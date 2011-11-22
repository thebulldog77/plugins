project(WntrVoiceLib)
cmake_minimum_required(VERSION 2.8)

## Targets
include_directories(${WNTRVOICE_INCLUDE_DIRS})
file(GLOB WNTRVOICE_SHPP "*.hpp")
file(GLOB WNTRVOICE_SCPP "*.cpp")
file(GLOB CMAKE_MODULES "${PROJECT_SOURCE_DIR}/cmake/Modules/*.cmake")
QT4_WRAP_CPP(WNTRVOICE_SCPP "${WNTRVOICE_SHPP}")

add_library(wintermute-plugin-voice SHARED ${WNTRVOICE_SCPP})

set_target_properties(wintermute-plugin-voice PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wintermute-plugin-voice ${WNTRVOICE_LIBRARIES})

install(TARGETS wintermute-plugin-voice
    EXPORT WntrVoiceLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}"
    RENAME WNTRVOICE_UUID)

install(EXPORT WntrVoiceLibraryDepends
    DESTINATION "${WNTRVOICE_CMAKE_DIR}")

install(FILES ${WNTRVOICE_SHPP}
    DESTINATION "${WNTRVOICE_INCLUDE_DIR}")
