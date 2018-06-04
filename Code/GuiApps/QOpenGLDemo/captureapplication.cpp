#include "captureapplication.h"

#include <QSurfaceFormat>
#include "capturecontroller.h"
#include "ImageCaptureConfigure.h"

namespace capture {
    CaptureApplication::CaptureApplication(int argc, char *argv[]) : QObject()
    {
        m_app = std::unique_ptr<QApplication>(new QApplication(argc, argv));
        m_app->setOrganizationName("UCL");
        m_app->setApplicationName("QOpenGLDemo");
        m_app->setApplicationVersion(QString(IMAGECAPTURE_VERSION_STRING));

        capture::CaptureController controller;

        QSurfaceFormat fmt;
        fmt.setDepthBufferSize(24);
        fmt.setVersion(3, 2);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
        QSurfaceFormat::setDefaultFormat(fmt);

        this->connect(m_app.get(), &QGuiApplication::screenAdded, this, &CaptureApplication::addScreen);
        this->connect(m_app.get(), &QGuiApplication::screenRemoved, this, &CaptureApplication::removeScreen);

        this->connect(this, &CaptureApplication::screensChanged, &controller, &CaptureController::screensChanged);
        controller.updateWindows();
    }

    CaptureApplication::~CaptureApplication() {
    }

    int CaptureApplication::run() {
        return m_app->exec(); // ToDo: Delete m_app and implement abouttoquit
    }

    void CaptureApplication::updateScreens()
    {
    }

    void CaptureApplication::addScreen(QScreen *screen)
    {
        emit screensChanged();
    }

    void CaptureApplication::removeScreen(QScreen *screen)
    {
        emit screensChanged();
    }
}
