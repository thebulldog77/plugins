project(IRC-Wintermute)
cmake_minimum_required(VERSION 2.8)

## Versioning definitions
set(WINTERMUTE_IS_PLUGIN ON)
set(IRC_WINTERMUTE_UUID "d5c34c82-10b3-11e1-86ef-2e723e73e86b")
set(IRC_WINTERMUTE_MAJOR_VERSION 0)
set(IRC_WINTERMUTE_MAJOR_VERSION 0)
set(IRC_WINTERMUTE_MICRO_VERSION 1)
set(IRC_WINTERMUTE_VERSION 
        "${IRC_WINTERMUTE_MAJOR_VERSION}.${IRC_WINTERMUTE_MINOR_VERSION}${IRC_WINTERMUTE_MICRO_VERSION}")
        
list(APPEND CMAKE_MODULE_PATH "cmake/modules")
        
## Packages
find_package(Wintermute 0.01 REQUIRED)
find_package(WntrMessaging 0.01 REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Qt4 4.6 REQUIRED)
pkg_search_module(QXMPP qxmpp REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

## Variables
set(IRC_WINTERMUTE_
