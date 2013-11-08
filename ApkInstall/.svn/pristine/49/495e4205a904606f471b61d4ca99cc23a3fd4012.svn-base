#ifndef IBUTTON_H
#define IBUTTON_H

#include <QLabel>
#include <QMouseEvent>

class Ibutton : public QLabel
{
    Q_OBJECT
public:
    explicit Ibutton(QWidget *parent = 0);
    ~Ibutton();

private:
    bool MyLabelPressed;
protected:
    void mousePressEvent ( QMouseEvent * e );
    void mouseReleaseEvent ( QMouseEvent * e );
    void mouseMoveEvent(QMouseEvent *ev);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);
    
signals:
    void iclicked();
    void ireleased();
    void ienterd();
    void iexited();
    
    
};

#endif // IBUTTON_H
