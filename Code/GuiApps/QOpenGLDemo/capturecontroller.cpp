#include "capturecontroller.h"

#include <QApplication>
#include <QDesktopWidget>
#include "cameradetector.h"
#include "captureOpenGLWidget.h"

namespace capture {
    CaptureController::CaptureController() {
    }

    void CaptureController::updateWindows() {
        capture::CameraDetector detector;
        const std::map<QString, QCameraInfo> cameras = detector.getAllCameras();

        m_capture_windows.clear();

        for (std::map<QString, QCameraInfo>::const_iterator iter = cameras.begin(); iter != cameras.end(); iter++) {
            std::unique_ptr<capture::OpenGLMainWindow> mainWindow(new capture::OpenGLMainWindow(iter->second));
            capture::OpenGLWidget::setTransparent(false);
            if (capture::OpenGLWidget::isTransparent())
            {
                mainWindow->setAttribute(Qt::WA_TranslucentBackground);
                mainWindow->setAttribute(Qt::WA_NoSystemBackground, false);
            }
            mainWindow->resize(mainWindow->sizeHint());
            int desktopArea = QApplication::desktop()->width() *
                    QApplication::desktop()->height();
            int widgetArea = mainWindow->width() * mainWindow->height();
            if (((float)widgetArea / (float)desktopArea) < 0.75f)
            {
                mainWindow->show();
            }
            else
            {
                mainWindow->showMaximized();
            }
            std::string id = (iter->first).toStdString();
            m_capture_windows[id] = std::move(mainWindow);
        }
    }
}
