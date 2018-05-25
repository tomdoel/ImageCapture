/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef captureQtVTKControllerWin32ExportHeader_h
#define captureQtVTKControllerWin32ExportHeader_h

/**
* \file captureQtVTKControllerWin32ExportHeader.h
* \brief Header to sort Windows dllexport/dllimport.
*/

#if (defined(_WIN32) || defined(WIN32)) && !defined(IMAGECAPTURE_STATIC)
  #ifdef IMAGECAPTURE_QTVTKCONTROLLER_WINDOWS_EXPORT
    #define IMAGECAPTURE_QTVTKCONTROLLERWINEXPORT __declspec(dllexport)
  #else
    #define IMAGECAPTURE_QTVTKCONTROLLERWINEXPORT __declspec(dllimport)
  #endif
#else
  #define IMAGECAPTURE_QTVTKCONTROLLERWINEXPORT
#endif

#endif
