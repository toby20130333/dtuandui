#include "widget.h"
#define APPLICATION_FONT_FAMILY "微软雅黑"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    canmove = false;
    homePath = QApplication::applicationDirPath();
    homePath.chop(6);
    permissionHeight = 0;
    isPermissionShow = false;
    installChList <<cmString::str_installAuto<<cmString::str_installFormPhone<<cmString::str_installFormSd;//tr("智能安装")<<tr("手机内存")<<tr("SD卡");
    installModel = "-r";
    pm = new QMovie(":/Image/loading.gif");
    isInstalling = false;
    pGetApkInfo = new GetApkInfoThread(this);
    initUI();
    connect(pGetApkInfo, SIGNAL(signalZipFinished(QString)), this,SLOT(slotSetIcon(QString)));

    connect(labCloseBtn, SIGNAL(iclicked()), this, SLOT(slotCloseBtnClicked()));
    connect(labCloseBtn, SIGNAL(ireleased()), this, SLOT(slotCloseBtnReleased()));
    connect(labCloseBtn, SIGNAL(ienterd()), this, SLOT(slotCloseBtnEntered()));
    connect(labCloseBtn, SIGNAL(iexited()), this, SLOT(slotCloseBtnExited()));
    connect(btnok,SIGNAL(iclicked()),this,SLOT(slotBtnokClicked()));
    connect(btnok, SIGNAL(ireleased()), this, SLOT(slotBtnOkReleased()));
    connect(btnok, SIGNAL(ienterd()), this, SLOT(slotBtnOkEntered()));
    connect(btnok, SIGNAL(iexited()), this, SLOT(slotBtnOkExited()));
    connect(labImgPack,SIGNAL(ireleased()),this,SLOT(slotBtnPackUpReleased()));
    connect(labBtnPackUp,SIGNAL(ireleased()),this,SLOT(slotBtnPackUpReleased()));
}

Widget::~Widget()
{
//    if(pInstallThread != 0)
//    {
//        pInstallThread->deleteLater();
//        pInstallThread = 0;
//    }
//    if(pGetApkInfo != 0)
//    {
//        pGetApkInfo->deleteLater();
//        pGetApkInfo = 0;
//    }
}

