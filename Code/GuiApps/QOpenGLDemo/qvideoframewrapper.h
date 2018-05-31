#pragma once

#include "CaptureLib/abstractimage.h"

#include <QVideoFrame>

class QVideoFrameWrapper : public cl::AbstractImage
{
    public:
        QVideoFrameWrapper(const QVideoFrame &frame);
        virtual ~QVideoFrameWrapper();

        // AbstractImage interface
    public:
        int width() const;
        int height() const;
        unsigned char *data() const;

    private:
        QVideoFrame m_frame;
        int m_width;
        int m_height;
        unsigned char* m_data;
};

