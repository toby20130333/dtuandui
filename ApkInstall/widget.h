#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qDebug>
#include <QProcess>
#include <QFileInfo>
#include <QPixmap>
#include <QDir>
#include <QLabel>
#include <QMouseEvent>
#include "ibutton.h"
#include <QScrollArea>
#include <QScrollBar>
#include "labpermission.h"
#include <QApplication>
#include <QComboBox>
#include "installthread.h"
#include <QTimeLine>
#include <QMovie>
#include <QTime>
#include <QDateTime>
#include <QFile>
#include "getapkinfothread.h"
#include "cmstring.h"
#include "elidedlabel.h"

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QUrl>
#include <QSettings>
#include <QFileOpenEvent>

//#include <windows.h>
//#include <Shlobj.h>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void getApkInfo(QString);
    void associateApk();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    bool canmove;
    QString apkPath;
    QString homePath;
    QString allInfo;
    QString apkname;
    QString apkVersion;
    QString apkSize;
    QString apkLogo;
    QString sdkVertion;
    QStringList apkPermision;
    int permissionHeight;
    bool isPermissionShow;
    bool isInstalling;
    QString packageName;

    QString titleText;
    QString imgApkPath;
    QString strApkName;
    QString strApkVersion;
    QStringList installChList;
    QString installModel;
    QMovie *pm;
    QPixmap imgApk;

    QLabel *labbg;
    QLabel *labTopRec;
    QLabel *labTitle;
    QLabel *labCenter;
    QLabel *havlingLineTop;
    QLabel *centerLineDown;
    QLabel *havlingLineDown;
    QLabel *labImgApk;
    //QLabel *labApkName;
    QLabel *labApkVersion;
    QLabel *labApkSize;
    QLabel *labApkSys;
    QLabel *labConnectStat;
    QLabel *topShadow;
    QLabel *imgStatus;

    QLabel *labTopleft;
    QLabel *labTopright;
    QLabel *labTopMid;
    QLabel *lableftMid;
    QLabel *labrightMid;
    QLabel *labbottomLeft;
    QLabel *labbottomRight;
    QLabel *labbottomMid;

    QPoint oldPos;
    Ibutton *labTitleLogo;
    Ibutton *labCloseBtn;
    Ibutton *btnok;
    Ibutton *labBtnPackUp;
    Ibutton *labImgPack;
    QScrollArea *scroll;
    QScrollBar *scrollbar;
    labPermission *permissionShow;
    QLabel *labInstallText;
    QComboBox *apkInstallChoose;
    InstallThread* pInstallThread;

    GetApkInfoThread *pGetApkInfo;
    QString tmpFilePath;
    ElidedLabel* labApkName;

private:
    QString getValue(QString,QString);
    QStringList getValues(QString,QString);
    QString getSdkVersion(QString);
    QString getFileSize(QString);
//    bool rmapkTmp(const QString dirName);
//    QString getMeidaNamefromPath(QString path);
    void getCFBundle();

    void initUI();
    void installApk();
    void paraApkInfo(QString);
private slots:
    void slotCloseBtnClicked();
    void slotCloseBtnReleased();
    void slotCloseBtnEntered();
    void slotCloseBtnExited();

    void slotBtnokClicked();
    void slotBtnOkReleased();
    void slotBtnOkEntered();
    void slotBtnOkExited();

    void slotBtnPackUpReleased();
    void slotComobBoxCurIndexChange(int);
    void slotSetInstallStatus(QString,int);
    void slotSetIcon(QString);
protected:
    bool eventFilter(QObject *, QEvent *);

};

#endif // WIDGET_H
