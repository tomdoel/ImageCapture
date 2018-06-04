#pragma once

#include <QObject>
#include <map>
#include <memory>
#include "captureOpenGLMainWindow.h"
#include "outputdisplaycontroller.h"

namespace capture {

    class OutputDisplayController;

    class CaptureController : public QObject
    {
            Q_OBJECT
        public:
            CaptureController();
            void updateWindows();

        private:
            std::map<std::string, std::unique_ptr<OpenGLMainWindow> > m_capture_windows;
            std::unique_ptr<OutputDisplayController> m_output_display_controller;

        signals:
            void addCaptureOutput(OpenGLMainWindow*);
            void removeCaptureOutput(OpenGLMainWindow*);

        public slots:
            void WindowClosed(QString id);
            void screensChanged();
    };

}

