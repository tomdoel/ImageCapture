#ifndef VIDEOOUTPUT_H
#define VIDEOOUTPUT_H

#include <QImage>

namespace capture {

class VideoOutput
{
    public:
        virtual void updateImage(QImage* image) = 0;
};

}

#endif // VIDEOOUTPUT_H
