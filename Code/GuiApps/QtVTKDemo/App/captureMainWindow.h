/*=============================================================================

  IMAGECAPTURE: A software package for capturing images from input devices and rendering to vide outputs.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef captureMainWindow_h
#define captureMainWindow_h

#include "ui_captureMainWindow.h"
#include <captureVolumeRenderingModel.h>

#include <QMainWindow>

namespace capture
{

class VTKViewWidget;

/**
* \class MainWindow
* \brief Demo Widget provides main window, and connects it to Model.
*/
class MainWindow : public QMainWindow, public Ui_MainWindow
{
  Q_OBJECT

public:

  MainWindow(capture::VolumeRenderingModel* model);
  virtual ~MainWindow();
  void ConnectRenderer();

private slots:

  void OnFileOpen();

private:

  capture::VolumeRenderingModel* m_Model;
  capture::VTKViewWidget*        m_Viewer;

}; // end class

} // end namespace

#endif
