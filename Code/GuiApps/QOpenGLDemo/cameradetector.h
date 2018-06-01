#pragma once

#include <map>
#include <QCameraInfo>
#include <QString>

namespace capture {

    class CameraDetector
    {
        public:
            CameraDetector();
            const std::map<QString, QCameraInfo> getAllCameras() const;

        private:
            void update();
            std::map<QString, QCameraInfo> m_cameras;
    };

}
