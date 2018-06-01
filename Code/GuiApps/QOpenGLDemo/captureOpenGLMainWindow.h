/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#pragma once

#include <QWindow>
#include <QCameraInfo>

namespace capture
{

    class OpenGLWidget;
    class OpenGLImage;

    /**
 * \class OpenGLMainWindow
 * \brief Demo
 */
    class OpenGLMainWindow
    {

        public:

            OpenGLMainWindow(const QCameraInfo&);

            void show();

        private:
            OpenGLWidget *m_Widget;
            OpenGLImage *m_image_widget;
    };

}


