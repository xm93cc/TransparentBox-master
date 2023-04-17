#ifndef CATCHWINDOW_H
#define CATCHWINDOW_H

#include <QWidget>
#include <qpainter.h>

namespace Ui {
class CatchWindow;
}

class CatchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CatchWindow(QWidget *parent = nullptr);
    ~CatchWindow();
    void paintEvent(QPaintEvent *);

private:
    Ui::CatchWindow *ui;
};

#endif // CATCHWINDOW_H
