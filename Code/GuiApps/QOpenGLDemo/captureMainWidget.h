#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace capture {

class MainWidget : public QWidget
{
        Q_OBJECT
    public:
        explicit MainWidget(QWidget *parent = nullptr);

        QSize minimumSizeHint() const override;
        QSize sizeHint() const override;

    signals:

    public slots:
};

}

#endif // MAINWIDGET_H
