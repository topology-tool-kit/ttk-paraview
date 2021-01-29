/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */
#include <catalyst.h>
#include <catalyst_stub.h>
#include <conduit.hpp>
#include <conduit_cpp_to_c.hpp>

//-----------------------------------------------------------------------------
void catalyst_initialize(const conduit_node*) {}

//-----------------------------------------------------------------------------
void catalyst_execute(const conduit_node*) {}

//-----------------------------------------------------------------------------
void catalyst_finalize(const conduit_node*) {}

//-----------------------------------------------------------------------------
void catalyst_about(conduit_node* params)
{
  catalyst_stub_about(params);
  auto& cpp_params = (*conduit::cpp_node(params));
  cpp_params["catalyst"]["capabilities"].append().set("adaptor0");
  cpp_params["catalyst"]["implementation"] = "examples/adaptor0";
}
