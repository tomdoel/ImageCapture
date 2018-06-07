/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "captureOpenGLMainWindow.h"
#include "captureOpenGLImage.h"
#include "captureCameraWidget.h"

namespace capture
{

    //-----------------------------------------------------------------------------
    OpenGLMainWindow::OpenGLMainWindow(const QCameraInfo& camera_info) : QObject()
    {
        m_id = camera_info.deviceName();
        m_image_widget = std::unique_ptr<OpenGLImage>(new OpenGLImage);
        m_image_widget->setAttribute( Qt::WA_DeleteOnClose );
        connect(m_image_widget.get(), &QWidget::destroyed, this, &OpenGLMainWindow::mainWidgetDestroyed);

        m_camera_widget = std::unique_ptr<CameraWidget>(new CameraWidget(camera_info));
        m_camera_widget->addListener(m_image_widget.get());

        m_image_widget->showMaximized();
    }

    OpenGLMainWindow::~OpenGLMainWindow()
    {
    }

    void OpenGLMainWindow::mainWidgetDestroyed() {
        emit windowHasClosed(m_id);
    }

    void OpenGLMainWindow::setScreen(QScreen* screen) {
        QRect screen_geometry = screen->geometry();
//        QRect virtual_geometry = screen->virtualGeometry();
        m_image_widget->move(screen_geometry.x(), screen_geometry.y());
        m_image_widget->resize(screen_geometry.width(), screen_geometry.height());
        m_image_widget->windowHandle()->setScreen(screen);
        m_image_widget->showFullScreen();
    }

}
