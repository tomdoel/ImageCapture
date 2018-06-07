#pragma once

#include <QWidget>
#include <QCameraInfo>

namespace capture {

    class VideoFileSurface;
    class VideoOutput;

    class CameraWidget
    {
        public:
            explicit CameraWidget(const QCameraInfo& camera_info);

            void addListener(VideoOutput*);

        private:
            VideoFileSurface *m_video_file_surface;
    };

}
