project(WntrVoiceSuite)
cmake_minimum_required(VERSION 2.8)

find_package(Wintermute 0.01 REQUIRED)
find_package(WntrVoice 0.01 QUIET)

include(WintermuteDefaults)
include(WintermuteMacros)

list(REMOVE_ITEM CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}")

if(NOT WntrVoice-FOUND)
    ## API
    add_subdirectory(wintermute-plugin-voice)
else()
    set(WntrVoice_DIR "${PROJECT_BINARY_DIR}/wintermute-plugin-voice/InstallFiles")
    message("${CMAKE_MODULE_PATH}")
    ## Synthesizers
    add_subdirectory(marytts-wintermute)
    add_subdirectory(speechd-wintermute)

    ## Recognizers
    ## @todo Add support for Julius.
    add_subdirectory(pocketsphinx-wintermute EXCLUDE_FROM_ALL ON)
endif()
