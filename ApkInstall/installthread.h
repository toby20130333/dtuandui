#ifndef INSTALLTHREAD_H
#define INSTALLTHREAD_H

#include <QThread>
#include <QProcess>
#include <QObject>
#include "cmstring.h"

class InstallThread : public QThread
{
    Q_OBJECT
public:
    explicit InstallThread(QObject *parent = 0);
    ~InstallThread();
    void setCmd(QString, QString, QString,QString);

    QString homePath;
    QString apkPath;
    QString adbPath;
    QString installModel;
    QString status;
    QString strPackageName;

    void readSetup(QString);
    void readReInstall(QString);
    void readADB(QString);
    bool repeatInstall(QString);

protected:
    void run();

signals:
    void signalEmitRes(QString,int);
    void signalInstall();

private slots:
    void slotInstall();



};

#endif // INSTALLTHREAD_H
