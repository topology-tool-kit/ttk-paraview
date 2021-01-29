set(libyaml_sources
    src/api.c
    src/dumper.c
    src/emitter.c
    src/loader.c
    src/parser.c
    src/reader.c
    src/scanner.c
    src/writer.c
    )

#
# libyaml headers
#

set(libyaml_headers
    include/yaml.h
    include/catalyst_yaml_mangle.h
    src/yaml_private.h)

add_library(libyaml STATIC
  ${libyaml_sources})
target_include_directories(libyaml
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

c_install_targets(libyaml)

if (WIN32)
  target_compile_definitions(libyaml
    PRIVATE
      CONDUIT_PLATFORM_WINDOWS)
endif()

# use cxx linker to avoid msvc static build issues
set_target_properties(libyaml PROPERTIES LINKER_LANGUAGE CXX)
