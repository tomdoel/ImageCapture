#ifndef LabelImage_H
#define LabelImage_H

#include <QLabel>
#include "captureVideoOutput.h"

namespace capture {

class LabelImage : public QLabel, public VideoOutput
{
        Q_OBJECT
    public:
        explicit LabelImage(QWidget *parent = nullptr);

        QSize minimumSizeHint() const override;
        QSize sizeHint() const override;

        void updateImage(QImage* image) override;

    signals:

    public slots:
};

}

#endif // LabelImage_H
