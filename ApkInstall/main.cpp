#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>
#include <QFileOpenEvent>
#include "getapkinfothread.h"
#include "cmstring.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *system = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForCStrings(system);
    QTextCodec::setCodecForLocale(system);
    QTextCodec::setCodecForTr(system);

    cmString::initCmString();
    //QString apkPath = QString(QApplication::QFileOpenEvent::url());


    Widget w;
    w.setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    w.setWindowModality(Qt::ApplicationModal);
    w.setAttribute(Qt::WA_TranslucentBackground);
    a.installEventFilter(&w);
    w.show();

    //w.getApkInfo(apkPath);
//    if(argc == 2)//接收路径参数，D团队使用
//    {
//        //QString apkPath = "F:/mobfound_svn_201210_release/MSIntaller/ApkInstallTest/我干你妹 12121.apk";
//        QString apkPath = QString(argv[1]);
//        apkPath = apkPath.replace ("-path=", "");
//        qDebug()<<apkPath;
//        w.getApkInfo(apkPath);
//    }

    return a.exec();
}
