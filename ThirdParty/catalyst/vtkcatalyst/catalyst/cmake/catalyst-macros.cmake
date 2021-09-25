# Macros and other CMake code part of the Catalyst SDK i.e.
# API used to build Catalyst API implementations.

#[==[
Mark a target as the Catalyst API implementation.

~~~{.cmake}
catalyst_library(
  TARGET    <target>
  [LIBRARY_DESTINATION <destination>]
  [INSTALL_EXPORT_DEFAULT]
  )
~~~

The `TARGET` identifies the target added using an `add_library` call.
This function ensures that properties on the target are set up
appropriately so that the generated library is ABI compatible
with the Catalyst stub implementation.

`LIBRARY_DESTINATION` if specified, is used to determine the install destination.
If not specified, no install rule is added.

`INSTALL_EXPORT_DEFAULT` is useful in projects that include Catalyst as a
sub-project (instead of using it externally) to build Catalyst implementations.
For such projects, the Catalyst library is often built as a part of the project.
Providing INSTALL_EXPORT_DEFAULT ensures that the Catalyst implementation is
added as a part of the export set for the Catalyst targets so that
`find_package(catalyst ... )` can work seamlessly.
If `LIBRARY_DESTINATION` must be specified if `INSTALL_EXPORT_DEFAULT`
specified.


#]==]
function(catalyst_library)
  cmake_parse_arguments(PARSE_ARGV 0 arg "INSTALL_EXPORT_DEFAULT" "TARGET;LIBRARY_DESTINATION" "")
  if (arg_UNPARSED_ARGUMENT)
    message(FATAL_ERROR
      "Unknown argument(s) passed to 'catalyst_library': '${arg_UNPARSED_ARGUMENT}'")
  endif()
  if (arg_INSTALL_EXPORT_DEFAULT AND NOT (arg_TARGET STREQUAL "catalyst"))
    message(WARNING
      "Target not named 'catalyst'. find_package(catalyst .. ) may not work as "
      "expected.")
  endif()
  if (arg_INSTALL_EXPORT_DEFAULT AND NOT DEFINED arg_LIBRARY_DESTINATION)
    message(WARNING
      "'INSTALL_EXPORT_DEFAULT' specified without 'LIBRARY_DESTINATION'."
      "Argument has no effect.")
  endif()

  target_link_libraries(${arg_TARGET}
    PUBLIC
      catalyst::core
      catalyst::conduit_headers
    PRIVATE
      catalyst::conduit
      catalyst::blueprint)
  set_target_properties(${arg_TARGET}
    PROPERTIES
      VERSION   "${CATALYST_ABI_VERSION}"
      SOVERSION "${CATALYST_ABI_VERSION}"
      OUTPUT_NAME "catalyst")

  set (_exports)
  if (arg_INSTALL_EXPORT_DEFAULT)
    set (_exports EXPORT Catalyst)
  endif()
  if (arg_LIBRARY_DESTINATION)
    install(
      TARGETS ${arg_TARGET}
      ${_exports}
      RUNTIME DESTINATION ${arg_LIBRARY_DESTINATION}
      LIBRARY DESTINATION ${arg_LIBRARY_DESTINATION})
  endif()
endfunction()

#-------------------------------------------------------------
# internal macros
#-------------------------------------------------------------
macro (c_set_if_not_set variable)
  if (NOT DEFINED "${variable}")
    set("${variable}" ${ARGN})
  endif()
endmacro()

function(c_install_targets)
  install(
    TARGETS ${ARGN}
    EXPORT  Catalyst
    ARCHIVE
      DESTINATION "${CATALYST_INSTALL_ARCHIVE_DIR}"
    LIBRARY
      DESTINATION "${CATALYST_INSTALL_LIBRARY_DIR}"
    RUNTIME
      DESTINATION "${CATALYST_INSTALL_RUNTIME_DIR}")
  foreach (arg IN LISTS ARGN)
    get_property(type
                 TARGET ${arg}
                 PROPERTY TYPE)
    # all static libraries are mangled using `catalyst_` prefix.
    # we don't mangle shared libs since this project only builds the
    # `catalyst` library as shared.
    if (type STREQUAL STATIC_LIBRARY)
      set_property(TARGET ${arg}
        PROPERTY OUTPUT_NAME ${arg}${CATALYST_CUSTOM_LIBRARY_SUFFIX})
    endif()
  endforeach()
endfunction()

function(c_install_headers)
  cmake_parse_arguments(PARSE_ARGV 0 "arg" "" "SUBDIR" "HEADERS")
  if (arg_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR
      "unknown arguments passed to 'c_install_headers': '${arg_UNPARSED_ARGUMENTS}'")
  endif()
  install(
    FILES ${arg_HEADERS}
    DESTINATION "${CATALYST_INSTALL_INCLUDE_DIR}/${arg_SUBDIR}")
endfunction()
