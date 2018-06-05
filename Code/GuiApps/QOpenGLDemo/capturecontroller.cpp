#include "capturecontroller.h"

#include <QApplication>
#include <QDesktopWidget>
#include <algorithm>
#include <string>

#include "cameradetector.h"
#include "captureOpenGLWidget.h"
#include "captureOpenGLMainWindow.h"
#include "screencontroller.h"
#include "screenmapper.h"
#include "outputdisplaycontroller.h"

namespace capture {

    CaptureController::CaptureController() : QObject() {

        m_output_display_controller = std::make_shared<OutputDisplayController>();
        m_screen_controller = std::make_shared<ScreenController>();
        m_screen_mapper = std::unique_ptr<ScreenMapper>(new ScreenMapper(m_output_display_controller, m_screen_controller));
        connect(m_output_display_controller.get(), &OutputDisplayController::outputDisplaysChanged, this, &CaptureController::outputDisplaysChanged);

        m_screen_mapper->orderScreens();
    }

    CaptureController::~CaptureController() {
    }

    void CaptureController::updateWindows() {
        capture::CameraDetector detector;
        const std::map<QString, QCameraInfo> cameras = detector.getAllCameras();

        m_output_display_controller->clearWindows();
        for (std::map<QString, QCameraInfo>::const_iterator iter = cameras.begin(); iter != cameras.end(); iter++) {
            m_output_display_controller->createWindowForCamera(iter->second);
        }
    }

    void CaptureController::outputDisplaysChanged()
    {
        m_screen_mapper->orderScreens();
    }

    void CaptureController::screensChanged()
    {
        m_screen_mapper->orderScreens();
    }
}
