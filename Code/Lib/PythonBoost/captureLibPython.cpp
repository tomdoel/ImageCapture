/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <boost/python.hpp>
#include "captureMyFunctions.h"

BOOST_PYTHON_MODULE(imagecapturepython)
{
  boost::python::def("my_first_add_function", capture::MyFirstAddFunction);
}
