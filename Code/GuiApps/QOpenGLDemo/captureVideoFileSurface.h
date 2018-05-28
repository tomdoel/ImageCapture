#ifndef VIDEOFILESURFACE_H
#define VIDEOFILESURFACE_H

#include <QAbstractVideoSurface>
#include "captureVideoFileSurface.h"
#include <list>
#include "captureVideoOutput.h"

namespace capture {

class VideoFileSurface : public QAbstractVideoSurface
{
    public:
        VideoFileSurface();

        QList<QVideoFrame::PixelFormat> supportedPixelFormats(
                QAbstractVideoBuffer::HandleType handleType) const;
        bool present(const QVideoFrame &frame);

        void addListener(VideoOutput*);

    private:
        QImage* convert(QVideoFrame& frame);
        std::list<VideoOutput*> m_video_outputs;
};

}

#endif // VIDEOFILESURFACE_H
