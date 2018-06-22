#pragma once

#include <QObject>
#include <QScreen>
#include <QString>
#include <QCameraInfo>
#include <map>
#include <set>
#include <string>
#include <memory>

#include "captureOpenGLMainWindow.h"

namespace capture {

    class OpenGLMainWindow;

    class OutputDisplayController : public QObject
    {
            Q_OBJECT

        public:
            explicit OutputDisplayController(QObject *parent = nullptr);
            ~OutputDisplayController();

            std::map<std::string, std::unique_ptr<OpenGLMainWindow> > const& getCaptureWindows() const;

            void clearWindows();
            void createWindowForCamera(const QCameraInfo& camera_info);

        private:
            std::map<std::string, std::unique_ptr<OpenGLMainWindow> > m_capture_windows;

        private slots:
            void WindowClosed(QString id);

        signals:
            void outputDisplaysChanged();
    };
}
