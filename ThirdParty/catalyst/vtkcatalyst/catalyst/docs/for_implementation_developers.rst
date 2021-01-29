Catalyst for Implementation Developers
######################################

Developers can develop custom implementations for the Catalyst API to support
a wide variety of use-cases. In most cases, however, if your goal is to use
ParaView for in situ data processing, it may be easier to simply use
**ParaView Catalyst**. It support several ways for describing computational
meshes and field arrays including `Mesh Blueprint`_ and `ADIS`_.

This section describes the workflow for those who want to implement a custom
implementation for the Catalyst API.


Prerequisites
=============

* To build a custom Catalyst implementation, your project needs to be a
  CMake-based project i.e. use CMake as the build system generator. While
  it is technically feasible to use a non-CMake based project, it is highly
  recommended to prefer to use CMake.


CMake Setup
===========

The following sample CMakeLists.txt shows how to build a Catalyst
implementation.

.. code-block:: cmake
    :linenos:

    # When implementing the Catalyst API, as against using
    # it to invoke Catalyst, one must use the component
    # `SDK` in `find_package` call. This ensures that all necessary
    # libraries etc. are available.
    find_package(catalyst
                 REQUIRED
                 COMPONENTS SDK)

    # Use `add_library` to add a library with the C (or C++) code
    # that is your implementation the Catalyst API.
    add_library(MyCustomCatalystImpl
                MyCustomCatalystImpl.cxx)

    # use this function call to mark any library as the
    # Catalyst API implementation.
    catalyst_library(
      TARGET MyCustomCatalystImpl)

That is it! `catalyst_apply_properties` sets up appropriate CMake
target-properties on the library including setting it's name and version number.
This function is only available when the `SDK` component is explicitly requested
in the `find_package(catalyst .. )` call.

Implementing Catalyst API
=========================

Providing an implementation for the Catalyst API implies providing code for the
four `catalyst_` functions that are part of the Catalyst API,
`catalyst_initialize`, `catalyst_finalize`, `catalyst_execute`, and
`catalyst_about`.

To do that, simply include `catalyst.h` header in your implementation file and
add definitions for these functions. Definitions for all the four functions must
be provided. You can choose to invoke the default stub implementation for any of
the functions by including the `catalyst_stub.h` header and then calling
`catalyst_stub_initialize`, `catalyst_stub_finalize`, `catalyst_stub_execute`,
or `catalyst_stub_about` in your implementations for the corresponding methods.

If your custom implementation is using C++, you can include
`c/conduit_cpp_to_c.hpp` headers to convert the `conduit_node` pointer to a
`conduit::Node` instance pointer using `conduit::cpp_node()`. Then you can use
the `conduit::Node` API which is generally friendlier than the C API.

.. code-block:: c++
    :linenos:

    #include <catalyst.h>
    #include <conduit.hpp>            // for conduit::Node
    #include <conduit_cpp_to_c.hpp>   // for conduit::cpp_node()

    ...

    void catalyst_about(conduit_node* params)
    {
      // convert to conduit::Node
      conduit::Node &cpp_params = (*conduit::cpp_node(params));

      // now, use conduit::Node API.
      cpp_params["catalyst"]["capabilities"].append().set("adaptor0");
    }


On successful build of your project, you should get a shared library named
`libcatalyst.so`, `libcatalyst.dylib`, or `catalyst.dll` on Linux, macOS, and
Windows respectively.

Using your Catalyst implementation
==================================

Now, to use your implementation with any simulation or code built with the stub
Catalyst implementation, all you need to do is to make sure your Catalyst
library is found and loaded by the runtime loader on your platform. On most
systems, this typically means you setup an environment variable with the path to
your implementation before launching the simulation executable. On linux, this
can be done using the `LD_LIBRARAY_PATH` variable (or `DYLD_LIBRARAY_PATH` or
`PATH` on macOS and Windows).



.. _`Mesh Blueprint`: https://llnl-conduit.readthedocs.io/en/latest/blueprint_mesh.html#mesh-blueprint

.. _`ADIS`: https://gitlab.kitware.com/vtk/adis
