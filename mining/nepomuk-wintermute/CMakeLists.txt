project(WntrMining-Nepomuk)
cmake_minimum_required(VERSION 2.8)

set(WINTERMUTE_IS_PLUGIN ON)
set(NEPOMUKWINTERMUTE_UUID "334493dd-d224-42b8-b274-076e0197822b")

find_package(Wintermute 0.01 REQUIRED)
find_package(Qt4 4.7.4 COMPONENTS
    QtCore
    REQUIRED)
#find_package(WntrMining 0.01 REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)
include("${QT_USE_FILE}")

set(NEPOMUKWNTR_INCLUDE_DIR "${WINTER_PLUGIN_INCLUDE_INSTALL_DIR}/nepomuk-wintermute")
set(NEPOMUKWNTR_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/share/cmake/NepomukWintermute")
set(NEPOMUKWNTR_LIBRARIES "${QT_LIBRARIES}"
        ${WNTRMINING_LIBRARIES}
        ${WINTERMUTE_LIBRARIES})
add_subdirectory(src)
