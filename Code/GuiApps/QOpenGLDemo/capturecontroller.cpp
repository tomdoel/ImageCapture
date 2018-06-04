#include "capturecontroller.h"

#include <QApplication>
#include <QDesktopWidget>
#include <algorithm>
#include <string>

#include "cameradetector.h"
#include "captureOpenGLWidget.h"
#include "captureOpenGLMainWindow.h"

namespace capture {

    CaptureController::CaptureController() : QObject() {
        m_output_display_controller = std::unique_ptr<OutputDisplayController>(new OutputDisplayController);
        connect(this, &CaptureController::addCaptureOutput, m_output_display_controller.get(), &OutputDisplayController::addCaptureOutput);
        connect(this, &CaptureController::removeCaptureOutput, m_output_display_controller.get(), &OutputDisplayController::removeCaptureOutput);
    }

    void CaptureController::updateWindows() {
        capture::CameraDetector detector;
        const std::map<QString, QCameraInfo> cameras = detector.getAllCameras();

        m_capture_windows.clear();

        for (std::map<QString, QCameraInfo>::const_iterator iter = cameras.begin(); iter != cameras.end(); iter++) {
            std::unique_ptr<OpenGLMainWindow> captureWindow(new OpenGLMainWindow(iter->second));
            emit addCaptureOutput(captureWindow.get());
            std::string id = (iter->first).toStdString();
            connect(captureWindow.get(), &OpenGLMainWindow::windowHasClosed, this, &CaptureController::WindowClosed);
            m_capture_windows[id] = std::move(captureWindow);
        }
    }

    void CaptureController::WindowClosed(QString id) {
        std::map<std::string, std::unique_ptr<capture::OpenGLMainWindow> >::iterator iter = m_capture_windows.find(id.toStdString());
        if (iter != m_capture_windows.end()) {
            emit removeCaptureOutput(iter->second.get());
            m_capture_windows.erase(iter);
        }
    }

    void CaptureController::screensChanged()
    {
        m_output_display_controller.get()->screensChanged();
    }
}
