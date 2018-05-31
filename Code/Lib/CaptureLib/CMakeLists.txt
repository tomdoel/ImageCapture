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

set(IMAGECAPTURE_CAPTURELIB_NAME ${IMAGECAPTURE_LIBRARY_NAME}capturelib)

set(IMAGECAPTURE_CAPTURELIB_SRCS
    abstractimage.cpp
    image.cpp
    convert.cpp
)

set(IMAGECAPTURE_CAPTURELIB_HDRS
    abstractimage.h
    image.h
    convert.h
)

add_library(${IMAGECAPTURE_CAPTURELIB_NAME} MODULE ${IMAGECAPTURE_CAPTURELIB_HDRS} ${IMAGECAPTURE_CAPTURELIB_SRCS})

if(BUILD_SHARED_LIBS)
  if(WIN32)
    add_definitions(-DIMAGECAPTURE_WINDOWS_EXPORT)
  endif(WIN32)
endif(BUILD_SHARED_LIBS)

# Thanks to: https://stackoverflow.com/questions/15120951/generating-a-bundle-file-with-cmake-on-mac-osx?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
if(APPLE)
set_target_properties(${IMAGECAPTURE_CAPTURELIB_NAME} PROPERTIES BUNDLE TRUE)
endif()

target_link_libraries(${IMAGECAPTURE_CAPTURELIB_NAME} PRIVATE ${IMAGECAPTURE_LIBRARIES} ${ALL_THIRD_PARTY_LIBRARIES})

#install(TARGETS ${IMAGECAPTURE_CAPTURELIB_NAME} DESTINATION ${IMAGECAPTURE_INSTALL_LIB_DIR})
IMAGECAPTURE_INSTALL_LIBRARY(${IMAGECAPTURE_CAPTURELIB_NAME})

