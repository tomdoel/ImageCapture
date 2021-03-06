/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <QVTKApplication.h>
#include "ImageCaptureConfigure.h"
#include "captureMainWindow.h"
#include <captureVolumeRenderingModel.h>
#include <QScopedPointer>

#ifdef BUILD_VTK_OpenGL2
#include <QSurfaceFormat>
#include <QVTKOpenGLWidget.h>
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkNew.h"
#endif

int main(int argc, char** argv)
{

#ifdef BUILD_VTK_OpenGL2
  vtkOpenGLRenderWindow::SetGlobalMaximumNumberOfMultiSamples(0);
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
#endif

  QVTKApplication app(argc, argv);
  app.setOrganizationName("UCL");
  app.setApplicationName("QtVTKDemo");
  app.setApplicationVersion(QString(IMAGECAPTURE_VERSION_STRING));

  QScopedPointer<capture::VolumeRenderingModel> mb(new capture::VolumeRenderingModel());

  capture::MainWindow mainWin(mb.data());

  mainWin.show();
  mainWin.ConnectRenderer();
  mainWin.showMaximized();

  return app.exec();
}
