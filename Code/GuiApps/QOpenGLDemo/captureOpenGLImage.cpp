/*=============================================================================

  OPENGLTEST: A software package for OpenGL.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "captureOpenGLImage.h"
#include <QCoreApplication>
#include <QDebug>
#include <QOpenGLTexture>

namespace capture
{

    bool OpenGLImage::m_IsTransparent = false;

    // Shader sources
    const GLchar* vertexShaderSource = R"glsl(
        #version 150 core
        in vec2 position;
        in vec3 color;
        in vec2 texcoord;
        out vec3 Color;
        out vec2 Texcoord;
        void main()
        {
            Color = color;
            Texcoord = texcoord;
            gl_Position = vec4(position, 0.0, 1.0);
        }
    )glsl";

    const GLchar* fragmentShaderSource = R"glsl(
        #version 150 core
        in vec3 Color;
        in vec2 Texcoord;
        out vec4 outColor;
        uniform sampler2D tex;
        void main()
        {
            outColor = texture(tex, Texcoord);
        }
    )glsl";


//-----------------------------------------------------------------------------
OpenGLImage::OpenGLImage(QWidget *parent)
: QOpenGLWidget(parent)
, m_IsCore(false)
{
  m_IsCore = QSurfaceFormat::defaultFormat().profile() == QSurfaceFormat::CoreProfile;
  if (m_IsTransparent)
  {
    QSurfaceFormat fmt = format();
    fmt.setAlphaBufferSize(8);
    setFormat(fmt);
  }
}

//-----------------------------------------------------------------------------
OpenGLImage::~OpenGLImage()
{
  cleanup();
}

//-----------------------------------------------------------------------------
QSize OpenGLImage::minimumSizeHint() const
{
  return QSize(400, 150);
}


//-----------------------------------------------------------------------------
QSize OpenGLImage::sizeHint() const
{
  return QSize(400, 300);
}



//-----------------------------------------------------------------------------
void OpenGLImage::cleanup()
{
    this->makeCurrent();

    glDeleteTextures(1, &m_texture_id);
    glDeleteProgram(m_shader_program_id);
    glDeleteShader(m_fragment_shader_id);
    glDeleteShader(m_vertex_shader_id);
    glDeleteBuffers(1, &m_vertex_buffer_id);
    glDeleteBuffers(1, &m_element_buffer_id);
    glDeleteVertexArrays(1, &m_vertex_array_id);

    this->doneCurrent();
}


//-----------------------------------------------------------------------------
void OpenGLImage::initializeGL()
{
    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &OpenGLImage::cleanup);

    initializeOpenGLFunctions();
    checkError();

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    checkError();

    glGenVertexArrays(1, &m_vertex_array_id);
    checkError();

    glBindVertexArray(m_vertex_array_id);
    checkError();

    glGenBuffers(1, &m_vertex_buffer_id);
    checkError();

    GLfloat vertices[] = {
    //  2xposition, 3xcolour, 2xtec coords
        -1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top left
         1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top right
         1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom right
        -1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom left
    };

    glBindBuffer(GL_ARRAY_BUFFER, m_vertex_buffer_id);
    checkError();

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    checkError();

    glGenBuffers(1, &m_element_buffer_id);
    checkError();

    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_element_buffer_id);
    checkError();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
    checkError();

    m_vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    checkError();

    glShaderSource(m_vertex_shader_id, 1, &vertexShaderSource, NULL);
    checkError();

    glCompileShader(m_vertex_shader_id);

    // Check for compilation failure
    GLint isCompiled = 0;
    glGetShaderiv(m_vertex_shader_id, GL_COMPILE_STATUS, &isCompiled);    
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_vertex_shader_id, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> error_text(maxLength);
        glGetShaderInfoLog(m_vertex_shader_id, maxLength, &maxLength, &error_text[0]);

        qInfo() << "glCompileShader(vertexShader): Error:" << error_text;
    }
    checkError();

    m_fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
    checkError();
    glShaderSource(m_fragment_shader_id, 1, &fragmentShaderSource, NULL);
    checkError();

    glCompileShader(m_fragment_shader_id);

    // Check for compilation failure
    isCompiled = 0;
    glGetShaderiv(m_fragment_shader_id, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(m_fragment_shader_id, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> error_text(maxLength);
        glGetShaderInfoLog(m_fragment_shader_id, maxLength, &maxLength, &error_text[0]);

        qInfo() << "glCompileShader(fragmentShader): Error:" << error_text;
    }
    checkError();

    // Link the vertex and fragment shader into a shader program
    m_shader_program_id = glCreateProgram();
    checkError();

    glAttachShader(m_shader_program_id, m_vertex_shader_id);
    checkError();

    glAttachShader(m_shader_program_id, m_fragment_shader_id);
    checkError();
    glBindFragDataLocation(m_shader_program_id, 0, "outColor");
    checkError();
    glLinkProgram(m_shader_program_id);

    //check if link was successful
    GLint linkError = -1;
    glGetProgramiv(m_shader_program_id, GL_LINK_STATUS, &linkError);
    if (GL_TRUE != linkError)
    {
        qInfo() << "glLinkProgram error with shaderProgram:" << linkError;
    }
    checkError();

    glUseProgram(m_shader_program_id);
    checkError();

    GLint posAttrib = glGetAttribLocation(m_shader_program_id, "position");
    checkError();
    glEnableVertexAttribArray(posAttrib);
    checkError();
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);
    checkError();

    GLint colAttrib = glGetAttribLocation(m_shader_program_id, "color");
    checkError();
    glEnableVertexAttribArray(colAttrib);
    checkError();
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));
    checkError();

    GLint texAttrib = glGetAttribLocation(m_shader_program_id, "texcoord");
    checkError();
    glEnableVertexAttribArray(texAttrib);
    checkError();
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));
    checkError();

    glGenTextures(1, &m_texture_id);
    checkError();
    glBindTexture(GL_TEXTURE_2D, m_texture_id);
    checkError();

    int texture_width = 0;
    int texture_height = 0;
    m_last_width = 0;
    m_last_height = 0;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_width, texture_height, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
    checkError();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    checkError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    checkError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    checkError();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    checkError();

    const qreal retinaScale = this->devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClearColor(0.0f, 0.0f, 0.0f, m_IsTransparent ? 0 : 1);
}


//-----------------------------------------------------------------------------
void OpenGLImage::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    checkError();

    glBindTexture(GL_TEXTURE_2D, m_texture_id); // Need to do this in the paintGL() call
    checkError();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    checkError();
}


//-----------------------------------------------------------------------------

void OpenGLImage::resizeGL(int width, int height)
{
}

//-----------------------------------------------------------------------------

void OpenGLImage::updateImage(QImage *image)
{
    QImage qimage2 = image->convertToFormat(QImage::Format_RGB888);
    int width = qimage2.width();
    int height = qimage2.height();
    const uchar* image_pointer = qimage2.bits();

    this->makeCurrent();
    glBindTexture(GL_TEXTURE_2D, m_texture_id);
    checkError();
    if (m_last_height != height || m_last_width != width) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_pointer);
    } else {
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, image_pointer);
    }
    m_last_width = width;
    m_last_height = height;
    checkError();
    update();
}

//-----------------------------------------------------------------------------

void OpenGLImage::checkError() {
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR) {
      qInfo() << "OpenGL Error:" << err;
    }
}



}
