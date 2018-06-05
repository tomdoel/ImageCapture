#include "outputdisplaycontroller.h"

namespace capture {
    OutputDisplayController::OutputDisplayController(QObject *parent) : QObject(parent) {
    }

    OutputDisplayController::~OutputDisplayController() {
    }

    std::map<std::string, std::unique_ptr<OpenGLMainWindow> > const& OutputDisplayController::getCaptureWindows() const
    {
        return m_capture_windows;
    }

    void OutputDisplayController::clearWindows() {
        m_capture_windows.clear();
        emit outputDisplaysChanged();
    }

    void OutputDisplayController::createWindowForCamera(const QCameraInfo& camera_info) {
        std::unique_ptr<OpenGLMainWindow> captureWindow(new OpenGLMainWindow(camera_info));
        std::string id = camera_info.deviceName().toStdString();
        connect(captureWindow.get(), &OpenGLMainWindow::windowHasClosed, this, &OutputDisplayController::WindowClosed);
        m_capture_windows[id] = std::move(captureWindow);
        emit outputDisplaysChanged();
    }

    void OutputDisplayController::WindowClosed(QString id) {
        std::map<std::string, std::unique_ptr<OpenGLMainWindow> >::iterator iter = m_capture_windows.find(id.toStdString());
        if (iter != m_capture_windows.end()) {
            m_capture_windows.erase(iter);
            emit outputDisplaysChanged();
        }
    }
}
