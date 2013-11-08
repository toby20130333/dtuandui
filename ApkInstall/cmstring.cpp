#include "cmstring.h"

QString cmString::str_Installing = ("安装中...");
QString cmString::str_install = ("安  装");
QString cmString::str_deviceOffLine = ("设备离线，请先重新连接设备！");
QString cmString::str_unConnectDevice = ("未检测到设备，请先将设备连接！");
QString cmString::str_installSuccess = ("安装成功！");
QString cmString::str_appExists = ("软件已存在！");
QString cmString::str_systemMemNone = ("系统空间不足！");
QString cmString::str_installFaild = ("安装失败！");
QString cmString::str_installAuto = ("智能安装");
QString cmString::str_installFormPhone = ("手机内存");
QString cmString::str_installFormSd = ("SD卡");
QString cmString::str_WidgetTitle = ("D团队手机助手安装器");
QString cmString::str_apkVersion = ("版本：");
QString cmString::str_apkSize = ("大小：");
QString cmString::str_apkSystemEnvironment = ("系统：");
QString cmString::str_apkInstallationSite = ("安装位置:");
QString cmString::str_displayAuthority = ("显示权限");
QString cmString::str_expansionAuthority = ("展开权限");
QString cmString::str_hiddenAuthority = ("隐藏权限");
QString cmString::str_installingTip1 = ("2.2固件以下将会被安装到手机内存!");
QString cmString::str_error_unknow = ("apk包可能损坏，建议重新下载");
QString cmString::str_media_unavailable = ("安装失败 建议安装到SD卡");
QString cmString::str_certificates = "签名不一致，卸载后重新安装中...";
QString cmString::str_exists_app = "安装包已存在，不建议重复安装";
QString cmString::str_advices_contents = "试试拖动apk到D团队图标上面";
QString cmString::strAndroidApk = "Android 程序安装包 (.apk)";
QString cmString::str_older_sdk = "您的Android SDK太旧，建议升级系统后再安装";

cmString::cmString()
{
}


void cmString::initCmString()
{
    cmString::str_Installing = QObject::tr("安装中...");
    cmString::str_install = QObject::tr("安  装");
    cmString::str_deviceOffLine = QObject::tr("设备离线，请先重新连接设备！");
    cmString::str_unConnectDevice = QObject::tr("未检测到设备，请先将设备连接！");
    cmString::str_installSuccess = QObject::tr("安装成功！");
    cmString::str_appExists = QObject::tr("软件已存在！");
    cmString::str_systemMemNone = QObject::tr("系统空间不足！");
    cmString::str_installFaild = QObject::tr("安装失败！");
    cmString::str_installAuto = QObject::tr("智能安装");
    cmString::str_installFormPhone = QObject::tr("手机内存");
    cmString::str_installFormSd = QObject::tr("SD卡");
    cmString::str_WidgetTitle = QObject::tr("D团队手机助手安装器");
    cmString::str_apkVersion = QObject::tr("版本：");
    cmString::str_apkSize = QObject::tr("大小：");
    cmString::str_apkSystemEnvironment = QObject::tr("系统：");
    cmString::str_apkInstallationSite = QObject::tr("安装位置:");
    cmString::str_displayAuthority = QObject::tr("显示权限");
    cmString::str_expansionAuthority = QObject::tr("展开权限");
    cmString::str_hiddenAuthority = QObject::tr("隐藏权限");
    cmString::str_installingTip1 = QObject::tr("2.2固件以下将会被安装到手机内存!");
    cmString::str_error_unknow = QObject::tr("apk包可能损坏，建议重新下载");
    cmString::str_media_unavailable = QObject::tr("安装失败 建议安装到SD卡");
    cmString::str_certificates = QObject::tr("签名不一致，卸载后重新安装");
    cmString::str_exists_app = QObject::tr("安装包已存在，不建议重复安装");
    cmString::str_advices_contents = QObject::tr("试试拖动apk到D团队图标上面");
    cmString::strAndroidApk = QObject::tr("Android 程序安装包 (.apk)");
    cmString::str_older_sdk = QObject::tr("您的Android SDK太旧，建议升级系统后再安装");

}
