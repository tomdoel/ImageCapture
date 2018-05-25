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

#########################
# Put .cpp files here.
#########################
set(QTVTKCONTROLLER_SRCS
  captureVolumeRenderingModel.cpp
)


###################################
# Put .h files that need moc here.
###################################
SET(QTVTKCONTROLLER_MOC_HDRS
  captureVolumeRenderingModel.h
)


##########################################
# Put .h files that do not need moc here.
##########################################
SET(QTVTKCONTROLLER_HDRS
  captureQtVTKModelWin32ExportHeader.h
)


#########################
# Resource file.
#########################
SET(QTVTKCONTROLLER_RES
)


################################
# Qt commands provided by CMake.
################################
qt5_wrap_cpp(QT5_MOCS ${QTVTKCONTROLLER_MOC_HDRS} )
qt5_add_resources(QT5_RES ${QTVTKCONTROLLER_RES})

################################
# Bundle it all together.
################################
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(qtvtkmodel
  ${QTVTKCONTROLLER_SRCS}
  ${QTVTKCONTROLLER_HDRS}
  ${QT5_MOCS}
  ${QT5_RES}
)


#################################
# Stuff for windows shared libs.
#################################
if(BUILD_SHARED_LIBS)
  if(WIN32)
    add_definitions(-DIMAGECAPTURE_QTVTKMODEL_WINDOWS_EXPORT)
  endif(WIN32)
  IMAGECAPTURE_INSTALL_LIBRARY(qtvtkmodel)
endif(BUILD_SHARED_LIBS)


#################################
# Link the library.
#################################
target_link_libraries(qtvtkmodel PRIVATE ${QT5_LINK_LIBRARIES} ${ALL_THIRD_PARTY_LIBRARIES})

