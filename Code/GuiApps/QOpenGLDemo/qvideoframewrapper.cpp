#include "qvideoframewrapper.h"

#include "qvideoframe.h"

QVideoFrameWrapper::QVideoFrameWrapper(const QVideoFrame &frame):
    m_width(frame.width()), m_height(frame.height())
{
    m_frame = QVideoFrame(frame);

    if(!m_frame.map(QAbstractVideoBuffer::ReadOnly))
    {
        // error
    }

    m_data = m_frame.bits();
}

QVideoFrameWrapper::~QVideoFrameWrapper() {
    m_frame.unmap();
}

int QVideoFrameWrapper::width() const
{
    return m_width;
}

int QVideoFrameWrapper::height() const
{
    return m_height;
}

unsigned char *QVideoFrameWrapper::data() const
{
    return m_data;
}
