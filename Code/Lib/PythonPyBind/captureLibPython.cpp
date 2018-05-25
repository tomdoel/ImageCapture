/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <pybind11/pybind11.h>
#include "captureMyFunctions.h"

PYBIND11_MODULE(imagecapturepython, m) {
    m.doc() = "pybind11 example wrapping capture::MyFirstAddFunction";
    m.def("my_first_add_function", &capture::MyFirstAddFunction, "A function which adds two numbers");
}
