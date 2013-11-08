#include "installthread.h"
#include <QDebug>

InstallThread::InstallThread(QObject *parent):QThread(parent)
{

}
InstallThread::~InstallThread()
{
    this->deleteLater();
}

void InstallThread::run()
{
    slotInstall();
}
void InstallThread::setCmd(QString homeP, QString apkP, QString falg,QString packageName)
{
    qDebug()<<homeP<<apkP<<falg;
    homePath = homeP;
    apkPath = apkP;
    adbPath = homePath+"/Resources/adb/adb";
    installModel = falg;
    strPackageName = packageName;
}
void InstallThread::slotInstall()
{
    QStringList cmdCheckList;
    QString cmd = "devices";
    cmdCheckList.append(cmd);
    qDebug()<<"in install thread ing~~~";

    //phone is or not online.
    //process adb device
    QProcess processADB;
    processADB.start(adbPath, cmdCheckList);
    processADB.waitForStarted();
    processADB.closeWriteChannel();
    processADB.waitForFinished();
    QString res = processADB.readAll();
    qDebug()<<"devices : "<<res;
    readADB(res);
}
void InstallThread::readADB(QString res)
{
    if(res.right(10).contains("device"))
    {
//        status = cmString::str_Installing;//tr("安装中...");
//        //0安装中，1安装出错，2安装成功
//        emit signalEmitRes(status,0);

        QStringList cmdCheckList1;
        cmdCheckList1.append("install");
        cmdCheckList1.append(installModel);
        cmdCheckList1.append(apkPath);
        QProcess p;
        p.start(adbPath, cmdCheckList1);
        p.waitForStarted();
        p.closeWriteChannel();
        p.waitForFinished();
        QString result = p.readAll();
        qDebug()<<"=======>>>>>  "<<result<<" "<<cmdCheckList1;
        readSetup(result);
    }
    else if(res.contains("offline"))
    {
        status = cmString::str_deviceOffLine;//tr("设备离线，请先重新连接设备！");
        emit signalEmitRes(status,1);
    }
    else
    {
        status = cmString::str_unConnectDevice;//tr("未检测到设备，请先将设备连接！");
        emit signalEmitRes(status,1);
    }
//    if(!QFile::rename(tmpFilePath,apkPath))
//    {
//        return;
    //    }
}

bool InstallThread::repeatInstall(QString strName)
{
    QStringList cmdCheckList1;
    cmdCheckList1.append("uninstall");
    cmdCheckList1.append(strName);
    QProcess p;
    p.start(adbPath, cmdCheckList1);
    p.waitForStarted();
    p.closeWriteChannel();
    p.waitForFinished();
    QString result = p.readAll();
    qDebug()<<"=======>>>>>wwwwww  "<<result<<" "<<cmdCheckList1;
    //readSetup(result);
    return true;
}
void InstallThread::readSetup(QString result)
{
    qDebug()<<"install finish~~~";
    QString tmp = result;
        //tmp = "INSTALL_PARSE_FAILED_INCONSISTENT_CERTIFICATES";
        if(tmp.contains("Success"))
        {
            status = cmString::str_installSuccess;//tr("安装成功！");
            emit signalEmitRes(status,2);
        }
        else if(tmp.contains("INSTALL_FAILED_ALREADY_EXISTS"))
        {
            status = cmString::str_appExists;//tr("软件已存在！");
            emit signalEmitRes(status,1);
        }
        else if(tmp.contains("INSTALL_FAILED_INSUFFICIENT_STORAGE"))
        {
            status = cmString::str_systemMemNone;//tr("系统空间不足！");
            emit signalEmitRes(status,1);
        }else if(tmp.contains("INSTALL_FAILED_MEDIA_UNAVAILABLE"))
        {
            status = cmString::str_media_unavailable;//tr("！");
            emit signalEmitRes(status,1);
        }else if(tmp.contains("INSTALL_FAILED_ALREADY_EXISTS"))
        {
            status = cmString::str_exists_app;//tr("！");
            emit signalEmitRes(status,1);
        }else if(tmp.contains("INSTALL_PARSE_FAILED_INCONSISTENT_CERTIFICATES"))
        {
            status = cmString::str_certificates;//tr("系统空间不足！");
            //emit signalEmitRes(status,1);
            //出现签名不一致，我们必须先卸载手机上面的版本，再安装新的apk
            if(repeatInstall(strPackageName))
            {
                QStringList cmdCheckList1;
                cmdCheckList1.append("install");
                cmdCheckList1.append(installModel);
                cmdCheckList1.append(apkPath);
                QProcess p;
                p.start(adbPath, cmdCheckList1);
                p.waitForStarted();
                p.closeWriteChannel();
                p.waitForFinished();
                QString result = p.readAll();
                qDebug()<<"=======>>>>>  "<<result<<" "<<cmdCheckList1;
                readReInstall(result);
            }
        }else if(tmp.contains("INSTALL_FAILED_OLDER_SDK"))
        {
            status = cmString::str_older_sdk;
            emit signalEmitRes(status,1);
        }
        else if(tmp.contains("Failure"))//
        {
            status = cmString::str_installFaild;//tr("安装失败！");
            emit signalEmitRes(status,1);
        }
        else
        {
            status = cmString::str_error_unknow;//未知错误!
            emit signalEmitRes(status,1);
        }
}

void InstallThread::readReInstall(QString str)
{
    QString tmp = str;
    if(tmp.contains("Success"))
    {
        status = cmString::str_installSuccess;//tr("安装成功！");
        emit signalEmitRes(status,2);
    }else{
        status = cmString::str_installFaild;//tr("安装成功！");
        emit signalEmitRes(status,1);
    }
}
