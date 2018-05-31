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

set(IMAGECAPTURE_LIBRARY_NAME imagecapture)

set(IMAGECAPTURE_LIBRARY_SRCS
  captureBasicTypes.cpp
  captureMyFunctions.cpp
  captureException.cpp
)

set(IMAGECAPTURE_LIBRARY_HDRS
  captureExceptionMacro.h
)

add_library(${IMAGECAPTURE_LIBRARY_NAME} ${IMAGECAPTURE_LIBRARY_HDRS} ${IMAGECAPTURE_LIBRARY_SRCS})

if(BUILD_SHARED_LIBS)
  if(WIN32)
    add_definitions(-DIMAGECAPTURE_WINDOWS_EXPORT)
  endif(WIN32)
endif(BUILD_SHARED_LIBS)

target_link_libraries(${IMAGECAPTURE_LIBRARY_NAME} PRIVATE ${ALL_THIRD_PARTY_LIBRARIES})

IMAGECAPTURE_INSTALL_HEADERS()
IMAGECAPTURE_INSTALL_LIBRARY(${IMAGECAPTURE_LIBRARY_NAME})

add_subdirectory(CaptureLib)

if(BUILD_Python_Boost)
  add_subdirectory(PythonBoost)
endif()

if(BUILD_Python_PyBind)
  add_subdirectory(PythonPyBind)
endif()

if(BUILD_UNITY_WRAPPER)
  add_subdirectory(UnityWrapper)
endif()
