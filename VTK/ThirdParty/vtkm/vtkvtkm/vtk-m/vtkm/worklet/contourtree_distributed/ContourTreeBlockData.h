//============================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//============================================================================
// Copyright (c) 2018, The Regents of the University of California, through
// Lawrence Berkeley National Laboratory (subject to receipt of any required approvals
// from the U.S. Dept. of Energy).  All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this
//     list of conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National
//     Laboratory, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//
//=============================================================================
//
//  This code is an extension of the algorithm presented in the paper:
//  Parallel Peak Pruning for Scalable SMP Contour Tree Computation.
//  Hamish Carr, Gunther Weber, Christopher Sewell, and James Ahrens.
//  Proceedings of the IEEE Symposium on Large Data Analysis and Visualization
//  (LDAV), October 2016, Baltimore, Maryland.
//
//  The PPP2 algorithm and software were jointly developed by
//  Hamish Carr (University of Leeds), Gunther H. Weber (LBNL), and
//  Oliver Ruebel (LBNL)
//==============================================================================

#ifndef vtk_m_worklet_contourtree_distributed_contourtreeblockdata_h
#define vtk_m_worklet_contourtree_distributed_contourtreeblockdata_h

#include <vtkm/Types.h>
#include <vtkm/worklet/contourtree_augmented/Types.h>

// clang-format off
VTKM_THIRDPARTY_PRE_INCLUDE
#include <vtkm/thirdparty/diy/diy.h>
VTKM_THIRDPARTY_POST_INCLUDE
// clang-format on


namespace vtkm
{
namespace worklet
{
namespace contourtree_distributed
{
template <typename FieldType>
struct ContourTreeBlockData
{
  static void* create() { return new ContourTreeBlockData<FieldType>; }
  static void destroy(void* b) { delete static_cast<ContourTreeBlockData<FieldType>*>(b); }

  // ContourTreeMesh data
  vtkm::Id NumVertices;
  // TODO Should be able to remove sortOrder here, but we need to figure out what to return in the worklet instead
  vtkm::worklet::contourtree_augmented::IdArrayType SortOrder;
  vtkm::cont::ArrayHandle<FieldType> SortedValue;
  vtkm::worklet::contourtree_augmented::IdArrayType GlobalMeshIndex;
  vtkm::worklet::contourtree_augmented::IdArrayType Neighbours;
  vtkm::worklet::contourtree_augmented::IdArrayType FirstNeighbour;
  vtkm::Id MaxNeighbours;

  // Block metadata
  vtkm::Id3 BlockOrigin;                // Origin of the data block
  vtkm::Id3 BlockSize;                  // Extends of the data block
  vtkm::Id3 GlobalSize;                 // Extends of the global mesh
  unsigned int ComputeRegularStructure; // pass through augmentation setting
};
} // namespace contourtree_distributed
} // namespace worklet
} // namespace vtkm


namespace vtkmdiy
{

// Struct to serialize ContourBlockData objects (i.e., load/save) needed in parralle for DIY
template <typename FieldType>
struct Serialization<vtkm::worklet::contourtree_distributed::ContourTreeBlockData<FieldType>>
{
  static void save(
    vtkmdiy::BinaryBuffer& bb,
    const vtkm::worklet::contourtree_distributed::ContourTreeBlockData<FieldType>& block)
  {
    vtkmdiy::save(bb, block.NumVertices);
    vtkmdiy::save(bb, block.SortOrder);
    vtkmdiy::save(bb, block.SortedValue);
    vtkmdiy::save(bb, block.GlobalMeshIndex);
    vtkmdiy::save(bb, block.Neighbours);
    vtkmdiy::save(bb, block.FirstNeighbour);
    vtkmdiy::save(bb, block.MaxNeighbours);
    vtkmdiy::save(bb, block.BlockOrigin);
    vtkmdiy::save(bb, block.BlockSize);
    vtkmdiy::save(bb, block.GlobalSize);
    vtkmdiy::save(bb, block.ComputeRegularStructure);
  }

  static void load(vtkmdiy::BinaryBuffer& bb,
                   vtkm::worklet::contourtree_distributed::ContourTreeBlockData<FieldType>& block)
  {
    vtkmdiy::load(bb, block.NumVertices);
    vtkmdiy::load(bb, block.SortOrder);
    vtkmdiy::load(bb, block.SortedValue);
    vtkmdiy::load(bb, block.GlobalMeshIndex);
    vtkmdiy::load(bb, block.Neighbours);
    vtkmdiy::load(bb, block.FirstNeighbour);
    vtkmdiy::load(bb, block.MaxNeighbours);
    vtkmdiy::load(bb, block.BlockOrigin);
    vtkmdiy::load(bb, block.BlockSize);
    vtkmdiy::load(bb, block.GlobalSize);
    vtkmdiy::load(bb, block.ComputeRegularStructure);
  }
};

} // namespace mangled_vtkmdiy_namespace


#endif
