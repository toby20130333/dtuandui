#ifndef LABPERMISSION_H
#define LABPERMISSION_H

#include <QWidget>
#include <QLabel>
#include <QMap>

class labPermission : public QWidget
{
    Q_OBJECT
public:
    explicit labPermission(QWidget *parent = 0);

    int addItem(QStringList);
    QString changeToText(QString);

private:

    QFont textfont;
    int itemHeight;
    int itemWidth;
    int xPos;
    int yPos;
    
signals:
    
public slots:
private:
   QMap<QString,QString> map;
    
};

#endif // LABPERMISSION_H
