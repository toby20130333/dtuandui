#include "cmstring.h"

QString cmString::str_Installing = ("installing...");
QString cmString::str_install = ("");
QString cmString::str_deviceOffLine = ("设备离线，请先重新连接设备！");
QString cmString::str_unConnectDevice = ("未检测到设备，请先将设备连接！");
QString cmString::str_installSuccess = ("安装成功！");
QString cmString::str_appExists = ("软件已存在！");
QString cmString::str_systemMemNone = ("系统空间不足！");
QString cmString::str_installFaild = ("安装失败！");
QString cmString::str_installAuto = ("智能安装");
QString cmString::str_installFormPhone = ("手机内存");
QString cmString::str_installFormSd = ("SD卡");
QString cmString::str_WidgetTitle = ("魔方手机助手安装器");
QString cmString::str_apkVersion = ("版本：");
QString cmString::str_apkSize = ("大小：");
QString cmString::str_apkSystemEnvironment = ("系统：");
QString cmString::str_apkInstallationSite = ("安装位置:");
QString cmString::str_displayAuthority = ("显示权限");
QString cmString::str_expansionAuthority = ("展开权限");
QString cmString::str_hiddenAuthority = ("隐藏权限");
QString cmString::str_installingTip1 = ("2.2固件以下将会被安装到手机内存!");


cmString::cmString()
{
}


void cmString::initCmString()
{
    cmString::str_Installing = QObject::tr("Installing...");
    cmString::str_install = QObject::tr("Install");
    cmString::str_deviceOffLine = QObject::tr("Device offline, please reconnect first!");
    cmString::str_unConnectDevice = QObject::tr("Not detect device，please connect first!");
    cmString::str_installSuccess = QObject::tr("successful!");
    cmString::str_appExists = QObject::tr("APP already exists!");
    cmString::str_systemMemNone = QObject::tr("Out of Memory");
    cmString::str_installFaild = QObject::tr("failed!");
    cmString::str_installAuto = QObject::tr("Auto");
    cmString::str_installFormPhone = QObject::tr("Phone");
    cmString::str_installFormSd = QObject::tr("SD");
    cmString::str_WidgetTitle = QObject::tr("MobFound Erector");
    cmString::str_apkVersion = QObject::tr("version:");
    cmString::str_apkSize = QObject::tr("size:");
    cmString::str_apkSystemEnvironment = QObject::tr("version:");
    cmString::str_apkInstallationSite = QObject::tr("site:");
    cmString::str_displayAuthority = QObject::tr("authority");
    cmString::str_expansionAuthority = QObject::tr("show");
    cmString::str_hiddenAuthority = QObject::tr("hide");
    cmString::str_installingTip1 = QObject::tr("The App will be installed to phone following Andriod 2.2 !");
}
