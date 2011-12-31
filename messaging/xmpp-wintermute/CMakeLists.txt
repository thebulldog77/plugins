project(XmppWintermute)
cmake_minimum_required(VERSION 2.8)

## Versioning definitions
set(WINTERMUTE_IS_PLUGIN ON)
set(XMPPWNTR_UUID "d5c34c82-10b3-11e1-86ef-2e723e73e86b")
set(XMPPWNTR_MAJOR_VERSION 0)
set(XMPPWNTR_MAJOR_VERSION 0)
set(XMPPWNTR_VERSION
        "${IRC_WINTERMUTE_MAJOR_VERSION}.${IRC_WINTERMUTE_MINOR_VERSION}")
        
list(APPEND CMAKE_MODULE_PATH "cmake/modules")
        
## Packages
find_package(Wintermute 0.01 REQUIRED)
#find_package(WntrMessaging 0.01 REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Qt4 4.6 REQUIRED)
pkg_search_module(QXMPP qxmpp REQUIRED)

include(WintermuteDefaults)
include(WintermuteMacros)

add_subdirectory(src)

## Variables
#set(IRC_WINTERMUTE_
