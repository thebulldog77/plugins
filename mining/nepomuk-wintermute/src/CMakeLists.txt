project(NepomukWintermuteSrc)

include(WintermuteDefaults)
include(WintermuteMacros)

file(GLOB NEPOMUKWINTERMUTE_SOURCES "*.cpp")
file(GLOB NEPOMUKWINTERMUTE_HEADERS "*.hpp")
QT4_WRAP_CPP(NEPOMUKWINTERMUTE_SOURCES ${NEPOMUKWINTERMUTE_HEADERS})

## Targets
add_library(nepomuk-wintermute SHARED ${NEPOMUKWINTERMUTE_SOURCES})
target_link_libraries(nepomuk-wintermute ${NEPOMUKWINTERMUTE_LIBRARIES})

## Installs
install(TARGETS nepomuk-wintermute
    EXPORT NepomukWintermuteLibraryDepends
    LIBRARY DESTINATION "${WINTER_PLUGIN_INSTALL_DIR}")

install(EXPORT NepomukWintermuteLibraryDepends
    DESTINATION "${NEPOMUKWINTERMUTE_CMAKE_DIR}")

install(FILES ${NEPOMUKWINTERMUTE_HEADERS}
    DESTINATION "${NEPOMUKWINTERMUTE_INCLUDE_DIR}"
    COMPONENT dev)


