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
//        status = cmString::str_Installing;//tr("��װ��...");
//        //0��װ�У�1��װ����2��װ�ɹ�
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
        status = cmString::str_deviceOffLine;//tr("�豸���ߣ��������������豸��");
        emit signalEmitRes(status,1);
    }
    else
    {
        status = cmString::str_unConnectDevice;//tr("δ��⵽�豸�����Ƚ��豸���ӣ�");
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
            status = cmString::str_installSuccess;//tr("��װ�ɹ���");
            emit signalEmitRes(status,2);
        }
        else if(tmp.contains("INSTALL_FAILED_ALREADY_EXISTS"))
        {
            status = cmString::str_appExists;//tr("����Ѵ��ڣ�");
            emit signalEmitRes(status,1);
        }
        else if(tmp.contains("INSTALL_FAILED_INSUFFICIENT_STORAGE"))
        {
            status = cmString::str_systemMemNone;//tr("ϵͳ�ռ䲻�㣡");
            emit signalEmitRes(status,1);
        }else if(tmp.contains("INSTALL_FAILED_MEDIA_UNAVAILABLE"))
        {
            status = cmString::str_media_unavailable;//tr("��");
            emit signalEmitRes(status,1);
        }else if(tmp.contains("INSTALL_FAILED_ALREADY_EXISTS"))
        {
            status = cmString::str_exists_app;//tr("��");
            emit signalEmitRes(status,1);
        }else if(tmp.contains("INSTALL_PARSE_FAILED_INCONSISTENT_CERTIFICATES"))
        {
            status = cmString::str_certificates;//tr("ϵͳ�ռ䲻�㣡");
            //emit signalEmitRes(status,1);
            //����ǩ����һ�£����Ǳ�����ж���ֻ�����İ汾���ٰ�װ�µ�apk
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
            status = cmString::str_installFaild;//tr("��װʧ�ܣ�");
            emit signalEmitRes(status,1);
        }
        else
        {
            status = cmString::str_error_unknow;//δ֪����!
            emit signalEmitRes(status,1);
        }
}

void InstallThread::readReInstall(QString str)
{
    QString tmp = str;
    if(tmp.contains("Success"))
    {
        status = cmString::str_installSuccess;//tr("��װ�ɹ���");
        emit signalEmitRes(status,2);
    }else{
        status = cmString::str_installFaild;//tr("��װ�ɹ���");
        emit signalEmitRes(status,1);
    }
}
