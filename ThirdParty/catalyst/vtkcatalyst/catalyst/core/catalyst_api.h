/*
 * Distributed under OSI-approved BSD 3-Clause License. See
 * accompanying License.txt
 */

#ifndef catalyst_api_h
#define catalyst_api_h

// include mangled conduit C API.
#include <conduit.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * Initialize Catalyst.
   * TODO: add more docs
   */
  CATALYST_EXPORT void catalyst_initialize(const conduit_node* params);

  /**
   * Execute per timestep.
   * TODO: add more docs.
   */
  CATALYST_EXPORT void catalyst_execute(const conduit_node* params);

  /**
   * finalize catalyst.
   * TODO: more docs
   */
  CATALYST_EXPORT void catalyst_finalize(const conduit_node* params);

  /**
   * Returns information about the catalyst library
   */
  CATALYST_EXPORT void catalyst_about(conduit_node* params);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // #ifndef catalyst_api_h
