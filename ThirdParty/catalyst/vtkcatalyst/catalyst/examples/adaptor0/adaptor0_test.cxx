/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */
#include <cstdlib>
#include <cstring>
#include <iostream>

#include <catalyst.h>

int main(int argc, char* argv[])
{
  auto node = conduit_node_create();
  catalyst_about(node);
  auto implementation = conduit_node_fetch_path_as_char8_str(node, "catalyst/implementation");
  if (strcmp(implementation, "examples/adaptor0") != 0)
  {
    std::cout << "TEST FAILED! " << std::endl
              << "Catalyst implementation is not the one built by this example!"
              << "Make sure the environment is setup correctly to load the Catalyst "
              << "library built by this example, rather than the default stub version."
              << std::endl;
    conduit_node_destroy(node);
    return EXIT_FAILURE;
  }

  conduit_node_destroy(node);
  return EXIT_SUCCESS;
}
