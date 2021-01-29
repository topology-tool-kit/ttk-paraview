set(libb64_sources
    src/cdecode.cpp
    src/cencode.cpp
    )

set(libb64_headers
    include/b64/cdecode.h
    include/b64/cencode.h
    include/b64/decode.h
    include/b64/encode.h
    include/b64/catalyst_b64_mangle.h)

add_library(b64 STATIC
  ${libb64_sources})
target_include_directories(b64
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

c_install_targets(b64)
