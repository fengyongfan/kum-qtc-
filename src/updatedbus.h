#ifndef UPDATEDBUS_H
#define UPDATEDBUS_H

#define KYLIN_UPDATE_MANAGER_PATH "/cn/kylinos/KylinUpdateManager"

#define KYLIN_UPDATE_MANAGER_SERVICE "cn.kylinos.KylinUpdateManager"

#define KYLIN_UPDATE_MANAGER_INTERFACE "cn.kylinos.KylinUpdateManager"

//#define SERVICE_NAME_SIZE 30

#include <QObject>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtDBus>
#include <unistd.h>
#include <sys/types.h>
#include <QFile>
#include <QSettings>
#include <QApt/Package>
#include <QApt/SourcesList>
#include <QApt/Backend>
#include <QApt/Changelog>
#include <QProcess>
#include <QTime>
#include <QTimer>


#include <QCoreApplication>
//#include <Python.h>
#include "appupdate.h"
#include "metatypes.h"

class UpdateDbus : public QObject
{
    Q_OBJECT
public:
    explicit UpdateDbus();

    static UpdateDbus *updateMutual;  //UpdateDbus类静态对象

    QDBusInterface *interface;  //dbus接口

    QDBusReply<QString> replyStr;   //string类型的返回值
    QDBusReply<bool> replyBool;     //bool类型的返回值
//    QDBusReply<QStringList> replyList;   //stringlist类型的返回值
    QDBusReply<QStringList> replyStrList;
    QDBusReply<int> replyInt; //int类型的返回值



    // 关闭自动更新
    bool autoStartClose();

    //开启自动更新
    bool autoStartOpen();

    //取消更新包
    bool cancel(QString pkgName);

    // 取消更新应用
    void cancelDownloadApp(QString appName);

    //改变source.list为默认源
    bool changeSourceListToDefault(QString serviceKey,QString pwd, QString currentUser,QString osCodename,QString availableSource);

    //改变source.list为kylin-update-server
    bool changeSourceListToKylinUpdateServer(QStringList lines);

    //函数：解决冲突
    bool configureDpkgByShell(bool queit);

    //wget下载软件包
    void copyFileToInstall(QString srcPath,QString appName,QString destDebname);

    // 安装单个应用
    bool instalOneApp(QString appName);

    //每日更新关闭
    bool dailyStartClose();

    //每日更新开启
    bool dailyStartOpen();

    //下载deb包
    void downDepPackage(QString appName);

    //退出dbus
    void Exit();

    //通过shell解决冲突
    bool fixConffileByShell(bool quiet);

    //获得依赖包
    QStringList getDependsPkgs(QString appName);


    //下载pkg列表
    bool Install(QStringList pkgNames);

    //安装和升级
    bool installAndUpgrade(QString pkgName);

    //更新软件源
    bool Update(bool quiet);

    //通过shell更新软件源
    bool updateByShell(bool quiet);

    //升级
    bool Upgrade(QStringList pkgNames);

    //单个升级
    bool upgradeOne(QString pkgName);

    //修改配置文件
    void modifyConf(QString path,QString group,QString key,QString value);

    //kill pid
    void killPid();

    //测试返回值
    int testReturnValue(int arg);

    //初始化cache
    void init_cache();

//dbus接口函数定义完毕





    //某个包是否已经安装
    bool checkIsInstalled(QString appName);


    //判断当前系统是否为龙芯4000，以及安装对应低版本的龙芯内核虚包
    bool checkLoongson3A4000();    


    // 获取更新信息
    QStringList getUpdateAppInfo(QString appName);

    //获取sinfo中source.list 将etc/apt/source.list设置为sinfo中[source.list]内容
    void getSourceListFromSinfo();
    QStringList sourcesList;

    //函数：获取下载的important和crucial列表
    void getInameAndCnameList();    //获取重要更新列表和紧急更新列表
    void getDesktopOrServer();     //获取当前系统是服务器还是桌面
    QString desktopOrServer;    //当前系统是服务器还是桌面操作系统

    QStringList inameList;  //重要更新列表
    QStringList cnameList; //紧急更新列表
    QStringList RUNLIST;   //运行列表




    QStringList ordinaryList;
    QStringList importantList;
    QStringList crucialList;

    QApt::Backend *m_backend;
    QApt::Package *m_package;


public slots:
    void getAptSignal(QString arg, QVariantMap map);

};


#endif // UPDATEDBUS_H
