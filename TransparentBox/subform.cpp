#include "subform.h"
#include "ui_subform.h"
#include <QPainter>
#include <qdebug.h>
SubForm::SubForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubForm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);//去掉标题栏
    setAttribute(Qt::WA_TranslucentBackground, true);//设置窗口背景透明
    //setWindowFlags(Qt::FramelessWindowHint);
}


void SubForm::paintEvent(QPaintEvent *)
{
    // 画一条直线
    QPainter painter(this);             // 创建QPainter一个对象
    QPen pen;
    // 画一个空心矩形
    pen.setColor("#33ff66");
    pen.setWidth(5);
    painter.setPen(pen);


    painter.drawRect(1, 1, this->geometry().width() -3,this->geometry().height() -8);
    //painter.drawRect(QRect(1, 1, 100, 100));
    //qDebug() << this->x() <<"\t"<<  this->y() << '\n';
}

SubForm::~SubForm()
{
    delete ui;
}
