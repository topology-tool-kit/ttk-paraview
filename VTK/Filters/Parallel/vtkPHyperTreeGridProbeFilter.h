/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPHyperTreeGridProbeFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkPHyperTreeGridProbeFilter
 * @brief   probe a vtkHyperTreeGrid in parallel
 *
 * Heavily modeled after the vtkPProbeFilter and vtkProbeFilter, this class
 *  is meant to be used to probe vtkHyperTreeGrid objects in parallel.
 *
 * This filter works correctly only if the whole geometry dataset
 * (that specify the point locations used to probe input) is present on all
 * nodes.
 *
 * Possible optimizations:
 * - Enrich the parallelism logic allowing for both distributed sources and input/outputs
 */

#ifndef vtkPHyperTreeGridProbeFilter_h
#define vtkPHyperTreeGridProbeFilter_h

#include "vtkFiltersParallelModule.h" //For export Macro
#include "vtkHyperTreeGridProbeFilter.h"
#include "vtkSmartPointer.h" //For Locator member

class vtkMultiProcessController;
class vtkIdList;
class vtkDataSet;
class vtkHyperTreeGrid;
class vtkHyperTreeGridLocator;

class VTKFILTERSPARALLEL_EXPORT vtkPHyperTreeGridProbeFilter : public vtkHyperTreeGridProbeFilter
{
public:
  vtkTypeMacro(vtkPHyperTreeGridProbeFilter, vtkHyperTreeGridProbeFilter);

  void PrintSelf(ostream& os, vtkIndent indent) override;

  static vtkPHyperTreeGridProbeFilter* New();

  ///@{
  /**
   * Set and get the controller.
   */
  virtual void SetController(vtkMultiProcessController*);
  vtkGetObjectMacro(Controller, vtkMultiProcessController);
  ///@}

protected:
  ///@{
  /**
   * Construction methods
   */
  vtkPHyperTreeGridProbeFilter();
  ~vtkPHyperTreeGridProbeFilter() override;
  ///@}

  ///@{
  /**
   * Overridden here because it is important that the input be updated on all processes
   */
  int RequestUpdateExtent(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;
  ///@}

  ///@{
  /**
   * Helper method for reducing the distributed data to the master process
   */
  bool Reduce(vtkHyperTreeGrid* source, vtkDataSet* output, vtkIdList* localPointIds);
  ///@}

  enum
  {
    HYPERTREEGRID_PROBE_COMMUNICATION_TAG = 4242
  };

  vtkMultiProcessController* Controller = nullptr;

private:
  vtkPHyperTreeGridProbeFilter(const vtkPHyperTreeGridProbeFilter&) = delete;
  void operator=(const vtkPHyperTreeGridProbeFilter&) = delete;

}; // vtkPHyperTreeGridProbeFilter

#endif // vtkPHyperTreeGridProbeFilter_h
