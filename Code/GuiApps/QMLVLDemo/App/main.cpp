/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/
#include <vlCore/VisualizationLibrary.hpp>
#include "captureTriangleModel.h"
#include "ImageCaptureConfigure.h"

#include <QGuiApplication>
#include <QtQuick/QQuickView>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  app.setOrganizationName("UCL");
  app.setApplicationName("QMLVLDemo");
  app.setApplicationVersion(QString(IMAGECAPTURE_VERSION_STRING));

  qmlRegisterType<capture::TriangleModel>("VLUnderQML", 1, 0, "TriangleModel");

  /* init Visualization Library */
  vl::VisualizationLibrary::init();

  QQuickView view;
  view.setResizeMode(QQuickView::SizeRootObjectToView);
  view.setSource(QUrl("qrc:/main.qml"));
  view.show();

  /* shutdown Visualization Library */
  vl::VisualizationLibrary::shutdown();

  return app.exec();
}

