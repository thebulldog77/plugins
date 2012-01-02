cmake_minimum_required(VERSION 2.8)

file(GLOB WNTRMESSAGING_CPP "*.cpp")
file(GLOB WNTRMESSAGING_HPP "*.hpp")

QT4_WRAP_CPP(WNTRMESSAGING_CPP ${WNTRMESSAGING_HPP})

add_library(wplugin-messaging SHARED ${WNTRMESSAGING_CPP})
set_target_properties(wplugin-messaging
    PROPERTIES
    VERSION ${GENERIC_LIB_VERSION}
    SOVERSION ${GENERIC_LIB_SOVERSION})

target_link_libraries(wplugin-messaging ${WNTRMESSAGING_LIBRARIES})

install(TARGETS wplugin-messaging
    EXPORT WntrMessagingLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(EXPORT WntrMessagingLibraryDepends
    DESTINATION "${WNTRMESSAGING_CMAKE_DIR}")

install(FILES ${WNTRMESSAGING_HEADERS}
    DESTINATION "${WNTRMESSAGING_INCLUDE_DIR}"
    COMPONENT dev)
