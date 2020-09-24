/*=========================================================================

   Program: ParaView
   Module:  pqLiveSourceBehavior.h

   Copyright (c) 2005,2006 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2.

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/
#ifndef pqLiveSourceBehavior_h
#define pqLiveSourceBehavior_h

#include "pqApplicationComponentsModule.h"
#include <QObject>
#include <QScopedPointer>

class pqPipelineSource;
class pqView;

/**
 * @class pqLiveSourceBehavior
 * @ingroup Behaviors
 *
 * pqLiveSourceBehavior adds support for "live" algorithms. These are
 * vtkAlgorithm subclasses that have a method `GetNeedsUpdate` which returns
 * true (bool) when source may have new data and should be refreshed.
 *
 * To indicate a source is a "live source", one needs to simply add
 * `<LiveSource>` XML hint for the source proxy.
 */
class PQAPPLICATIONCOMPONENTS_EXPORT pqLiveSourceBehavior : public QObject
{
  Q_OBJECT
  typedef QObject Superclass;

public:
  pqLiveSourceBehavior(QObject* parent = 0);
  ~pqLiveSourceBehavior() override;

  /**
   * Pause live updates.
   */
  static void pause();

  /**
   * Resume live updates.
   */
  static void resume();

  /**
   * Returns true if live updates are paused.
   */
  static bool isPaused() { return pqLiveSourceBehavior::PauseLiveUpdates; }

protected slots:
  void viewAdded(pqView*);
  void sourceAdded(pqPipelineSource*);
  void timeout();

private:
  Q_DISABLE_COPY(pqLiveSourceBehavior);
  void startInteractionEvent();
  void endInteractionEvent();

  class pqInternals;
  QScopedPointer<pqInternals> Internals;

  static bool PauseLiveUpdates;
};

#endif
