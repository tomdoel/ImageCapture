#include "captureCameraWidget.h"

#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>

#include "captureVideoFileSurface.h"

namespace capture {

CameraWidget::CameraWidget(const QCameraInfo& camera_info)
{
    QCamera *camera = new QCamera(camera_info);

    m_video_file_surface = new VideoFileSurface();
    camera->setViewfinder(m_video_file_surface);

    camera->start();
}

void CameraWidget::addListener(VideoOutput *output)
{
    m_video_file_surface->addListener(output);
}

}
