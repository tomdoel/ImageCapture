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

macro(IMAGECAPTURE_INSTALL_LIBRARY)

  set(ARGS ${ARGN})
  set(install_directories "")
  list(FIND ARGS DESTINATION _destination_index)
  if(_destination_index GREATER -1)
    message(SEND_ERROR "IMAGECAPTURE_INSTALL_LIBRARAY macro must not be called with a DESTINATION parameter.")
  else()

    if(NOT BUILDING_GUIS)
        install(TARGETS ${ARGS}
                ARCHIVE DESTINATION ${IMAGECAPTURE_INSTALL_LIB_DIR}
                LIBRARY DESTINATION ${IMAGECAPTURE_INSTALL_LIB_DIR}
                RUNTIME DESTINATION ${IMAGECAPTURE_INSTALL_BIN_DIR}
               )
     endif()

  endif()
endmacro()
