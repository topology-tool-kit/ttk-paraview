#------------------------------------------------------------------------------
# Get build directory functional

set(_binary_package_dir "${CMAKE_BINARY_DIR}/${CATALYST_INSTALL_PACKAGE_DIR}")

# These are targets for users of Catalyst
# i.e the simulation codes.
export(
  # TARGETS   core conduit catalyst
  EXPORT    Catalyst
  NAMESPACE catalyst::
  FILE      ${_binary_package_dir}/catalyst-targets.cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${_binary_package_dir}/catalyst-version.cmake"
  VERSION       "${CATALYST_VERSION}"
  COMPATIBILITY SameMajorVersion)

configure_package_config_file(
  "${CMAKE_CURRENT_LIST_DIR}/catalyst-config.cmake.in"
  "${_binary_package_dir}/catalyst-config.cmake"
  INSTALL_DESTINATION "${CATALYST_INSTALL_PACKAGE_DIR}")


configure_file("${CMAKE_CURRENT_LIST_DIR}/catalyst-macros.cmake"
               "${_binary_package_dir}/catalyst-macros.cmake" COPYONLY)
#------------------------------------------------------------------------------
# Get install directory functional

# We only install targes for users of Catalyst i.e. simulation codes
install(
  EXPORT      Catalyst
  NAMESPACE   catalyst::
  FILE        catalyst-targets.cmake
  DESTINATION "${CATALYST_INSTALL_PACKAGE_DIR}")

install(
  FILES       "${_binary_package_dir}/catalyst-version.cmake"
              "${_binary_package_dir}/catalyst-config.cmake"
              "${_binary_package_dir}/catalyst-macros.cmake"
  DESTINATION "${CATALYST_INSTALL_PACKAGE_DIR}")
