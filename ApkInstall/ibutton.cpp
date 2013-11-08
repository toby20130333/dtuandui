#include "ibutton.h"

Ibutton::Ibutton(QWidget *parent) :
    QLabel(parent)
{
    MyLabelPressed = false;
}

Ibutton::~Ibutton()
{
}

void Ibutton::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit iclicked();
    }
}

void Ibutton::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit ireleased();
    }

}

void Ibutton::mouseMoveEvent(QMouseEvent *ev)
{
}

void Ibutton::enterEvent(QEvent *e)
{
    emit ienterd();
}

void Ibutton::leaveEvent(QEvent *e)
{
    emit iexited();
}
