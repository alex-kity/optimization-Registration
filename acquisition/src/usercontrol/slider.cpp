#include "slider.h"
#include "qevent.h"

Slider::Slider(QWidget *parent) : QSlider(parent)
{
}

void Slider::mousePressEvent(QMouseEvent *event)
{
    //注意应先调用父类的鼠标点击处理事件,这样可以不影响拖动的情况
    QSlider::mousePressEvent(event);

    //获取鼠标的位置
    double pos = event->pos().x() / (double)width();
    double value = pos * (maximum() - minimum()) + minimum();
    setValue(value + 0.5);

    //发送自定义的鼠标单击信号
    emit clicked();
}
