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
    OpenGLMainWindow::OpenGLMainWindow(const QCameraInfo& camera_info) : QObject()
    {
        m_id = camera_info.deviceName();
        m_main_widget = new QWidget;
        m_main_widget->setAttribute( Qt::WA_DeleteOnClose );
        connect(m_main_widget, &QWidget::destroyed, this, &OpenGLMainWindow::mainWidgetDestroyed);

        m_Widget = new OpenGLWidget;
        m_image_widget = new OpenGLImage;

        CameraWidget *cameraWidget = new CameraWidget(camera_info);
        cameraWidget->addListener(m_image_widget);

        QVBoxLayout *mainLayout = new QVBoxLayout;
        m_main_widget->setLayout(mainLayout);

        mainLayout->addWidget(this->m_image_widget);
        mainLayout->addWidget(this->m_Widget);

        m_main_widget->showMaximized();
    }

    void OpenGLMainWindow::mainWidgetDestroyed() {
        emit windowHasClosed(m_id);
    }

    void OpenGLMainWindow::setScreen(QScreen* screen) {
        m_main_widget->windowHandle()->setScreen(screen);
        QRect geometry = screen->virtualGeometry();
        m_main_widget->move(geometry.x(), geometry.y());
        m_main_widget->showFullScreen();
    }

}
