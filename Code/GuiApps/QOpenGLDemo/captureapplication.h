#pragma once

#include <QObject>
#include <QApplication>
#include <QScreen>

namespace capture {
    class CaptureApplication : public QObject
    {
            Q_OBJECT

        public:
            explicit CaptureApplication(int argc, char *argv[]);
            ~CaptureApplication();
            int run();

        private:
            std::unique_ptr<QApplication> m_app;
            void updateScreens();

        signals:
            void screensChanged();

        public slots:
            void addScreen(QScreen* screen);
            void removeScreen(QScreen* screen);

    };
}
