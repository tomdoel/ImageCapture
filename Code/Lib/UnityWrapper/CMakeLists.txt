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

  set(IMAGECAPTURE_UNITY_NAME ${IMAGECAPTURE_LIBRARY_NAME}unity)

  set(IMAGECAPTURE_UNITY_SRCS
    captureUnityWrapper.cpp
  )

  set(IMAGECAPTURE_UNITY_HDRS
    captureUnityWrapper.h
  )

  # Thanks to: https://stackoverflow.com/questions/15120951/generating-a-bundle-file-with-cmake-on-mac-osx?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
  add_library(${IMAGECAPTURE_UNITY_NAME} MODULE ${IMAGECAPTURE_UNITY_HDRS} ${IMAGECAPTURE_UNITY_SRCS})
  if(APPLE)
    set_target_properties(${IMAGECAPTURE_UNITY_NAME} PROPERTIES BUNDLE TRUE)
  endif()

  target_link_libraries(${IMAGECAPTURE_UNITY_NAME} PRIVATE ${IMAGECAPTURE_LIBRARIES} ${ALL_THIRD_PARTY_LIBRARIES})
  install(TARGETS ${IMAGECAPTURE_UNITY_NAME} DESTINATION ${IMAGECAPTURE_INSTALL_LIB_DIR})

  if( NOT "${IMAGECAPTURE_UNITY_PLUGIN_DIR}" STREQUAL "")
    install(TARGETS ${IMAGECAPTURE_UNITY_NAME} DESTINATION ${IMAGECAPTURE_UNITY_PLUGIN_DIR})
  endif()

endif()
