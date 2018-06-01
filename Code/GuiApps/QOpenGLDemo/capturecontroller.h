#pragma once

#include <map>
#include <memory>
#include "captureOpenGLMainWindow.h"

namespace capture {
    class CaptureController
    {
        public:
            CaptureController();
            void updateWindows();

        private:
            std::map<std::string, std::unique_ptr<capture::OpenGLMainWindow> > m_capture_windows;
    };

}

