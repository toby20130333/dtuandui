#ifndef CMSTRING_H
#define CMSTRING_H

#include <QObject>
#include <QString>

class cmString
{
public:
    cmString();

    static QString str_Installing;
    static QString str_deviceOffLine;
    static QString str_unConnectDevice;
    static QString str_installSuccess;
    static QString str_appExists;
    static QString str_systemMemNone;
    static QString str_installFaild;
    static QString str_installAuto;
    static QString str_installFormPhone;
    static QString str_installFormSd;
    static QString str_WidgetTitle;
    static QString str_apkVersion;
    static QString str_apkSize;
    static QString str_apkSystemEnvironment;
    static QString str_apkInstallationSite;
    static QString str_displayAuthority;
    static QString str_install;
    static QString str_expansionAuthority;
    static QString str_hiddenAuthority;
    static QString str_installingTip1;

    static void initCmString();
};

#endif // CMSTRING_H
