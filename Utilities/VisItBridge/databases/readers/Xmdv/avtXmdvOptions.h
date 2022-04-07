// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                             avtXmdvOptions.h                              //
// ************************************************************************* //

#ifndef AVT_Xmdv_OPTIONS_H
#define AVT_Xmdv_OPTIONS_H

class DBOptionsAttributes;

#include <string>


// ****************************************************************************
//  Functions: avtXmdvOptions
//
//  Purpose:
//      Creates the options for  Xmdv readers and/or writers.
//
//  Programmer: childs -- generated by xml2avt
//  Creation:   Tue Jul 19 17:30:27 PST 2005
//
// ****************************************************************************

DBOptionsAttributes *GetXmdvReadOptions(void);
DBOptionsAttributes *GetXmdvWriteOptions(void);


#endif
