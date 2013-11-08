#ifndef GETAPKINFOTHREAD_H
#define GETAPKINFOTHREAD_H

#include <QProcess>
#include <QThread>
#include <Qdir>
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>

class GetApkInfoThread: public QThread
{
    Q_OBJECT
public:
    explicit GetApkInfoThread(QObject *parent = 0);
    ~GetApkInfoThread();
    void zipApkBag();
    void setApkPath(QString);
    void setApkLogo(QString apkLogoTmp);
    void getTarFile();
    QString apkPath;
    QString apkLogo;
    QString homePath;

protected:
    void run();

signals:
    void signalZipFinished(QString);

private:
    bool rmapkTmp(const QString dirName);
};

#endif // GETAPKINFOTHREAD_H
