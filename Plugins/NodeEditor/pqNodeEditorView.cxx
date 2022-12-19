/*=========================================================================

  Program:   ParaView
  Plugin:    NodeEditor

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/*-------------------------------------------------------------------------
  ParaViewPluginsNodeEditor - BSD 3-Clause License - Copyright (C) 2021 Jonas Lukasczyk

  See the Copyright.txt file provided
  with ParaViewPluginsNodeEditor for license information.
-------------------------------------------------------------------------*/

#include "pqNodeEditorView.h"
#include "pqNodeEditorUtils.h"

#include <pqDeleteReaction.h>

// qt includes
#include <QAction>
#include <QKeyEvent>
#include <QWheelEvent>

// ----------------------------------------------------------------------------
pqNodeEditorView::pqNodeEditorView(QGraphicsScene* scene, QWidget* parent)
  : QGraphicsView(scene, parent)
  , deleteAction(new QAction(this))
{
  // create delete reaction
  new pqDeleteReaction(this->deleteAction);

  this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
  this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

  this->setDragMode(QGraphicsView::ScrollHandDrag);
  constexpr QRectF MAX_SCENE_SIZE{ -1e4, -1e4, 3e4, 3e4 };
  this->setSceneRect(MAX_SCENE_SIZE);
}

// ----------------------------------------------------------------------------
void pqNodeEditorView::wheelEvent(QWheelEvent* event)
{
  constexpr double ZOOM_INCREMENT_RATIO = 0.1;

  const ViewportAnchor anchor = this->transformationAnchor();
  this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
  const int angle = event->angleDelta().y();
  const double factor = 1.0 + ((angle > 0) ? ZOOM_INCREMENT_RATIO : -ZOOM_INCREMENT_RATIO);

  this->scale(factor, factor);
  this->setTransformationAnchor(anchor);
}

// ----------------------------------------------------------------------------
void pqNodeEditorView::keyReleaseEvent(QKeyEvent* event)
{
  if (event->key() == Qt::Key_Delete)
  {
    this->deleteAction->trigger();
  }

  return QWidget::keyReleaseEvent(event);
}

// ----------------------------------------------------------------------------
void pqNodeEditorView::triggerDeleteAction() const
{
  this->deleteAction->trigger();
}
