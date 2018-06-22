#pragma once

#include <memory>
#include <QWidget>
#include <QCameraInfo>

namespace capture {

    class VideoFileSurface;
    class VideoOutput;

    class CameraWidget
    {
        public:
            explicit CameraWidget(const QCameraInfo& camera_info);
            ~CameraWidget();

            void addListener(VideoOutput*);

        private:
            std::unique_ptr<VideoFileSurface> m_video_file_surface;
            std::unique_ptr<QCamera> m_camera;
    };

}
