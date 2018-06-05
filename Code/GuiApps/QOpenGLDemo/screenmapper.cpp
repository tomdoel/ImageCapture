#include "screenmapper.h"

#include "outputdisplaycontroller.h"
#include "screencontroller.h"
#include "captureOpenGLMainWindow.h"

namespace capture {
    ScreenMapper::ScreenMapper(std::shared_ptr<OutputDisplayController> output_display_controller, std::shared_ptr<ScreenController> screen_controller)
        : m_output_display_controller(output_display_controller), m_screen_controller(screen_controller) {
    }

    ScreenMapper::~ScreenMapper() {
    }

    void ScreenMapper::orderScreens()
    {
        const std::pair<QScreen*, std::set<QScreen*> > screens = m_screen_controller->getScreens();

        QScreen* primary = screens.first;
        const std::set<QScreen*> other_screens = screens.second;

        std::set<QScreen*>::const_iterator screen_iter = other_screens.begin();

        const std::map<std::string, std::unique_ptr<OpenGLMainWindow> >& capture_windows = m_output_display_controller->getCaptureWindows();

        for (std::map<std::string, std::unique_ptr<OpenGLMainWindow> >::const_iterator capture_window_iter = capture_windows.begin(); capture_window_iter != capture_windows.end(); capture_window_iter++) {
            OpenGLMainWindow* window_pointer = capture_window_iter->second.get();
            if (screen_iter == other_screens.end()) {
                window_pointer->setScreen(primary);
            } else {
                window_pointer->setScreen(*screen_iter);
                screen_iter++;
            }
        }
    }
}
