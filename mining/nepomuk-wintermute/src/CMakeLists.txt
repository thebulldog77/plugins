project(WntrMining-Nepomuk:Src)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB NEPOMUKWNTR_SOURCES "*.cpp")
file(GLOB NEPOMUKWNTR_HEADERS "*.hpp")
QT4_WRAP_CPP(NEPOMUKWNTR_SOURCES ${NEPOMUKWNTR_HEADERS})

## Targets
add_library(nepomuk-wintermute SHARED ${NEPOMUKWNTR_SOURCES})
target_link_libraries(nepomuk-wintermute ${NEPOMUKWNTR_LIBRARIES})

## Installs
install(TARGETS nepomuk-wintermute
    EXPORT NEPOMUKWNTRLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(EXPORT NEPOMUKWNTRLibraryDepends
    DESTINATION "${NEPOMUKWNTR_CMAKE_DIR}")

install(FILES ${NEPOMUKWNTR_HEADERS}
    DESTINATION "${NEPOMUKWNTR_INCLUDE_DIR}"
    COMPONENT dev)


