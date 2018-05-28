#include "captureLabelImage.h"

namespace capture {

LabelImage::LabelImage(QWidget *parent) : QLabel(parent)
{
}


//-----------------------------------------------------------------------------
QSize LabelImage::minimumSizeHint() const
{
  return QSize(400, 300);
}


//-----------------------------------------------------------------------------
QSize LabelImage::sizeHint() const
{
    return QSize(400, 300);
}

void LabelImage::updateImage(QImage *image)
{
    resize(image->size());
    setPixmap(QPixmap::fromImage(*image));

    update();
}

}

