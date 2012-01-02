project(WntrMessagingApi)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)

find_package(Wintermute 0.1 REQUIRED)
find_package(Qt4 4.7 COMPONENTS
    QtXml
    QtCore
    REQUIRED)
find_library(IRCLIB ircclient)

include(WintermuteDefaults)
include(WintermuteMacros)
include("${QT_USE_FILE}")


set(WNTRMESSAGING_UUID "1e473ae4-3400-11e1-b7dd-020054746872")
set(WNTRMESSAGING_VERSION_MINOR 0)
set(WNTRMESSAGING_VERSION_MAJOR 1)
set(WNTRMESSAGING_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/WntrMessaging")
set(WNTRMESSAGING_VERSION "${WNTRMESSAGING_VERSION_MAJOR}.${WNTRMESSAGING_VERSION_MINOR}")
set(WNTRMESSAGING_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/messaging")
set(WNTRMESSAGING_INCLUDE_DIRS "${QT_INCLUDE_DIR}"
    ${WINTERMUTE_INCLUDE_DIRS}
    ${WNTRMESSAGING_INCLUDE_DIR}
    "${CMAKE_INSTALL_PREFIX}/include/${IRCLIB}")
set(WNTRMESSAGING_LIBRARIES "${QT_LIBRARIES}"
    ${WINTERMUTE_LIBRARIES}
    ${IRCLIB})

include_directories(${WNTRMESSAGING_INCLUDE_DIRS})
add_subdirectory(src)

configure_file("${PROJECT_SOURCE_DIR}/cmake/WntrMessagingConfig.cmake.in"
                "${PROJECT_BINARY_DIR}/InstallFiles/WntrMessagingConfig.cmake" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/cmake/WntrMessagingConfigVersion.cmake.in"
                "${PROJECT_BINARY_DIR}/InstallFiles/WntrMessagingConfigVersion.cmake" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/config.hpp.in"
                "${PROJECT_SOURCE_DIR}/src/config.hpp" @ONLY)

configure_file("${PROJECT_SOURCE_DIR}/spec.in"
                "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRMESSAGING_UUID}.spec" @ONLY)

#dbus_add_activation_service(org.thesii.Wintermute.Messaging.service.in)

## Installs
install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/WntrMessagingConfig.cmake"
              "${PROJECT_BINARY_DIR}/InstallFiles/WntrMessagingConfigVersion.cmake"
        DESTINATION "${WNTRMESSAGING_CMAKE_DIR}")

install(FILES ${CMAKE_MODULES}
        DESTINATION "${CMAKE_MODULE_DIR}")

install(FILES "${PROJECT_BINARY_DIR}/InstallFiles/${WNTRMESSAGING_UUID}.spec"
        DESTINATION "${WINTER_PLUGINSPEC_INSTALL_DIR}")
