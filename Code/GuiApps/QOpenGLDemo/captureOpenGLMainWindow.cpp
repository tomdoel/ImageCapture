/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "captureOpenGLMainWindow.h"
#include "captureOpenGLWidget.h"
#include "captureOpenGLImage.h"
#include "captureCameraWidget.h"
#include "captureLabelImage.h"
#include <QVBoxLayout>

namespace capture
{

    //-----------------------------------------------------------------------------
    OpenGLMainWindow::OpenGLMainWindow(const QCameraInfo& camera_info)
    {
        QWidget* mainWidget = new QWidget;

        m_Widget = new OpenGLWidget;
        m_image_widget = new OpenGLImage;

        CameraWidget *cameraWidget = new CameraWidget(camera_info);
        cameraWidget->addListener(m_image_widget);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainWidget->setLayout(mainLayout);

        mainLayout->addWidget(this->m_image_widget);
        mainLayout->addWidget(this->m_Widget);

        mainWidget->showMaximized();
    }

}
