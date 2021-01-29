# CMakeLists for Catalyst

configure_file (conduit_blueprint_exports.h.in
                conduit_blueprint_exports.h)


# Specify all headers
#
set(blueprint_headers
    conduit_blueprint.hpp
    conduit_blueprint_mesh.hpp
    conduit_blueprint_mesh_examples.hpp
    conduit_blueprint_mcarray.hpp
    conduit_blueprint_mcarray_examples.hpp
    conduit_blueprint_zfparray.hpp
    ${CMAKE_CURRENT_BINARY_DIR}/conduit_blueprint_exports.h
)

#
# Specify blueprint c sources
#
set(blueprint_c_headers
    c/conduit_blueprint.h
    c/conduit_blueprint_mcarray.h
    c/conduit_blueprint_mesh.h
    )


#
# Specify blueprint cpp sources
#
set(blueprint_sources
    conduit_blueprint.cpp
    conduit_blueprint_mesh.cpp
    conduit_blueprint_mesh_examples.cpp
    conduit_blueprint_mcarray.cpp
    conduit_blueprint_mcarray_examples.cpp
    conduit_blueprint_zfparray.cpp
    )

#
# Specify blueprint c sources
#
set(blueprint_c_sources
    c/conduit_blueprint_c.cpp
    c/conduit_blueprint_mcarray_c.cpp
    c/conduit_blueprint_mesh_c.cpp
    )

#-------------------------------------------------------------------------
# build blueprint library
add_library(blueprint STATIC
  ${blueprint_sources}
  ${blueprint_c_sources})
target_link_libraries(blueprint
  PUBLIC
    catalyst::conduit)
target_include_directories(blueprint
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/c>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:${CATALYST_INSTALL_INCLUDE_DIR}>)
add_library(catalyst::blueprint ALIAS blueprint)
c_install_targets(blueprint)
c_install_headers(
  HEADERS ${blueprint_headers}
          ${blueprint_c_headers})
