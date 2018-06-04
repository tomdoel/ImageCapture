/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#pragma once

#include <QObject>
#include <QWindow>
#include <QScreen>
#include <QCameraInfo>

namespace capture
{

    class OpenGLWidget;
    class OpenGLImage;

    /**
 * \class OpenGLMainWindow
 * \brief Demo
 */
    class OpenGLMainWindow: public QObject
    {
            Q_OBJECT

        public:

            OpenGLMainWindow(const QCameraInfo&);

            void show();
            void setScreen(QScreen* screen);

        signals:
            void windowHasClosed(QString);

        private:
            OpenGLWidget *m_Widget;
            OpenGLImage *m_image_widget;
            QString m_id;
            QWidget* m_main_widget;

        private slots:
            void mainWidgetDestroyed();
    };

}


