/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <QApplication>
#include <QDesktopWidget>
#include <QSurfaceFormat>
#include "ImageCaptureConfigure.h"
#include "captureOpenGLWidget.h"
#include "captureOpenGLMainWindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  app.setOrganizationName("UCL");
  app.setApplicationName("QOpenGLDemo");
  app.setApplicationVersion(QString(IMAGECAPTURE_VERSION_STRING));

  QSurfaceFormat fmt;
  fmt.setDepthBufferSize(24);
  fmt.setVersion(3, 2);
  fmt.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(fmt);

  capture::OpenGLMainWindow mainWindow;
  capture::OpenGLWidget::setTransparent(false);
  if (capture::OpenGLWidget::isTransparent())
  {
    mainWindow.setAttribute(Qt::WA_TranslucentBackground);
    mainWindow.setAttribute(Qt::WA_NoSystemBackground, false);
  }
  mainWindow.resize(mainWindow.sizeHint());
  int desktopArea = QApplication::desktop()->width() *
                    QApplication::desktop()->height();
  int widgetArea = mainWindow.width() * mainWindow.height();
  if (((float)widgetArea / (float)desktopArea) < 0.75f)
  {
    mainWindow.show();
  }
  else
  {
    mainWindow.showMaximized();
  }
  return app.exec();
}
