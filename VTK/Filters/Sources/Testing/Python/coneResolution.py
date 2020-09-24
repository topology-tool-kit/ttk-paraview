#!/usr/bin/env python
import vtk
from vtk.util.misc import vtkGetDataRoot
VTK_DATA_ROOT = vtkGetDataRoot()

# create a rendering window and renderer
ren1 = vtk.vtkRenderer()
renWin = vtk.vtkRenderWindow()
renWin.AddRenderer(ren1)
iren = vtk.vtkRenderWindowInteractor()
iren.SetRenderWindow(renWin)
# create cones of varying resolution
cone0 = vtk.vtkConeSource()
cone0.SetResolution(0)
cone1 = vtk.vtkConeSource()
cone1.SetResolution(1)
cone2 = vtk.vtkConeSource()
cone2.SetResolution(2)
cone8 = vtk.vtkConeSource()
cone8.SetResolution(8)
cone0Mapper = vtk.vtkPolyDataMapper()
cone0Mapper.SetInputConnection(cone0.GetOutputPort())
cone0Actor = vtk.vtkActor()
cone0Actor.SetMapper(cone0Mapper)
cone1Mapper = vtk.vtkPolyDataMapper()
cone1Mapper.SetInputConnection(cone1.GetOutputPort())
cone1Actor = vtk.vtkActor()
cone1Actor.SetMapper(cone1Mapper)
cone2Mapper = vtk.vtkPolyDataMapper()
cone2Mapper.SetInputConnection(cone2.GetOutputPort())
cone2Actor = vtk.vtkActor()
cone2Actor.SetMapper(cone2Mapper)
cone8Mapper = vtk.vtkPolyDataMapper()
cone8Mapper.SetInputConnection(cone8.GetOutputPort())
cone8Actor = vtk.vtkActor()
cone8Actor.SetMapper(cone8Mapper)
# assign our actor to the renderer
ren1.AddActor(cone0Actor)
ren1.AddActor(cone1Actor)
ren1.AddActor(cone2Actor)
ren1.AddActor(cone8Actor)
ren1.SetBackground(.5,.5,.5)
ren1.ResetCamera()
ren1.GetActiveCamera().Elevation(30)
ren1.GetActiveCamera().Dolly(1.3)
ren1.ResetCameraClippingRange()
renWin.SetSize(300,90)
cone0Actor.SetPosition(-1.5,0,0)
cone1Actor.SetPosition(-.5,0,0)
cone2Actor.SetPosition(.5,0,0)
cone8Actor.SetPosition(1.5,0,0)
cone0Actor.GetProperty().SetDiffuseColor(1,0,0)
cone1Actor.GetProperty().SetDiffuseColor(0,1,0)
cone8Actor.GetProperty().BackfaceCullingOn()
cone8Actor.GetProperty().SetDiffuseColor(0,0,1)
# enable user interface interactor
iren.Initialize()
# prevent the tk window from showing up then start the event loop
# --- end of script --
