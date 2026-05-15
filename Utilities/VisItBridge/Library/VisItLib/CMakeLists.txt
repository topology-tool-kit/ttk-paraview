#cmake_minimum_required(VERSION 2.6.3)

#FOREACH(policy CMP0012 CMP0013 CMP0014 CMP0017)
#  IF(POLICY ${policy})
#    CMAKE_POLICY(SET ${policy} NEW)
#  ENDIF()
#ENDFOREACH()

project(VisItBridgePlugin)

include(${CMAKE_CURRENT_SOURCE_DIR}/CMake/VisItCommon.cmake)

#-----------------------------------------------------------------------------
# Read the version
#-----------------------------------------------------------------------------
file(STRINGS VERSION VERSION)
if(NOT VERSION)
    message(FATAL_ERROR
        "File \"VERSION\" with ascii string of VisIt version does not exist")
endif()
set(VISIT_VERSION ${VERSION})

# Want to split VISIT_VERSION into major,minor and patch vars.
# Could use SETUP_APP_VERSION, but it sets the vars as CACHE (needed for TP).
# This conflicts with the non-cache var VISIT_VERSION automagically set by
# the call to PROJECT(VISIT).  (Non-cache vars overshadow cache vars).
# There is a 'VERSION' argument to PROJECT, but it only accepts integers, thus
# it bails on things like '3.0.0b'.  So we will parse the visit version here
# instead.
string(REPLACE "." ";" v_list ${VERSION})
list(GET v_list 0 VISIT_VERSION_MAJOR)
list(GET v_list 1 VISIT_VERSION_MINOR)
list(GET v_list 2 VISIT_VERSION_PATCH)
unset(v_list)

#-----------------------------------------------------------------------------
# Create visit-config.h and other configuration.
#-----------------------------------------------------------------------------

if(WIN32)
  add_definitions(-DWIN32)
endif()

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/visit-cmake.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/visit-config.h @ONLY IMMEDIATE)

CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/common/misc/ConfigureInfo.C.in
               ${CMAKE_CURRENT_BINARY_DIR}/common/misc/ConfigureInfo.C @ONLY IMMEDIATE)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/visit-version.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/visit-version.h @ONLY IMMEDIATE)


add_subdirectory(common)
add_subdirectory(visit_vtk)
add_subdirectory(avt)

if (VISIT_PARALLEL)
  set(visit_par_libs
    avtdatabase_par
    avtpipeline_par)
else ()
  set(visit_par_libs
    avtdatabase_ser
    avtpipeline_ser)
endif ()

add_library(VisItLib INTERFACE)
target_link_libraries(VisItLib
  INTERFACE
    visitcommon
    ${visit_par_libs}
    visit_vtk)
target_include_directories(VisItLib
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
add_library(ParaView::VisItLib ALIAS VisItLib)
VISIT_INSTALL_TARGETS(VisItLib)
