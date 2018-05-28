#include "captureCameraWidget.h"

#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>

#include "captureVideoFileSurface.h"

namespace capture {

CameraWidget::CameraWidget(QWidget *parent)// : QWidget(parent)
{
    QCamera *camera = new QCamera(QCameraInfo::availableCameras().at(0));
//    QCameraViewfinder *viewFinder = new QCameraViewfinder(this);
//    viewFinder->setGeometry(00,00,400,300);
//    viewFinder->show();
//    camera->setViewfinder(viewFinder);

    m_video_file_surface = new VideoFileSurface();
    camera->setViewfinder(m_video_file_surface);

    camera->start();
}

void CameraWidget::addListener(VideoOutput *output)
{
    m_video_file_surface->addListener(output);
}

}
