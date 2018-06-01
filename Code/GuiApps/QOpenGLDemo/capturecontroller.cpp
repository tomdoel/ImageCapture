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
            std::unique_ptr<capture::OpenGLMainWindow> captureWindow(new capture::OpenGLMainWindow(iter->second));
            std::string id = (iter->first).toStdString();
            m_capture_windows[id] = std::move(captureWindow);
        }
    }
}
