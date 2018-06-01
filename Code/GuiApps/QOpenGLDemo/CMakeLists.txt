#/*============================================================================
#
#  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

set(APP_NAME QOpenGLDemo)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

set(APP_UIS
)

set(APP_SRCS
  captureOpenGLWidget.cpp
  captureOpenGLMainWindow.cpp
  captureMainWidget.cpp
  captureCameraWidget.cpp
  captureOpenGLImage.cpp
  captureVideoFileSurface.cpp
  captureLabelImage.cpp
  captureVideoOutput.cpp
  qvideoframewrapper.cpp
  cameradetector.cpp
  capturecontroller.cpp
)

set(APP_MOC_HDRS
  captureOpenGLWidget.h
  captureMainWidget.h
  captureCameraWidget.h
  captureOpenGLImage.h
  captureVideoFileSurface.h
  captureLabelImage.h
  captureVideoOutput.h
)

set(APP_HDRS
  captureOpenGLMainWindow.h
  qvideoframewrapper.h
  cameradetector.h
  capturecontroller.h
)

set(APP_RES
)

qt5_wrap_ui(QT5_UIS ${APP_UIS})
qt5_wrap_cpp(QT5_MOCS ${APP_MOC_HDRS})
qt5_add_resources(QT5_RES ${APP_RES})

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${APP_NAME} MACOSX_BUNDLE
  ${APP_SRCS}
  ${APP_HDRS}
  ${QT5_UIS}
  ${QT5_MOCS}
  ${QT5_RES}
  main.cpp
)

set(APP_LIBS
  ${OPENGL_LIBRARIES}
)

target_link_libraries(${APP_NAME} ${APP_LIBS} ${ALL_THIRD_PARTY_LIBRARIES} ${QT5_LINK_LIBRARIES})
captureMacroCreateGuiApplication(${APP_NAME} "${ADDITIONAL_SEARCH_PATHS}")

