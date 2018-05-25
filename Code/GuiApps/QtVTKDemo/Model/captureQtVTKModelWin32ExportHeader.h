/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef captureQtVTKModelWin32ExportHeader_h
#define captureQtVTKModelWin32ExportHeader_h

/**
* \file captureQtVTKModelWin32ExportHeader.h
* \brief Header to sort Windows dllexport/dllimport.
*/

#if (defined(_WIN32) || defined(WIN32)) && !defined(IMAGECAPTURE_STATIC)
  #ifdef IMAGECAPTURE_QTVTKMODEL_WINDOWS_EXPORT
    #define IMAGECAPTURE_QTVTKMODELWINEXPORT __declspec(dllexport)
  #else
    #define IMAGECAPTURE_QTVTKMODELWINEXPORT __declspec(dllimport)
  #endif
#else
  #define IMAGECAPTURE_QTVTKMODELWINEXPORT
#endif

#endif
