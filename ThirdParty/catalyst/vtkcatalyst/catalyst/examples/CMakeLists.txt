cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(CATALYST_EXAMPLES)

if (CATALYST_BINARY_DIR)

  #------------------------------------------------------------------
  # add a test to do installation of catalyst
  set(install_prefix "${CMAKE_CURRENT_BINARY_DIR}/root")
  add_test(
    NAME  "install-prepare"
    COMMAND "${CMAKE_COMMAND}" -E rm -rf "${install_prefix}")
  add_test(
    NAME  "install"
    COMMAND "${CMAKE_COMMAND}"
            --build ${CATALYST_BINARY_DIR}
            --target "install"
            --config $<CONFIGURATION>
    WORKING_DIRECTORY ${CATALYST_BINARY_DIR})
  set_tests_properties("install"
    PROPERTIES
      ENVIRONMENT "DESTDIR=${install_prefix}")
  set_tests_properties("install-prepare"
    PROPERTIES
      FIXTURES_SETUP "install-prepare")
  set_tests_properties("install"
    PROPERTIES
      FIXTURES_REQUIRED "install-prepare"
      FIXTURES_SETUP    "install")

  function(add_example2 dir mode root)
    add_test(
      NAME    "example-${mode}-${dir}-prepare"
      COMMAND "${CMAKE_COMMAND}" -E rm -rf
              "${CMAKE_CURRENT_BINARY_DIR}/${mode}-${dir}")
    add_test(
      NAME    "example-${mode}-${dir}"
      COMMAND "${CMAKE_CTEST_COMMAND}"
              --build-generator
                "${CMAKE_GENERATOR}"
              --build-and-test
                "${CMAKE_CURRENT_SOURCE_DIR}/${dir}"
                "${CMAKE_CURRENT_BINARY_DIR}/${mode}-${dir}"
              --build-options
                "-DBUILD_TESTING:BOOL=ON"
                "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
                "-DBUILD_SHARED_LIBS:BOOL=${BUILD_SHARED_LIBS}"
                "-Dcatalyst_DIR:PATH=${root}/${CATALYST_INSTALL_PACKAGE_DIR}"
              --test-command
                "${CMAKE_CTEST_COMMAND}"
                  -C $<CONFIGURATION>
                  -V)
    set_tests_properties("example-${mode}-${dir}"
      PROPERTIES
        FIXTURES_REQUIRED "fixture-${mode}-${dir}")
    set_tests_properties("example-${mode}-${dir}-prepare"
      PROPERTIES
        FIXTURES_SETUP "fixture-${mode}-${dir}")

    if (mode STREQUAL "install")
      # install-based tests, depend on the install fixture.
      set_tests_properties("example-${mode}-${dir}"
        PROPERTIES
          FIXTURES_REQUIRED "install")
    endif()
  endfunction()

  function(add_example dir)
    add_example2("${dir}" build "${CATALYST_BINARY_DIR}")
    add_example2("${dir}" install "${install_prefix}/${CMAKE_INSTALL_PREFIX}")
  endfunction()
else ()
  find_package(catalyst VERSION 2.0 REQUIRED)
  macro(add_example dir)
    add_subdirectory("${dir}")
  endmacro()
endif ()

add_example(about)
add_example(adaptor0)
