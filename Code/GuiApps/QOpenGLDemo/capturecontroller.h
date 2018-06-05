#pragma once

#include <QObject>
#include <memory>

namespace capture {

    class OutputDisplayController;
    class OpenGLMainWindow;
    class OutputDisplayController;
    class ScreenController;
    class ScreenMapper;

    class CaptureController : public QObject
    {
            Q_OBJECT
        public:
            CaptureController();
            ~CaptureController();

            void updateWindows();

        private:
            std::shared_ptr<OutputDisplayController> m_output_display_controller;
            std::shared_ptr<ScreenController> m_screen_controller;
            std::unique_ptr<ScreenMapper> m_screen_mapper;

        signals:
            void addCaptureOutput(OpenGLMainWindow*);
            void removeCaptureOutput(OpenGLMainWindow*);

        public slots:
            void screensChanged();
            void outputDisplaysChanged();
    };
}
