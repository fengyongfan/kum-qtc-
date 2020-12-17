#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QListWidget>
#include <QListWidgetItem>

#include "appupdate.h"
#include "switchbutton.h"

class TabWid : public QWidget
{
    Q_OBJECT
public:
    explicit TabWid(QWidget *parent = nullptr);

    void tabUI1();  //系统为最新
    void tabUI2();  //自动更新关闭
    void tabUI3();  //自动更新开启
    void allComponents(); //更新页面里所有组件


    void getAppUpdateMsg();   //加载所有应用的具体更新信息
    void setItemHeight();



//    void allBinding();  //更新页面里所有组件绑定

//    void updateSettings(); //更新设置页面

    //选项卡页面，具有更新和更新设置两个选项卡及对应界面
    QTabWidget *updateWidget;
    QWidget *updateTab;
    QWidget *updateSettingTab;
    QVBoxLayout *mainTabLayout;

    //更新页面布局
    QHBoxLayout *tab1HLayout;
    QWidget *systemWidget;
    QVBoxLayout *tab1VLayout;
    QScrollArea *scrollArea;


    //更新设置页面布局
//    QHBoxLayout *tab2HLayout;
    QVBoxLayout *tab2VLayout;

    //系统头像
    QLabel *systemPortraitLab;

    //更新按钮
    //自动更新关闭时 点击检查更新  检查更新之后变为现在更新或系统已经是最新的状态
    QPushButton *checkUpdateBtn;
    QPushButton *nowUpdateBtn;
    QPushButton *updateAllBtn;

    //三种状态下的版本信息   显示当前版本、可更新版本、或最新版本
    QLabel *versionInformationLab;
    QLabel *lastRefreshTime;
    QVBoxLayout *inforLayout;

    //应用更新列表
//    AppUpdateWid *appWid1[100];
//    AppUpdateWid *appWid2;
    QListWidget *appUpdateListWidget;
//    QListWidgetItem *appUpdateItem[100];






    // 更新设置页面组件
    SwitchButton *isAutoCheckSBtn;    //是否自动检查更新
    QWidget *isAutoCheckWidget;
    QLabel *isAutoCheckedLab;

    SwitchButton *isAutoDownloadSBtn;   //是否自动下载更新
    QWidget *isAutoDownloadWidget;
    QLabel *autoDownloadIntroLab;
    QLabel *autoDownloadLab;

    SwitchButton *isClearCacheSBtn;     //是否下载安装包后清除缓存
    QLabel *isClearCacheLab;
    QWidget *isClearCacheWidget;

    SwitchButton *intellMirrSourceSBtn;   //智能镜像源
    QLabel *intellMirrSourceLab;
    QWidget *intellMirrSourceWidget;
    QLabel *intellMirrSourceIntroLab;


    QPushButton *updateSourceSetting;
    int inumber = 0;

signals:
//    void send_Signal();
//    void parameterSignal(int i);


public slots:

    void updateNowBtnConnect();  //现在更新按钮绑定


private:



};

#endif // TABWIDGET_H
