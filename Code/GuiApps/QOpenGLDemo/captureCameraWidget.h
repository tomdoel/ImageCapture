#ifndef CameraWidget_H
#define CameraWidget_H

#include <QWidget>
#include "captureVideoOutput.h"
#include "captureVideoFileSurface.h"

namespace capture {

class CameraWidget
{
    public:
        explicit CameraWidget(QWidget *parent = nullptr);

        void addListener(VideoOutput*);

    private:
        VideoFileSurface *m_video_file_surface;
};

}

#endif // CameraWidget_H
