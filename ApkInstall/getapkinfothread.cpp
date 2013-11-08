#include "getapkinfothread.h"
#include <QDebug>

GetApkInfoThread::GetApkInfoThread(QObject *parent):QThread(parent)
{
    homePath = QApplication::applicationDirPath();
    homePath.chop(6);
}

GetApkInfoThread::~GetApkInfoThread()
{
    this->deleteLater();
}

void GetApkInfoThread::run()
{
    //zipApkBag();
    getTarFile();
}

void GetApkInfoThread::setApkPath(QString apkPathTmp)
{
    apkPath = apkPathTmp;
}
void GetApkInfoThread::setApkLogo(QString apkLogoTmp)
{
    apkLogo = apkLogoTmp;
}

void GetApkInfoThread::getTarFile()
{
    //解压压缩包中指定文件(或目录):  tar -zxvf  tar文件名 -C descFile  指定的要解压的文件名(如果在子目录中要加入目录)或目录,
       QProcess processTar;
       QString descPath = homePath+"/Resources/tmp";//+packAgeName+"_"+QTime::currentTime().toString();
       QString cmd = "tar";//    + apkPath + " -d " + homePath + "/apktmp/";
       QStringList cmdList;

       cmdList.append("-xzvf");
       cmdList.append(apkPath);
       cmdList.append("-C");
       cmdList.append(descPath);
       cmdList.append(apkLogo);
       processTar.start(cmd, cmdList);
       processTar.waitForStarted();
       processTar.closeWriteChannel();
       processTar.waitForFinished();
       qDebug()<<"iconPath2 "<<apkLogo<<cmdList<<"\n"<<processTar.readAll();
       QFileInfo fileInfo(descPath+"/"+apkLogo);
       QFile file(descPath+"/"+apkLogo);
       QString filePath = fileInfo.absolutePath();
       QString returnPath = filePath+"/"+QDateTime::currentDateTime().toString("yyyyMMddHHmmss")+".png";
       qDebug()<<"getIconFromApk "<<filePath;
       if(file.exists())
       {
           bool bl = file.rename(returnPath);
           qDebug()<<"getIconFromApk "<<returnPath<<" return status"<<bl;
       }
       emit signalZipFinished(returnPath);
       //return returnPath;
}

void GetApkInfoThread::zipApkBag()
{
    QString homePath = QApplication::applicationDirPath();

    rmapkTmp(homePath+"/apktmp");
    //解压压缩包中指定文件(或目录):  tar -zxvf  tar文件名 -C descFile  指定的要解压的文件名(如果在子目录中要加入目录)或目录,
    QDir dir;
    dir.mkdir(homePath+"/apktmp");

    QProcess processUnzip;
    QString cmd = homePath + "/Resources/adb/unzip.exe" ;//    + apkPath + " -d " + homePath + "/apktmp/";
//    QStringList cmdList;
//    cmdList.append(apkPath);
//    cmdList.append("-d");
//    cmdList.append(homePath);
//    cmdList.append("/apktmp/");
    QStringList cmdList;
    cmdList.append(apkPath);
    cmdList.append("-X");
    cmdList.append(apkLogo);
    cmdList.append("-d");
    cmdList.append(homePath+"/apktmp/");

    processUnzip.start(cmd, cmdList);
    processUnzip.waitForFinished();
    qDebug()<<"cmdListcmdListcmdListcmdList"<<cmdList;
    emit signalZipFinished("");
}

bool GetApkInfoThread::rmapkTmp(const QString dirName)
{
    QDir directory(dirName);

    if (!directory.exists())
    {
        return true;
    }

    QStringList files = directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);


    QList<QString>::iterator f = files.begin();

    bool error = false;

    for (; f != files.end(); ++f)
    {
        QString filePath = QDir::convertSeparators(directory.path() + '/' + (*f));
        QFileInfo fi(filePath);
        if (fi.isFile() || fi.isSymLink())
        {
            QFile::setPermissions(filePath, QFile::WriteOwner);
            if (!QFile::remove(filePath))
            {
                error = true;
            }
        }
        else if (fi.isDir())
        {
            if (!rmapkTmp(filePath))
            {
                error = true;
            }
        }
    }

    if(!directory.rmdir(QDir::convertSeparators(directory.path())))
    {
        error = true;
    }
    return false;

}
