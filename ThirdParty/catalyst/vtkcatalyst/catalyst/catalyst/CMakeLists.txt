# catalyst library is always built SHARED.
# this is necessary so that it be loaded in simulations built with
# stub catalyst build.
add_library(catalyst SHARED
  catalyst.cxx)
add_library(catalyst::catalyst ALIAS catalyst)
catalyst_library(TARGET catalyst)
c_install_targets(catalyst)
