ImageCapture
------------

[![Build Status](https://travis-ci.org/TomDoel/ImageCapture.svg?branch=master)](https://travis-ci.org/TomDoel/ImageCapture)


This is a simple test/prototype application for displaying video from capture devices (such as webcams) and displaying as on OpenGL texture with an example OpenGL overlay.
If you have multiple capture devices and multiple output monitors, it should display each input full-screen on a separate monitor.


Requirements
------------

Some basic knowledge of CMake, QT and building C++ code is required.

You need the following in order to compile this project:

 * CMake (testing used 3.11.0)
 * QT (tested using 5.10.1)
 * A suitable C++ compiler, eg. gcc (linux), XCode (macOS), Visual Studio (Windows)



 Building
 --------

You can configure a build with CMake. CMake is cross-platform and allows you to generate a project for your preferred compiler/IDE.
Some IDEs (such as QT Creator) will import CMakeLists.txt files directly, and will run the CMake step for you.

To compile using QT Creator (tested using QT 5.10.1, QT Creator 4.6.0, macOS High Sierra):
 * Start QT Creator
 * Open Project and choose the root level CMakeLists.txt files
 * In you don't have a QT kit configured, configure it now.
 * Select your QT kit and click Configure project
 * Click on "Projects" n the left bar. This will show you the CMake variables which you can change as required - in almost all cases you can leave them as the defaults.
 * Under *Build Settings*:
   * Set your build folder. This is where the intermediate and binary files will go. Keep this in a separate directory to your source files
   * If the `QT5_DIR` is not found, then you can set the `CMAKE_PREFIX_PATH` variable to point to your QT installation. To do this, click Advanced to show the `CMAKE_PREFIX_PATH` variable (or create it if it doesn't exist) and set to the folder containing your QT installation. This should point to the subfolder containing the platform name, e.g. if your QT is installed under `/somewhere/Qt/5.10.1` then on macOS the path would be `/somewhere/5.10.1/clang_64`
   * Click Apply configuration changes if required
   * Fix any CMake issues (highlighted in red)
 * Under *Run Settings*
   * Change *Run Configuration* to QOpenGlDemo
 * Build the project

Credits
-------

The ImageCapture project was created by Tom Doel at the WEISS centre, UCL.

The project was originally built using [Matt Clarkson's CMakeCatchTemplate template](https://github.com/MattClarkson/CMakeCatchTemplate). This was based on work by Matt Clarkson and James Hetherington at UCL.



Licence
-------
Please see LICENSE.txt
