/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef captureWin32ExportHeader_h
#define captureWin32ExportHeader_h

/**
* \file captureWin32ExportHeader.h
* \brief Header to sort Windows dllexport/dllimport.
*/

#if (defined(_WIN32) || defined(WIN32)) && !defined(IMAGECAPTURE_STATIC)
  #ifdef IMAGECAPTURE_WINDOWS_EXPORT
    #define IMAGECAPTURE_WINEXPORT __declspec(dllexport)
  #else
    #define IMAGECAPTURE_WINEXPORT __declspec(dllimport)
  #endif  /* IMAGECAPTURE_WINEXPORT */
#else
/* linux/mac needs nothing */
  #define IMAGECAPTURE_WINEXPORT
#endif

#endif
