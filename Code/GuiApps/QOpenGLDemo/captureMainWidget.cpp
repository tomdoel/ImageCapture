#include "captureMainWidget.h"

namespace capture {

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{

}


//-----------------------------------------------------------------------------
QSize MainWidget::minimumSizeHint() const
{
  return QSize(600, 900);
}


//-----------------------------------------------------------------------------
QSize MainWidget::sizeHint() const
{
  return QSize(600, 900);
}

}

