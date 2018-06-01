#include "captureVideoFileSurface.h"
#include <QPixmap>
#include <iterator>
#include "CaptureLib/convert.h"
#include "qvideoframewrapper.h"

namespace capture {

VideoFileSurface::VideoFileSurface()
{
}

QList<QVideoFrame::PixelFormat> VideoFileSurface::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType handleType) const
{
    if (handleType == QAbstractVideoBuffer::NoHandle) {
        return QList<QVideoFrame::PixelFormat>()
                << QVideoFrame::Format_RGB24;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }
}

bool VideoFileSurface::present(const QVideoFrame &frame)
{

    QVideoFrameWrapper frametodraw(frame);

    // Convert from UYVY to RGB
    QImage* image = convert(frametodraw);

    for(std::list<VideoOutput*>::iterator iter = m_video_outputs.begin(); iter != m_video_outputs.end(); iter++) {
        (*iter)->updateImage(image);
    }

    // Delete the allocated QImage object
    delete image;

    return true;
}

void VideoFileSurface::addListener(VideoOutput *output)
{
    m_video_outputs.push_back(output);
}


QImage* VideoFileSurface::convert(cl::AbstractImage& frame) {

    int width = frame.width();
    int height = frame.height();

    unsigned char* rgb_image = new unsigned char[width * height * 3]; //width and height of the image to be converted

    unsigned char* uyuy_image = frame.data(); // Frame is already mapped
    int y;
    int cr;
    int cb;

    double r;
    double g;
    double b;

    for (int i = 0, j = 0; i < width * height * 3; i+=6, j+=4) {
        // pixel 1
        y = uyuy_image[j+1];
        cb = uyuy_image[j];
        cr = uyuy_image[j+2];

        r = y + (1.4065 * (cr - 128));
        g = y - (0.3455 * (cb - 128)) - (0.7169 * (cr - 128));
        b = y + (1.7790 * (cb - 128));

        // Clipping
        if (r < 0) r = 0;
        else if (r > 255) r = 255;
        if (g < 0) g = 0;
        else if (g > 255) g = 255;
        if (b < 0) b = 0;
        else if (b > 255) b = 255;

        rgb_image[i] = (unsigned char)r;
        rgb_image[i+1] = (unsigned char)g;
        rgb_image[i+2] = (unsigned char)b;

        // pixel 2
        y = uyuy_image[j+3];
        cb = uyuy_image[j];
        cr = uyuy_image[j+2];

        r = y + (1.4065 * (cr - 128));
        g = y - (0.3455 * (cb - 128)) - (0.7169 * (cr - 128));
        b = y + (1.7790 * (cb - 128));

        if (r < 0) r = 0;
        else if (r > 255) r = 255;
        if (g < 0) g = 0;
        else if (g > 255) g = 255;
        if (b < 0) b = 0;
        else if (b > 255) b = 255;

        rgb_image[i+3] = (unsigned char)r;
        rgb_image[i+4] = (unsigned char)g;
        rgb_image[i+5] = (unsigned char)b;
    }

    QImage *image = new QImage(rgb_image, width, height, QImage::Format_RGB888);
    return image;
}

}

