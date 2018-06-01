/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef captureOpenGLMainWindow_h
#define captureOpenGLMainWindow_h

#include <QMainWindow>
#include <QCameraInfo>

namespace capture
{

class OpenGLWidget;
class OpenGLImage;

/**
 * \class OpenGLMainWindow
 * \brief Demo QMainWindow subclass just to hold our OpenGLWidget.
 */
class OpenGLMainWindow : public QMainWindow
{

public:

  OpenGLMainWindow(const QCameraInfo&);

private:
  OpenGLWidget *m_Widget;
  OpenGLImage *m_image_widget;
};

} // end namespace

#endif
