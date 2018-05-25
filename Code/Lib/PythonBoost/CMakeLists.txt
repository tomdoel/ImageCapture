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

if(NOT BUILDING_GUIS)

  # if running pip install, IMAGECAPTURE_PYTHON_MODULE_NAME is passed in from setup.py
  # So, if its not specified, we just name it after the current library with a 'python' suffix.
  if (NOT IMAGECAPTURE_PYTHON_MODULE_NAME OR IMAGECAPTURE_PYTHON_MODULE_NAME STREQUAL "")
    set(IMAGECAPTURE_PYTHON_MODULE_NAME "${IMAGECAPTURE_LIBRARY_NAME}python")
  endif()

  set(IMAGECAPTURE_PYTHON_SRCS
    captureLibPython.cpp
  )

  link_libraries(${IMAGECAPTURE_LIBRARY_NAME})
  PYTHON_ADD_MODULE(${IMAGECAPTURE_PYTHON_MODULE_NAME} ${IMAGECAPTURE_PYTHON_SRCS})
  install(TARGETS ${IMAGECAPTURE_PYTHON_MODULE_NAME} DESTINATION ${IMAGECAPTURE_INSTALL_LIB_DIR})

endif()
