#include "captureCameraWidget.h"

#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>

#include "captureVideoFileSurface.h"

namespace capture {

    CameraWidget::CameraWidget(const QCameraInfo& camera_info)
    {
        m_camera = std::unique_ptr<QCamera>(new QCamera(camera_info));

        m_video_file_surface = std::unique_ptr<VideoFileSurface>(new VideoFileSurface());
        m_camera->setViewfinder(m_video_file_surface.get());

        m_camera->start();
    }

    CameraWidget::~CameraWidget() {
    }

    void CameraWidget::addListener(VideoOutput *output)
    {
        m_video_file_surface->addListener(output);
    }

}
