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
#include "cameradetector.h"
#include "capturecontroller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("UCL");
    app.setApplicationName("QOpenGLDemo");
    app.setApplicationVersion(QString(IMAGECAPTURE_VERSION_STRING));

    capture::CaptureController controller;

    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    fmt.setVersion(3, 2);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(fmt);

    controller.updateWindows();
    return app.exec();
}
