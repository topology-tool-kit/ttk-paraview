if (WIN32)
  add_definitions(-DNOMINMAX)
endif ()

cmake_policy(PUSH)
if (POLICY CMP0076)
  cmake_policy(SET CMP0076 NEW)
else ()
  message(FATAL_ERROR
    "VisItBridge requires CMake 3.13.")
endif ()

vtk_module_third_party_internal(
  SPDX_LICENSE_IDENTIFIER
    "BSD-3-Clause"
  SPDX_COPYRIGHT_TEXT
    "Copyright (c) 2000 - 2020, Lawrence Livermore National Security, LLC"
    "copyright (C) 2007 martin isenburg@cs.unc.edu"
    "Copyright (c) 2010, University of New Hampshire Computer Science Department"
    "Copyright (c) 1993-2002 Ken Martin, Will Schroeder, Bill Lorensen"
  SPDX_DOWNLOAD_LOCATION
    "git+https://gitlab.kitware.com/paraview/visitbridge.git@756b0aa4ee"
  LICENSE_FILES
    "../LICENSE"
  VERSION
    "master-756b0aa4ee" # Mon Mar 30 09:31:47 2020 -0700
  SUBDIRECTORY
    "VisItLib")

cmake_policy(POP)
