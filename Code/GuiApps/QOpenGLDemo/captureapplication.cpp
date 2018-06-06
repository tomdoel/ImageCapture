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

        QSurfaceFormat fmt;
        fmt.setDepthBufferSize(24);
        fmt.setVersion(3, 2);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
        QSurfaceFormat::setDefaultFormat(fmt);

        m_controller = std::unique_ptr<CaptureController>(new CaptureController());
        this->connect(m_app.get(), &QGuiApplication::screenAdded, m_controller.get(), &CaptureController::screensChanged);
        this->connect(m_app.get(), &QGuiApplication::screenRemoved, m_controller.get(), &CaptureController::screensChanged);

        m_controller->updateWindows();
    }

    CaptureApplication::~CaptureApplication() {
    }

    int CaptureApplication::run() {
        return m_app->exec(); // ToDo: Delete m_app and implement abouttoquit
    }
}
