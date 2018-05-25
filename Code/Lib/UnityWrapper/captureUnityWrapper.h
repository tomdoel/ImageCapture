/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/
/**
* \file captureUnityWrapper.h
* \brief Wrapper for Unity3D to load simple functionality as plugin.
* \ingroup utilities
*
* Note: this example is based on:
* https://docs.unity3d.com/Manual/PluginsForDesktop.html
*
* For a more advanced plugin see:
* https://docs.unity3d.com/Manual/NativePluginInterface.html
*/

/**
 * Unity plugin's must have C-style linkage to avoid name mangling.
 */
extern "C" {

/**
 * \brief C-style wrapper for capture::MyFirstAddFunction
 */
int AddTwoIntegers(int a, int b);

}
