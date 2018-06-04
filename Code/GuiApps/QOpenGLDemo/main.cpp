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
#include "captureapplication.h"

int main(int argc, char *argv[])
{
    capture::CaptureApplication app(argc, argv);
    return app.run();
}
