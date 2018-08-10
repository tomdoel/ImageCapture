/*=============================================================================

  OPENGLTEST: A software package for OpenGL.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef mpOpenGLImage_h
#define mpOpenGLImage_h
#define GL_GLEXT_PROTOTYPES

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "captureVideoOutput.h"

namespace capture
{

/**
 * \class OpenGLWidget
 * \brief Demo Widget to show how to an image rendered as an OpenGL texture.
 */
class OpenGLImage : public QOpenGLWidget, protected QOpenGLFunctions, public VideoOutput
{
  Q_OBJECT

public:

  OpenGLImage(QWidget *parent = 0);
  ~OpenGLImage();

  static bool isTransparent() { return m_IsTransparent; }
  static void setTransparent(bool t) { m_IsTransparent = t; }

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

public slots:

  void cleanup();

protected:

  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;

private:

  void checkError();

  static bool m_IsTransparent;
  bool        m_IsCore;

  GLuint      m_video_vertex_array_id;
  GLuint      m_video_vertex_buffer_id;
  GLuint      m_vertex_shader_id;
  GLuint      m_fragment_shader_id;
  GLuint      m_shader_program_id;
  GLuint      m_video_element_buffer_id;
  GLuint      m_texture_id;

  int m_last_width;
  int m_last_height;

public:
  void updateImage(QImage *image) override;
};

} // end namespace

#endif
