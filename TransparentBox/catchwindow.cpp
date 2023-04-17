#include "catchwindow.h"
#include "ui_catchwindow.h"


CatchWindow::CatchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CatchWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);//去掉标题栏
    setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明
}

CatchWindow::~CatchWindow()
{
    delete ui;
}

void CatchWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    // 画一个空心矩形
    pen.setColor("#33ff66");
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawRect(1, 1, this->geometry().width() -3,this->geometry().height() -8);
}
