cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_EXAMPLE_ADAPTOR0)

# When implementing the Catalyst API, as against using
# it to invoke Catalyst, one must use the component
# `SDK` in `find_package` call. This ensures that all necessary
# libraries etc. are available.
find_package(catalyst
  REQUIRED
  COMPONENTS SDK)

add_library(catalyst_example_adaptor0
 catalyst_example_adaptor0.cxx)

# use this function call to mark any library as the
# Catalyst API implementation.
catalyst_library(TARGET catalyst_example_adaptor0)

include(CTest)
if (BUILD_TESTING)
  # Add a test that links against the standard Catalyst library
  # However at runtime ensures the implementation built here
  # is being used.
  set(CMAKE_SKIP_BUILD_RPATH ON)
  add_executable(adaptor0_test
    adaptor0_test.cxx)
  target_link_libraries(adaptor0_test
    PRIVATE
      catalyst::catalyst)
  add_test(
    NAME adaptor0_test
    COMMAND adaptor0_test)

  # set test PATH to ensure our implementation of the Catalyst
  # library is loaded.
  set (pathvar_name)
  if (APPLE)
    set(pathvar_name "DYLD_LIBRARY_PATH")
    set(sep ":")
  elseif(WIN32)
    set(pathvar_name "PATH")
    set(sep "\;")
  elseif (UNIX)
    set(pathvar_name "LD_LIBRARY_PATH")
    set(sep ":")
  endif()
  set_tests_properties(adaptor0_test
    PROPERTIES
      ENVIRONMENT "${pathvar_name}=$<TARGET_FILE_DIR:catalyst_example_adaptor0>${sep}$ENV{${pathvar_name}}")
endif()
