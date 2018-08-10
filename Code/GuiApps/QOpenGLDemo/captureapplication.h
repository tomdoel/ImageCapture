#pragma once

#include <QObject>
#include <QApplication>
#include <QScreen>
#include <memory>

namespace capture {
    class CaptureController;

    class CaptureApplication : public QObject
    {
            Q_OBJECT

        public:
            explicit CaptureApplication(int argc, char *argv[]);
            ~CaptureApplication();
            int run();

        private:
            std::unique_ptr<QApplication> m_app;
            std::unique_ptr<CaptureController> m_controller;
    };
}
