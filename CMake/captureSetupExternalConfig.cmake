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

configure_file(${CMAKE_SOURCE_DIR}/UseImageCapture.cmake.in ${CMAKE_BINARY_DIR}/UseImageCapture.cmake @ONLY IMMEDIATE)
configure_file(${CMAKE_SOURCE_DIR}/ImageCaptureConfig.cmake.in ${CMAKE_BINARY_DIR}/ImageCaptureConfig.cmake @ONLY IMMEDIATE)
if(NOT BUILDING_GUIS)
  install(FILES ${CMAKE_BINARY_DIR}/UseImageCapture.cmake DESTINATION . COMPONENT CONFIG)
  install(FILES ${CMAKE_BINARY_DIR}/ImageCaptureConfig.cmake DESTINATION . COMPONENT CONFIG)
endif()
