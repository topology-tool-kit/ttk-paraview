set(headers
  catalyst.h
  catalyst_api.h
  catalyst_stub.h
  ${CMAKE_CURRENT_BINARY_DIR}/catalyst_export.h
  ${CMAKE_CURRENT_BINARY_DIR}/catalyst_version.h)
configure_file(catalyst_version.h.in catalyst_version.h)

#------------------------------------------------------------
# Add an interface library just to setup include dirs.
add_library(core INTERFACE)
target_include_directories(core
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CATALYST_INSTALL_INCLUDE_DIR}>)
add_library(catalyst::core ALIAS core)

c_install_targets(core)
c_install_headers(
  HEADERS ${headers})

#-------------------------------------------------------------
# Generate export header.
# Since we want to use generate_export_header() from CMake,
# we create a dummy library to help us generate the export header
# here.
set(CMAKE_CONFIGURABLE_FILE_CONTENT "#error \"this file should not be compiled!\"")
configure_file("${CMAKE_ROOT}/Modules/CMakeConfigurableFile.in"
               "${CMAKE_CURRENT_BINARY_DIR}/dummy.cxx")
unset(CMAKE_CONFIGURABLE_FILE_CONTENT)
add_library(dummy SHARED EXCLUDE_FROM_ALL ${CMAKE_CURRENT_BINARY_DIR}/dummy.cxx)
set_target_properties(dummy
  PROPERTIES
    DEFINE_SYMBOL catalyst_EXPORTS)
include(GenerateExportHeader)
generate_export_header(dummy BASE_NAME catalyst)
