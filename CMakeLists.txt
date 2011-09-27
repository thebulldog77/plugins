project(WntrPlugins)
cmake_minimum_required(VERSION 2.8)

find_package(WntrVoice QUIET)

if (WntrVoice_FOUND)
	add_subdirectory(pocketsphinx-wintermute)
	add_subdirectory(marytts-wintermute)
endif(WntrVoice_FOUND)

add_subdirectory(wintermute-plugin-voice)
