#include "labpermission.h"
#include <QDebug>
#define APPLICATION_FONT_FAMILY "微软雅黑"

labPermission::labPermission(QWidget *parent) :
    QWidget(parent)
{  
    itemHeight = 20;
    itemWidth = 400;
    xPos = 30;
    yPos = 0;

    textfont.setBold(false);
    textfont.setPointSize(12);
    textfont.setFamily(APPLICATION_FONT_FAMILY);

    map["ACCESS_CHECKIN_PROPERTIES"]         =    tr("允许在 checkin数据库中读写访问”properties”表。");
    map["ACCESS_COARSE_LOCATION"]            =    tr("允许一个程序访问CellID或WiFi热点来获取粗略的位置。");
    map["ACCESS_FINE_LOCATION"]              =    tr("允许一个程序访问精良位置(如GPS)。");
    map["ACCESS_LOCATION_EXTRA_COMMANDS"]    =    tr("允许应用程序访问额外的位置提供命令。");
    map["ACCESS_MOCK_LOCATION"]              =    tr("允许程序创建模拟位置提供用于测试。");
    map["ACCESS_NETWORK_STATE"]              =    tr("允许程序访问有关GSM网络信息。");
    map["ACCESS_SURFACE_FLINGER"]            =    tr("允许程序使用SurfaceFlinger底层特性。");
    map["ACCESS_WIFI_STATE"] = tr("允许程序访问Wi-Fi网络状态信息。");
    map["ADD_SYSTEM_SERVICE"] =tr("允许程序发布系统级服务。");
    map["BATTERY_STATS"] =tr("允许程序更新手机电池统计信息。");
    map["BLUETOOTH"] =  tr("允许程序连接到已配对的蓝牙设备。");
    map["BLUETOOTH_ADMIN"] = tr("允许程序发现和配对蓝牙设备。");
    map["BRICK"] =tr("请求能够禁用设备(非常危险)。");
    map["BROADCAST_PACKAGE_REMOVED"] =tr("允许程序广播一个提示消息在一个应用程序包已经移除后。");
    map["BROADCAST_STICKY"] =tr("允许一个程序广播常用intents");
    map["CALL_PHONE"] = tr("允许一个程序初始化一个电话拨号不需通过拨号用户界面。");
    map["CALL_PRIVILEGED"] =tr("允许一个程序拨打任何号码，包含紧急号码无需通过拨号用户界面。");
    map["CAMERA"] = tr("请求访问使用照相设备");
    map["CHANGE_COMPONENT_ENABLED_STATE"] = tr("允许一个程序是否改变一个组件或其他的启用或禁用。");
    map["CHANGE_CONFIGURATION"] =  tr("允许一个程序修改当前设置，如本地化。");
    map["CHANGE_NETWORK_STATE"] = tr("允许程序改变网络连接状态。");
    map["CHANGE_WIFI_STATE"] = tr("允许程序改变Wi-Fi连接状态。");
    map["CLEAR_APP_CACHE"] = tr("允许一个程序从所有安装的程序在设备中清除缓存。");
    map["CLEAR_APP_USER_DATA"] =  tr("允许一个程序清除用户设置。");
    map["CONTROL_LOCATION_UPDATES"] = tr("允许启用禁止位置更新提示从无线模块。");
    map["DELETE_CACHE_FILES"] =      tr("允许程序删除缓存文件。");
    map["DELETE_PACKAGES"] =  tr("允许一个程序删除包。");
    map["DEVICE_POWER"] = tr("允许访问底层电源管理。");
    map["DIAGNOSTIC"] =   tr("允许程序RW诊断资源。");
    map["DISABLE_KEYGUARD"] =  tr("允许程序禁用键盘锁。");
    map["DUMP"] =  tr("允许程序返回状态抓取信息从系统服务。");
    map["EXPAND_STATUS_BAR"] = tr("在状态栏允许一个程序扩展收缩。");
    map["FACTORY_TEST"] =  tr("作为一个工厂测试程序，在root用户运行。");
    map["FLASHLIGHT"] =  tr("访问闪光灯。");
    map["FORCE_BACK"] = tr("是否允许程序在顶层activities强行一个后退操作。");
    map["FOTA_UPDATE"] =  tr("预留权限。");
    map["GET_ACCOUNTS"] =  tr("在Accounts Service中访问一个帐户列表。");
    map["GET_PACKAGE_SIZE"] =  tr("允许一个程序获取任何package占用空间容量。");
    map["GET_TASKS"] =  tr("允许一个程序获取有关当前或最近运行任务的信息。");
    map["HARDWARE_TEST"] =   tr("允许访问硬件。");
    map [ "INJECT_EVENTS"] = tr("允许一个程序截获用户事件如按键、触摸、轨迹球等等。");
    map["INSTALL_PACKAGES"] = tr("允许一个程序安装packages。");
    map["INTERNAL_SYSTEM_WINDOW"] =   tr("允许打开窗口使用系统用户界面。");
    map["INTERNET"] =  tr("允许程序打开网络套接字。");
    map["MODIFY_AUDIO_SETTINGS"] =  tr("允许程序修改全局音频设置。");
    map["MODIFY_PHONE_STATE"] =  tr("允许修改话机状态。");
    map["MOUNT_UNMOUNT_FILESYSTEMS"] =   tr("允许可移动存储挂载和反挂载文件系统。");
    map["PERSISTENT_ACTIVITY"] =  tr("允许一个程序设置他的activities显示。");
    map["PROCESS_OUTGOING_CALLS"] =   tr("允许程序监视、修改有关播出电话。");
    map["READ_CALENDAR"] = tr("允许程序读取用户日历数据。");
    map["READ_CONTACTS"] =  tr("允许程序读取用户联系人数据。");
    map["READ_FRAME_BUFFER"] =  tr(" 允许程序更多常规的访问帧缓冲数据");
    map["READ_INPUT_STATE"] = tr("允许程序返回当前按键状态。");
    map["READ_LOGS"] = tr("允许程序读取底层系统日志文件。");
    map["READ_OWNER_DATA"] = tr("允许程序读取所有者数据。");
    map["READ_SMS"] =  tr("允许程序读取短信息。");
    map["READ_SYNC_SETTINGS"] =  tr("允许程序读取同步设置。");
    map["READ_SYNC_STATS"] = tr("允许程序读取同步状态。");
    map["REBOOT"] =  tr("允许请求重新启动设备。");
    map["RECEIVE_BOOT_COMPLETED"] =  tr("允许程序在系统完成启动后接收广播。");
    map["RECEIVE_MMS"] = tr("允许程序记录或处理一个将收到MMS彩信。");
    map["RECEIVE_SMS"] = tr(" 允许程序记录或处理一个将收到短信息。");
    map["RECEIVE_WAP_PUSH"] = tr("允许程序监控将收到WAP PUSH信息。");
    map["RECORD_AUDIO"] =  tr("允许程序录制音频。");
    map["REORDER_TASKS"] =  tr("允许程序改变Z轴排列任务。");
    map["RESTART_PACKAGES"] =  tr("允许程序重新启动其他程序。");
    map["SEND_SMS"] =   tr("允许程序发送SMS短信。");
    map["SET_ACTIVITY_WATCHER"] =  tr("允许程序在已经启动全局系统中监控或控制activities。");
    map["SET_ALWAYS_FINISH"] =  tr("在处于后台时允许程序控制活动是否间接完成。");
    map["SET_ANIMATION_SCALE"] = tr("修改全局信息比例。");
    map["SET_DEBUG_APP"] =  tr("配置一个程序用于调试。");
    map["SET_ORIENTATION"] =   tr("允许底层访问设置屏幕方向和实际旋转。");
    map["SET_PREFERRED_APPLICATIONS"] =   tr("允许一个程序修改列表参数。");
    map["SET_PROCESS_FOREGROUND"] =  tr("允许程序当前运行程序强行到前台。");
    map["SET_PROCESS_LIMIT"] =  tr("允许设置最大的运行进程数量。");
    map["SET_TIME_ZONE"] =  tr("允许程序设置时间区域。");
    map["SET_WALLPAPER"] =  tr("允许程序设置壁纸。");
    map["SET_WALLPAPER_HINTS"] = tr("允许程序设置壁纸hits。");
    map["SIGNAL_PERSISTENT_PROCESSES"] = tr("允许程序请求发送信号到所有显示的进程中。");
    map["STATUS_BAR"] = tr("允许程序打开、关闭或禁用状态栏及图标。");
    map["SUBSCRIBED_FEEDS_READ"] =  tr("允许一个程序访问订阅RSS Feed内容提供。");
    map["VIBRATE"] = tr("允许访问振动设备。");
    map["WRITE_APN_SETTINGS"] =  tr("允许程序写入API设置。");
    map["WRITE_CALENDAR"] = tr("允许一个程序写入但不读取用户日历数据。");
    map["WRITE_CONTACTS"] =  tr(" 允许程序写入但不读取用户联系人数据");
    map["WRITE_GSERVICES"] = tr("允许程序修改Google服务地图。");
    map["WRITE_OWNER_DATA"] = tr("允许一个程序写入但不读取所有者数据。");
    map["WRITE_SETTINGS"] = tr("允许程序读取或写入系统设置。");
    map["WRITE_SMS"] = tr("允许程序写短信。");
    map["WRITE_SYNC_SETTINGS"] =  tr("允许程序写入同步设置。");
    map["WRITE_EXTERNAL_STORAGE"] =  tr("允许在SD卡上写入数据。");
}

int labPermission::addItem(QStringList listtmp)
{
    int returnCount =0;
    for(int i=0; i<listtmp.count(); i++)
    {
        QString str = changeToText(listtmp.at(i));
        if(str != "")
        {
            QLabel *labItemTmp = new QLabel(this);
            QLabel *labItemImg = new QLabel(this);
            yPos += itemHeight;
            labItemImg->setGeometry(xPos,yPos,15,15);
            //labItemImg->setStyleSheet("background-image: url(:/Image/limited_danger.png)");
            QPixmap imgTip = QPixmap(":/Image/limited_danger.png");
            imgTip = imgTip.scaled(15,15,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
            labItemImg->setPixmap(imgTip);
            labItemTmp->setGeometry(xPos+20,yPos,itemWidth,itemHeight);
            labItemTmp->setFont(textfont);
            labItemTmp->setAlignment(Qt::AlignVCenter);
            labItemTmp->setText(str);
            returnCount++;
        }
    }
    return returnCount-1;
}

QString labPermission::changeToText(QString cmd)
{
    cmd = cmd.replace("android.permission.", "");
    cmd = cmd.trimmed();
    //qDebug()<<"cmd------------>>> "<<cmd;
    return map[cmd];
}


