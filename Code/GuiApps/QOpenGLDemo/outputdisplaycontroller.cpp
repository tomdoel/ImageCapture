#include "outputdisplaycontroller.h"

#include <QGuiApplication>

namespace capture {
    OutputDisplayController::OutputDisplayController(QObject *parent) : QObject(parent)
    {
        orderScreens();
    }

    OutputDisplayController::~OutputDisplayController() {

    }

    void OutputDisplayController::screensChanged()
    {
        orderScreens();
    }

    void OutputDisplayController::orderScreens()
    {
        QList<QScreen*> screens = QGuiApplication::screens();
        QScreen* primary = QGuiApplication::primaryScreen();
        screens.removeAll(primary);

        QList<QScreen*>::const_iterator screen_iter = screens.begin();
        for (std::set<OpenGLMainWindow*>::iterator capture_window_iter = m_capture_windows.begin(); capture_window_iter != m_capture_windows.end(); capture_window_iter++) {
            if (screen_iter == screens.end()) {
                (*capture_window_iter)->setScreen(primary);
            } else {
                (*capture_window_iter)->setScreen(*screen_iter);
                screen_iter++;
            }
        }
    }

    void OutputDisplayController::addCaptureOutput(OpenGLMainWindow * capture_window)
    {
        m_capture_windows.insert(capture_window);
        orderScreens();
    }

    void OutputDisplayController::removeCaptureOutput(OpenGLMainWindow *capture_window)
    {
        m_capture_windows.erase(capture_window);
        orderScreens();
    }

    void OutputDisplayController::addScreen(QScreen *)
    {

    }

    void OutputDisplayController::removeScreen(QScreen *)
    {

    }
}