void Widget::initUI()
{
    this->setFixedSize(489,259);
    qDebug()<<"initUI "<<this->height();
    //主背景
    labbg = new QLabel(this);
    labbg->setGeometry(19,19,451,221);
    labbg->setStyleSheet("background-color: \"#F9F9F9\"");
    //主UI四周阴影
    labTopleft = new QLabel(this);
    labTopleft->setStyleSheet("background-image: url(:/Image/pop/pop_top_left.png)");
    labTopleft->setGeometry(0,0,19,19);
    labTopright = new QLabel(this);
    labTopright->setStyleSheet("background-image: url(:/Image/pop/pop_top_right.png)");
    labTopright->setGeometry(470,0,19,19);
    labTopMid = new QLabel(this);
    labTopMid->setStyleSheet("background-image: url(:/Image/pop/pop_top_mid.png)");
    labTopMid->setGeometry(19,0,451,19);
    lableftMid = new QLabel(this);
    lableftMid->setStyleSheet("background-image: url(:/Image/pop/pop_left_mid.png)");
    lableftMid->setGeometry(0,19,19,221);
    labrightMid = new QLabel(this);
    labrightMid->setStyleSheet("background-image: url(:/Image/pop/pop_right_mid.png)");
    labrightMid->setGeometry(470,19,19,221);
    labbottomLeft = new QLabel(this);
    labbottomLeft->setStyleSheet("background-image: url(:/Image/pop/pop_bottom_left.png)");
    labbottomLeft->setGeometry(0,240,19,19);
    labbottomRight = new QLabel(this);
    labbottomRight->setStyleSheet("background-image: url(:/Image/pop/pop_bottom_right.png)");
    labbottomRight->setGeometry(470,240,19,19);
    labbottomMid = new QLabel(this);
    labbottomMid->setStyleSheet("background-image: url(:/Image/pop/pop_bottom_mid.png)");
    labbottomMid->setGeometry(19,240,451,19);

    labTopRec = new QLabel(this);
    labTopRec->setStyleSheet("background-image: url(:/Image/pop/backup_title_bg.png)");
    labTopRec->setGeometry(16,18,457,41);

    QFont textfont;
    textfont.setPointSize(14);
    //textfont.setBold(true);
    textfont.setFamily(APPLICATION_FONT_FAMILY);

    labTitleLogo = new Ibutton(this);
    labTitleLogo->setGeometry(20, 20, 88, 31);
    labTitleLogo->setStyleSheet("background: transparent");
    QPixmap imgLogo = QPixmap(":/Image/dtuandui.png");
    labTitleLogo->setPixmap(imgLogo);


    labTitle = new QLabel(this);
    labTitle->setStyleSheet("background: transparent");
    titleText = cmString::str_WidgetTitle;//tr("D团队手机助手安装器");
    labTitle->setText(titleText);
    textfont.setPointSize(13);
    labTitle->setFont(textfont);
    labTitle->setGeometry(170, 19, 200, 35);

    labCloseBtn = new Ibutton(this);
    labCloseBtn->setGeometry(442,19,28,22);
    labCloseBtn->setStyleSheet("background: transparent");
    QPixmap imgClose = QPixmap(":/Image/pop/backup_btnclose_n.png");
    labCloseBtn->setPixmap(imgClose);

    labCenter = new QLabel(this);
    labCenter->setGeometry(19,54,451,130);

    havlingLineTop = new QLabel(this);
    havlingLineTop->setStyleSheet("background-color: \"#C8D4D7\"");
    havlingLineTop->setGeometry(19,54,451,1);

    centerLineDown = new QLabel(this);
    centerLineDown->setStyleSheet("background-color: \"#C8D4D7\"");
    centerLineDown->setGeometry(19,184,451,1);

    havlingLineDown = new QLabel(this);
    havlingLineDown->setStyleSheet("background-color: \"#C8D4D7\"");
    havlingLineDown->setGeometry(19,285,451,1);

    //apk图标
    labImgApk = new QLabel(this);
    labImgApk->setGeometry(54,70,55,55);
    imgApk = QPixmap(":/Image/pop/img_apk.png");
    imgApk = imgApk.scaled(55,55,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    labImgApk->setPixmap(imgApk);
    labImgApk->setAcceptDrops(true);
    labImgApk->installEventFilter(this);
    //apk名字
//    labApkName = new QLabel(this);
//    labApkName->setGeometry(129,65,200,30);
//    textfont.setPointSize(12);
//    //labApkName->setContextMenuPolicy();
//    labApkName->setFont(textfont);
//    labApkName->setText("");
//    labApkName->setAlignment(Qt::AlignVertical_Mask);

    labApkName = new ElidedLabel("",this);
    labApkName->setGeometry(129,65,200,30);
    labApkName->setFont(textfont);

    QFont textfont1;
    textfont1.setBold(false);
    textfont1.setPointSize(12);
    textfont1.setFamily(APPLICATION_FONT_FAMILY);
    //版本
    labApkVersion = new QLabel(this);
    labApkVersion->setGeometry(129,95,200,20);
    labApkVersion->setFont(textfont1);
    labApkVersion->setText(cmString::str_apkVersion);//(tr("版本："));
    //apk大小
    labApkSize = new QLabel(this);
    labApkSize->setGeometry(129,115,200,20);
    labApkSize->setFont(textfont1);
    labApkSize->setText(cmString::str_apkSize);//(tr("大小："));

    //系统版本
    labApkSys = new QLabel(this);
    labApkSys->setGeometry(129,135,200,20);
    labApkSys->setFont(textfont1);
    labApkSys->setText(cmString::str_apkSystemEnvironment);//(tr("系统："));

    //安装位置选择
    labInstallText = new QLabel(this);
    labInstallText->setGeometry(129,155,60,20);
    labInstallText->setText(cmString::str_apkInstallationSite);//(tr("安装位置:"));
    labInstallText->setFont(textfont1);
    apkInstallChoose = new QComboBox(this);
    apkInstallChoose->setGeometry(189,155,80,18);
    apkInstallChoose->addItems(installChList);
    apkInstallChoose->setFont(textfont1);
    const QString styleStr = "QComboBox {\
            border: 1px solid gray;\
            border-radius: 3px;\
            padding: 1px 18px 1px 3px;\
            min-width: 2em}";
    apkInstallChoose->setStyleSheet("border: 1px solid darkgray");
    connect(apkInstallChoose,SIGNAL(currentIndexChanged(int)),this,SLOT(slotComobBoxCurIndexChange(int)));

    //权限显示按钮位置
    labBtnPackUp = new Ibutton(this);
    labBtnPackUp->setGeometry(370,160,70,20);
    labBtnPackUp->setText(cmString::str_displayAuthority);//(tr("显示权限"));
    QPalette pe;
    pe.setColor(QPalette::WindowText,"#00A1EA");
    labBtnPackUp->setPalette(pe);

    labImgPack = new Ibutton(this);
    labImgPack->setGeometry(422,165,10,11);
    QPixmap imgPack = QPixmap(":/Image/permission_PackDown.png");
    labImgPack->setPixmap(imgPack);

    //权限显示
    permissionShow = new labPermission(this);
    permissionShow->hide();

    //滚动区域
    scroll = new QScrollArea(this);
    scroll->setGeometry(19,185,451,100);
    scroll->setWidget(permissionShow);
    scroll->setStyleSheet("border: 0px");
    scroll->hide();

    topShadow = new QLabel(this);
    topShadow->setGeometry(19,185,451,11);
    topShadow->setStyleSheet("background-image: url(:/Image/middleShadow.png)");
    topShadow->hide();

    const QString VSCROLLBAR_STYLE ="QScrollBar:vertical {margin: 0px 0px 0px 0px;background-color: transparent;color:gray;width: 8px;}\
                 .QScrollBar::handle:vertical {background-color: transparent; width: 8px; border-image:url(:/Image/line_p.png)}\
                 .QScrollBar::sub-line:vertical {subcontrol-origin: margin; border: 0px; height:0px}\
                 .QScrollBar::up-arrow:vertical {subcontrol-origin: margin; height:0px}\
                 .QScrollBar::add-line:vertical {subcontrol-origin: margin; border: 0px; height:0px}\
                 .QScrollBar::sub-page:vertical {background-color: transparent;}\
                 .QScrollBar::add-page:vertical {background-color: transparent;}";

    scrollbar = new QScrollBar(scroll);
    scrollbar->setStyleSheet (VSCROLLBAR_STYLE);
    scroll->setVerticalScrollBar (scrollbar);

    //连接状态显示
    imgStatus = new QLabel(this);
    imgStatus->setGeometry(27,206,15,15);

    labConnectStat = new QLabel(this);
    labConnectStat->setGeometry(50,195,300,35);
    QFont textfontStat;
    textfontStat.setPointSize(12);
    textfontStat.setFamily(APPLICATION_FONT_FAMILY);

    labConnectStat->setFont(textfontStat);
    labConnectStat->setAlignment(Qt::AlignVCenter);
    labConnectStat->setText(cmString::str_advices_contents);
                                     qDebug()<<"bottom y:"<<labbottomMid->y()<<"this2 Y" <<this->y()+this->height();
    //确定按钮
    btnok = new Ibutton(this);
    btnok->setGeometry(360,195,85,35);
    btnok->setFont(textfont1);
    btnok->setText(cmString::str_install);//(tr("安  装"));
    btnok->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    btnok->setStyleSheet("border-image: url(:/Image/pop/task_pauseall_n.png)");

}

void Widget::getApkInfo(QString apkoutPath)
{
    apkPath = apkoutPath;

    pGetApkInfo->setApkPath(apkPath);
//    pGetApkInfo.start();

    QProcess processApkInfo;
    QString cmd = homePath + "/Resources/adb/aapt";// + " d badging "+ apkPath;
    QStringList cmdList;
    cmdList.append("d");
    cmdList.append("badging");
    cmdList.append(apkPath);
    processApkInfo.start(cmd, cmdList);
    processApkInfo.waitForFinished();
    QString result = QString::fromUtf8(processApkInfo.readAll().data()).toLocal8Bit().data();
    qDebug()<<"cmdList "<<cmdList<<"\ncmd "<<cmd;
    paraApkInfo(result);
}

void Widget::paraApkInfo(QString result)
{
    qDebug()<<"paraApkInfo "<<result;
    allInfo = result;

    apkLogo = getValue(allInfo,"icon=");
    if(apkLogo.isEmpty())
    {
        labImgApk->setPixmap(imgApk);

    }else{
        qDebug()<<"apkLogo "<<apkLogo;
        pGetApkInfo->setApkLogo(apkLogo);
        pGetApkInfo->start();
    }


    apkname = getValue(allInfo,"application-label");
    QFileInfo file(apkPath);

    if(apkname.isEmpty())
    {
        apkname = file.fileName();
    }
    if(apkname.contains("?"))
    {
        apkname.replace("?","");
    }
    //apkname.replace();
    apkVersion = getValue(allInfo,"versionName");
    if(apkVersion.isEmpty())
    {
        apkVersion = "1.0.0.0";
    }
    sdkVertion = getSdkVersion(getValue(allInfo,"sdkVersion"));
    apkPermision = getValues(allInfo,"uses-permission");
    apkSize = getFileSize(apkPath);
    packageName = getValue(allInfo,"package: name=");

    labApkName->setText(apkname);
    labApkVersion->setText(cmString::str_apkVersion+apkVersion);
    labApkSize->setText(cmString::str_apkSize+apkSize);
    labApkSys->setText(cmString::str_apkSystemEnvironment+sdkVertion+"及以上版本");
    qDebug()<<"permision ---------->>>  "<<apkPermision;
    apkPermision.removeDuplicates();
    int countTmp = permissionShow->addItem(apkPermision);
    int perLabelHeight = ((20*countTmp));
    qDebug()<<"perLabelHeight ---------->>>  "<<perLabelHeight;
    permissionShow->resize(415, perLabelHeight+40);

}

QString Widget::getValue(QString strsource, QString strdes)
{
    QString source = strsource;
    if(!source.contains(strdes))
    {
        return "";
    }
    int index = source.indexOf(strdes);
    int j = 2;
    QString strout = "";
    for(int i = index;i<source.length();i++)
    {
        if(source[i] == '\''||source[i] == '\n')
        {
            j--;
            if(j == 1)
            {
                continue;
            }
            else if(j == 0)
            {
                break;
            }
        }
        else
        {
            if(j == 1)
            {
                strout+=source[i];
            }
        }
    }
    return strout;
}

QStringList Widget::getValues(QString strsource, QString strdes)
{
    QString source = strsource;
    QStringList outlist;
    while(int i = source.indexOf(strdes) != -1)
    {
        QString strtmp = getValue(source,strdes);
        outlist.append(strtmp);
        source = source.mid(i+strdes.length()+strtmp.length(),source.length());
    }
    return outlist;
}

QString Widget::getSdkVersion(QString resVersion)
{
    QString outVersion;
    switch(resVersion.toInt())
    {
    case 3:
        outVersion = "1.5";
        break;
    case 4:
        outVersion = "1.6";
        break;
    case 5:
        outVersion = "2.0";
        break;
    case 6:
        outVersion = "2.0.1";
        break;
    case 7:
        outVersion = "2.1";
        break;
    case 8:
        outVersion = "2.2";
        break;
    case 9:
        outVersion = "2.3";
        break;
    case 10:
        outVersion = "2.3.3";
        break;
    case 11:
        outVersion = "3.0";
        break;
    case 12:
        outVersion = "3.1";
        break;
    case 13:
        outVersion = "3.2";
        break;
    case 14:
        outVersion = "4.0.1";
        break;
    case 15:
        outVersion = "4.0.3";
        break;
    default:
        outVersion = "2.1.1";
        break;
    }
    return outVersion;
}

QString Widget::getFileSize(QString resFile)
{
    QString outSize;
    QFileInfo fileInfo;
    fileInfo.setFile(resFile);
    float apkSize;
    apkSize = fileInfo.size();
    apkSize /= 1024;
    if(apkSize > 1024)
    {
        apkSize /= 1024;
        outSize = QString::number(apkSize,'f',2)+"M";
    }
    else
    {
        outSize = QString::number(apkSize,'f',2)+"K";
    }
    return outSize;
}

//void Widget::getCFBundle()
//{
//#ifdef Q_WS_MAC
//     CFURLRef appUrlRef = CFBundleCopyBundleURL(CFBundleGetMainBundle());
//     CFStringRef macPath = CFURLCopyFileSystemPath(appUrlRef,
//                                            kCFURLPOSIXPathStyle);
//     const char *pathPtr = CFStringGetCStringPtr(macPath,
//                                            CFStringGetSystemEncoding());
//     qDebug("Path = %s", pathPtr);
//     CFRelease(appUrlRef);
//     CFRelease(macPath);
// #endif
//}
void Widget::mousePressEvent(QMouseEvent *e)
{
    if(!(apkInstallChoose->rect().contains(e->pos())) && (e->pos().x()>= 60) && (e->pos().y()<=45))
    {
        canmove = true;
    }
    else
    {
        canmove = false;
        e->accept();
        return;
    }
    oldPos = e->pos();
    e->accept();
}
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(canmove)
    {
        move(e->globalPos() - oldPos);
    }
    e->accept();
}
void Widget::slotCloseBtnClicked()
{
    QPixmap imgClose = QPixmap(":/Image/pop/backup_btnclose_p.png");
    labCloseBtn->setPixmap(imgClose);
    this->close();
}
void Widget::slotCloseBtnReleased()
{
    QPixmap imgClose = QPixmap(":/Image/pop/backup_btnclose_n.png");
    labCloseBtn->setPixmap(imgClose);
}
void Widget::slotCloseBtnEntered()
{
    QPixmap imgClose = QPixmap(":/Image/pop/backup_btnclose_h.png");
    labCloseBtn->setPixmap(imgClose);
}
void Widget::slotCloseBtnExited()
{
    QPixmap imgClose = QPixmap(":/Image/pop/backup_btnclose_n.png");
    labCloseBtn->setPixmap(imgClose);
}
void Widget::slotBtnokClicked()
{
    if(apkPath.length()>0 && !isInstalling)
    {
        btnok->setStyleSheet("border-image: url(:/Image/pop/task_pauseall_p.png)");
    }
}
void Widget::slotBtnOkReleased()
{
    if(apkPath.length()>0 && !isInstalling)
    {
        isInstalling = true;
        btnok->setStyleSheet("border-image: url(:/Image/pop/task_pauseall_n.png)");
        imgStatus->show();
        imgStatus->setMovie(pm); //将图片加载到label上
        pm->start();
        labConnectStat->setText(cmString::str_Installing);
        installApk();
    }
}
void Widget::slotBtnOkEntered()
{
    if(!isInstalling)
    {
        btnok->setStyleSheet("border-image: url(:/Image/pop/task_pauseall_h.png)");
    }
}
void Widget::slotBtnOkExited()
{
    if(!isInstalling)
    {
        btnok->setStyleSheet("border-image: url(:/Image/pop/task_pauseall_n.png)");
    }
}
void Widget::slotBtnPackUpReleased()
{
    qDebug()<<"bottom1 y:"<<labbottomMid->y()<<"this1 Y" <<this->y()+this->height();
    if(isPermissionShow)
    {
        permissionHeight = 0;
        isPermissionShow = false;
        labBtnPackUp->setText(cmString::str_expansionAuthority);//(tr("展开权限"));
        QPixmap imgPack = QPixmap(":/Image/permission_PackDown.png");
        labImgPack->setPixmap(imgPack);
        permissionShow->hide ();
        scroll->hide();
        topShadow->hide();
        this->setFixedSize(489,259+permissionHeight-15);
    }
    else
    {
        permissionHeight = 100;
        isPermissionShow = true;
        labBtnPackUp->setText(cmString::str_hiddenAuthority);//(tr("隐藏权限"));
        QPixmap imgPack = QPixmap(":/Image/permission_packUp.png");
        labImgPack->setPixmap(imgPack);
        permissionShow->show ();
        scroll->show();
        topShadow->show();
        this->setFixedSize(489,259+permissionHeight);
    }

    this->repaint();
    //主背景
    labbg->setGeometry(19,19,451,221+permissionHeight);
    labbg->repaint();
    //主UI四周阴影
    lableftMid->setGeometry(0,19,19,221+permissionHeight);
    labrightMid->setGeometry(470,19,19,221+permissionHeight);
    labbottomLeft->setGeometry(0,240+permissionHeight,19,19);
    labbottomRight->setGeometry(470,240+permissionHeight,19,19);
    labbottomMid->setGeometry(19,240+permissionHeight,451,19);
    labbottomLeft->repaint();
    labbottomRight->repaint();
    labbottomMid->repaint();
    imgStatus->setGeometry(27,204+permissionHeight,15,15);
    labConnectStat->setGeometry(50,195+permissionHeight,200,35);
    btnok->setGeometry(360,195+permissionHeight,85,35);
    qDebug()<<"主背景 "<<this->height()<<"labConnectStat "<<labConnectStat->height();
    qDebug()<<"bottom2 y:"<<labbottomMid->y()<<"this Y" <<this->y()+this->height();
    update();
}
void Widget::slotComobBoxCurIndexChange(int index)
{
    switch (index)
    {
    case 0:
    {
        if(!isInstalling)
        {
            labConnectStat->setText("");
            imgStatus->hide();
        }
        installModel = "-r";
    }
        break;
    case 1:
    {
        if(!isInstalling)
        {
            labConnectStat->setText("");
            imgStatus->hide();
        }
        installModel = "-rf";
    }
        break;
    case 2:
    {
        if(!isInstalling)
        {
            labConnectStat->setText(cmString::str_installingTip1);//(tr("2.2固件以下将会被安装到手机内存!"));
            imgStatus->hide();
        }
        installModel = "-rs";
    }
        break;
    default:
        break;
    }
}
void Widget::installApk()
{
    pInstallThread = new InstallThread(this);
    connect(pInstallThread,SIGNAL(signalEmitRes(QString,int)),this,SLOT(slotSetInstallStatus(QString,int)));

    int tmpIndex = apkPath.lastIndexOf("/");
    QString tmpHead = apkPath.mid(0,tmpIndex+1);
    QString tmpCurrentTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    tmpFilePath = homePath+"/" + tmpCurrentTime + ".apk";
    qDebug()<<"tmpFilePath "<<tmpFilePath;
    //copy local apk to Resources dir
    if(QFile::copy(apkPath,tmpFilePath))
    {
        pInstallThread->setCmd(homePath, tmpFilePath, installModel,packageName);
        pInstallThread->start();
    }

//    if(!QFile::rename(apkPath,tmpFilePath))
//    {
//        return;
//    }

}
void Widget::slotSetInstallStatus(QString res, int flag)
{
    QPixmap imgstat;
    imgStatus->show();
    if(flag == 0)
    {
        imgStatus->setMovie(pm); //将图片加载到label上
        pm->start();
        labConnectStat->setText(res);
    }else if(flag == 1)
    {
        imgstat = QPixmap(":/Image/task_oprationmentions_f.png");
        imgstat = imgstat.scaled(15,15,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        imgStatus->setPixmap(imgstat);
        labConnectStat->setText(res);
        isInstalling = false;
    }else if(flag == 2)
    {
        imgstat = QPixmap(":/Image/task_oprationmentions_s.png");
        imgstat = imgstat.scaled(15,15,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        imgStatus->setPixmap(imgstat);
        labConnectStat->setText(res);
        isInstalling = false;
    }
    if(!QFile::remove(tmpFilePath))
    {
        return;
    }
    if(pInstallThread != 0)
    {
        pInstallThread->terminate();
        pInstallThread = 0;
        delete pInstallThread;
    }
}

void Widget::slotSetIcon(QString iconPath)
{
    //加载应用图标
    //QPixmap imgApkTmp = QPixmap(homePath+"/apktmp/"+apkLogo);
    QPixmap imgApkTmp = QPixmap(iconPath);

    qDebug()<<"bubble in slotSetIcon :   "<<homePath+"/apktmp/"+apkLogo<<" iconPath"<<iconPath;
    imgApkTmp = imgApkTmp.scaled(55,55,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    labImgApk->setPixmap(imgApkTmp);

}
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == labImgApk)
    {
            qDebug()<<"in it..........";            
            if (event->type() == QEvent::DragEnter) {
                // [[2]]: 当拖放时鼠标进入label时, label接受拖放的动作
                labConnectStat->setText(cmString::str_advices_contents);
                imgStatus->hide();
                QDragEnterEvent *dee = dynamic_cast<QDragEnterEvent *>(event);
                dee->acceptProposedAction();
                return true;
            } else if (event->type() == QEvent::Drop) {
                // [[3]]: 当放操作发生后, 取得拖放的数据
                QDropEvent *de = dynamic_cast<QDropEvent *>(event);
                QList<QUrl> urls = de->mimeData()->urls();

                qDebug()<<"xxxx"<<urls;
                if (urls.isEmpty()) { return true; }
                QString path = urls.first().toLocalFile();

                // [[4]]: 在label上显示拖放的图片
                QFileInfo iapk(path); // QImage对I/O优化过, QPixmap对显示优化
                if(iapk.exists())
                {
                    if(iapk.fileName().contains(".apk"))
                    {
                        //labTitle->setText(path);
                        getApkInfo(path);
                    }
                }
                return true;
            }

    }else if(event->type()==QEvent::FileOpen){
        QFileOpenEvent *eventMy = dynamic_cast<QFileOpenEvent*>(event);
        if(eventMy)
        {
             QString str = eventMy->url().toString();
             QFileInfo info(str);
             if(info.fileName().contains(".apk"))
             {
                 getApkInfo(str.mid(7));
             }
        }
    }

     return QWidget::eventFilter(watched, event);
}
void Widget::associateApk()
{
    //删除默认项
    QString tmp = qApp->arguments().at(0);
    tmp.chop(13);
    QSettings *settings = new QSettings("HKEY_CLASSES_ROOT\\.apk\\", QSettings::NativeFormat);
    settings->remove(".");

    //将默认项改成需要打开应用程序在注册表中的路径
    settings->setValue(".",QVariant("MSApkInstaller"));
    delete settings;

    //插入安装程序的注册表项
    QSettings *settings1 = new QSettings("HKEY_CLASSES_ROOT\\MSApkInstaller\\", QSettings::NativeFormat);
    QString strIcoPath = tmp +"/Resources/logo/MSAPK.ico"+",0";
    settings1->setValue(".",cmString::strAndroidApk);
    strIcoPath.replace("/","\\");
    settings1->setValue("DefaultIcon/.",strIcoPath);
    settings1->setValue("shell/.","open");
    settings1->setValue("shell/open/.","mobfound APk安装程序");
    QString cmd = "\""+tmp+"/msApkTool.exe\" -path=\"%1\"";
    cmd.replace ("/","\\");
    settings1->setValue("shell/open/command/.", cmd);
    delete settings1;

    //在注册表中右键删除下面这个注册表项：
    //HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\FileExts\.apk\UserChoice
    //这个注册表项下的值和数据（具体就是名为progid的值和它的数据），是对应右键打开方式所设置的默认打开程序的
    QSettings *settings2 = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FileExts\\.apk\\", QSettings::NativeFormat);
    settings2->setValue("Progid",QVariant("MSApkInstaller"));
    delete settings2;

    qDebug()<<"homePathhomePathhomePathhomePathhomePathhomePathhomePath "<<tmp;
    //通知系统强制刷新系统图标缓存， 需要有#include <Shlobj.h>头文件
    //::SHChangeNotify(SHCNE_ASSOCCHANGED,SHCNF_IDLIST|SHCNF_FLUSH,0,0);
}
