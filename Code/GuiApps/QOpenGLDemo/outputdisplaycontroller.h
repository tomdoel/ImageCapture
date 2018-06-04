#pragma once

#include <QObject>
#include <QScreen>
#include "captureOpenGLMainWindow.h"
#include <set>

namespace capture {
    class OutputDisplayController : public QObject
    {
            Q_OBJECT

        public:
            explicit OutputDisplayController(QObject *parent = nullptr);
            ~OutputDisplayController();

            void screensChanged();

        private:
            void orderScreens();

            std::set<OpenGLMainWindow*> m_capture_windows;

        signals:

        public slots:
            void addCaptureOutput(OpenGLMainWindow*);
            void removeCaptureOutput(OpenGLMainWindow*);
            void addScreen(QScreen*);
            void removeScreen(QScreen*);
    };

}
