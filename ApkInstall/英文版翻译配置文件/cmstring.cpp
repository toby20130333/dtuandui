#include "cmstring.h"

QString cmString::str_Installing = ("installing...");
QString cmString::str_install = ("");
QString cmString::str_deviceOffLine = ("�豸���ߣ��������������豸��");
QString cmString::str_unConnectDevice = ("δ��⵽�豸�����Ƚ��豸���ӣ�");
QString cmString::str_installSuccess = ("��װ�ɹ���");
QString cmString::str_appExists = ("����Ѵ��ڣ�");
QString cmString::str_systemMemNone = ("ϵͳ�ռ䲻�㣡");
QString cmString::str_installFaild = ("��װʧ�ܣ�");
QString cmString::str_installAuto = ("���ܰ�װ");
QString cmString::str_installFormPhone = ("�ֻ��ڴ�");
QString cmString::str_installFormSd = ("SD��");
QString cmString::str_WidgetTitle = ("ħ���ֻ����ְ�װ��");
QString cmString::str_apkVersion = ("�汾��");
QString cmString::str_apkSize = ("��С��");
QString cmString::str_apkSystemEnvironment = ("ϵͳ��");
QString cmString::str_apkInstallationSite = ("��װλ��:");
QString cmString::str_displayAuthority = ("��ʾȨ��");
QString cmString::str_expansionAuthority = ("չ��Ȩ��");
QString cmString::str_hiddenAuthority = ("����Ȩ��");
QString cmString::str_installingTip1 = ("2.2�̼����½��ᱻ��װ���ֻ��ڴ�!");


cmString::cmString()
{
}


void cmString::initCmString()
{
    cmString::str_Installing = QObject::tr("Installing...");
    cmString::str_install = QObject::tr("Install");
    cmString::str_deviceOffLine = QObject::tr("Device offline, please reconnect first!");
    cmString::str_unConnectDevice = QObject::tr("Not detect device��please connect first!");
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
