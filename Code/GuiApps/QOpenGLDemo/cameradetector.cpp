#include "cameradetector.h"

#include <QCameraInfo>

namespace capture {
    CameraDetector::CameraDetector() {
        update();
    }

    const std::map<QString, QCameraInfo> CameraDetector::getAllCameras() const {
        return m_cameras;
    }

    void CameraDetector::update() {
        m_cameras.clear();
        QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
        for (QList<QCameraInfo>::iterator iter = cameras.begin(); iter != cameras.end(); iter++) {
            m_cameras[iter->deviceName()] = (*iter);
        }
    }

}
