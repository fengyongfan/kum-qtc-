#include "tabwidget.h"

TabWid::TabWid(QWidget *parent):QWidget(parent)
{

    this->resize(620,580);
//    this->setStyleSheet("background-color:red;");

    allComponents();



    if(isAutoCheckSBtn->isChecked() == false)
    {
        tabUI1();
    }
    else if(isAutoCheckSBtn->isChecked() == true)
    {
        tabUI2();
    }



}

void TabWid::allComponents()
{
    mainTabLayout = new QVBoxLayout(this);  //整个页面的主布局

    updateWidget = new QTabWidget(this);   //标签页
//    updateWidget->resize(500,580);
    scrollArea = new QScrollArea(this);

    updateTab = new QWidget(this);  //更新页面
    tab1VLayout = new QVBoxLayout(updateTab);
    systemWidget = new QWidget(updateTab);
    systemPortraitLab = new QLabel(systemWidget);


//    appWid1 = new AppUpdateWid(updateTab);
//    appWid2 = new AppUpdateWid(updateTab);
    appUpdateListWidget = new QListWidget(updateTab);
    appUpdateListWidget->setStyleSheet("QListWidget::Item{padding-top:4px; padding-bottom:4px;}"
                                       "QListWidget::item:selected{background:#FFFFFF;}");



    tab1VLayout->addWidget(systemWidget,0,Qt::AlignTop);
    tab1VLayout->addWidget(appUpdateListWidget);

    getAppUpdateMsg();
//    updateTab->setLayout(tab1VLayout);



    scrollArea->setWidget(updateTab);
    scrollArea->setFrameStyle(0);
//    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true);

//    tab1VLayout->addWidget(appWid1,0,Qt::AlignTop);
//    tab1VLayout->addWidget(appWid2,1,Qt::AlignTop);

    systemWidget->setStyleSheet("width: 560px;\
                                height: 120px;\
                                background: #F2F2F2;\
                                border-radius: 6px;");
    systemWidget->setFixedHeight(120);

    updateSettingTab = new QWidget(this);  //更新设置界面
    tab2VLayout = new QVBoxLayout(updateSettingTab);
//    tab2HLayout = new QHBoxLayout(updateSettingTab);

    isAutoCheckWidget = new QWidget(updateSettingTab);
    isAutoCheckedLab = new QLabel(isAutoCheckWidget);
    isAutoCheckWidget->setFixedHeight(50);
    isAutoCheckedLab->setText("自动检查更新");
    isAutoCheckedLab->setStyleSheet("width: 84px;\
                                    height: 20px;\
                                    font-size: 14px;\
                                    font-family: PingFangSC-Regular, PingFang SC;\
                                    font-weight: 400;\
                                    color: rgba(0, 0, 0, 0.85);\
                                    line-height: 20px;");
    isAutoCheckSBtn = new SwitchButton(isAutoCheckWidget);
    QHBoxLayout *autoCheckLayout = new QHBoxLayout(isAutoCheckWidget);

    autoCheckLayout->addWidget(isAutoCheckedLab,0,Qt::AlignLeft);
    autoCheckLayout->addWidget(isAutoCheckSBtn,1,Qt::AlignRight);
    autoCheckLayout->setSpacing(0);
//    autoCheckLayout->setMargin(0);

    isAutoCheckWidget->setStyleSheet("width: 560px;\
                                     height: 50px;\
                                     background: #F2F2F2;\
                                     border-radius:6px;");



    intellMirrSourceWidget = new QWidget(this);  //智能镜像源页面
    intellMirrSourceWidget->setFixedHeight(70);
    intellMirrSourceWidget->setStyleSheet("width: 560px;\
                                          height: 70px;\
                                          background: #F2F2F2;\
                                          border-radius: 6px;");
    intellMirrSourceLab = new QLabel(intellMirrSourceWidget);
    intellMirrSourceLab->setText("智能镜像源");
    intellMirrSourceLab->setStyleSheet("width: 84px;\
                                    height: 20px;\
                                    font-size: 14px;\
                                    font-family: PingFangSC-Regular, PingFang SC;\
                                    font-weight: 400;\
                                    color: rgba(0, 0, 0, 0.85);\
                                    line-height: 20px;");
    intellMirrSourceIntroLab = new QLabel(intellMirrSourceWidget);
    intellMirrSourceIntroLab->setText("开启智能镜像源会自动匹配响应最快的镜像源");
    intellMirrSourceIntroLab->setStyleSheet("width: 238px;\
                                            height: 20px;\
                                            font-size: 13px;\
                                            font-family: PingFangSC-Regular, PingFang SC;\
                                            font-weight: 400;\
                                            color: rgba(0, 0, 0, 0.5);\
                                            line-height: 20px;");


    intellMirrSourceSBtn = new SwitchButton(intellMirrSourceWidget);
    QHBoxLayout *intellMirrSourceLayout = new QHBoxLayout(intellMirrSourceWidget);

    QWidget *mirrIntro = new QWidget(intellMirrSourceWidget);
    QVBoxLayout *mirrIntrolay = new QVBoxLayout(mirrIntro);

    mirrIntrolay->addWidget(intellMirrSourceLab);
    mirrIntrolay->addWidget(intellMirrSourceIntroLab);
    mirrIntrolay->setMargin(0);
    mirrIntrolay->setSpacing(0);

    intellMirrSourceLayout->addWidget(mirrIntro,0,Qt::AlignLeft);
    intellMirrSourceLayout->addWidget(intellMirrSourceSBtn,1,Qt::AlignRight);

    intellMirrSourceWidget->setLayout(intellMirrSourceLayout);


    /****************************************************/


    isAutoDownloadWidget = new QWidget(this);  //是否自动下载更新
    isAutoDownloadWidget->setFixedHeight(70);
    isAutoDownloadWidget->setStyleSheet("width: 560px;\
                                          height: 70px;\
                                          background: #F2F2F2;\
                                          border-radius: 6px;");
    autoDownloadLab = new QLabel(isAutoDownloadWidget);
    autoDownloadLab->setText("自动下载更新");
    autoDownloadLab->setStyleSheet("width: 84px;\
                                    height: 20px;\
                                    font-size: 14px;\
                                    font-family: PingFangSC-Regular, PingFang SC;\
                                    font-weight: 400;\
                                    color: rgba(0, 0, 0, 0.85);\
                                    line-height: 20px;");
    autoDownloadIntroLab = new QLabel(isAutoDownloadWidget);
    autoDownloadIntroLab->setText("系统会在有网络的情况下自动下载更新");
    autoDownloadIntroLab->setStyleSheet("width: 238px;\
                                            height: 20px;\
                                            font-size: 13px;\
                                            font-family: PingFangSC-Regular, PingFang SC;\
                                            font-weight: 400;\
                                            color: rgba(0, 0, 0, 0.5);\
                                            line-height: 20px;");


    isAutoDownloadSBtn = new SwitchButton(isAutoDownloadWidget);
    QHBoxLayout *isAutoDownloadLayout = new QHBoxLayout(isAutoDownloadWidget);

    QWidget *isAutoDownload = new QWidget(isAutoDownloadWidget);
    QVBoxLayout *isAutoDownloadlay = new QVBoxLayout(isAutoDownload);

    isAutoDownloadlay->addWidget(autoDownloadLab);
    isAutoDownloadlay->addWidget(autoDownloadIntroLab);
    isAutoDownloadlay->setMargin(0);
    isAutoDownloadlay->setSpacing(0);

    isAutoDownloadLayout->addWidget(isAutoDownload,0,Qt::AlignLeft);
    isAutoDownloadLayout->addWidget(isAutoDownloadSBtn,1,Qt::AlignRight);

    isAutoDownloadWidget->setLayout(isAutoDownloadLayout);





//是否下载安装包后清除缓存

    isClearCacheWidget = new QWidget(updateSettingTab);
    isClearCacheLab = new QLabel(isClearCacheWidget);
    isClearCacheWidget->setFixedHeight(50);
    isClearCacheLab->setText("下载后清除软件包缓存");
    isClearCacheLab->setStyleSheet("width: 84px;\
                                    height: 20px;\
                                    font-size: 14px;\
                                    font-family: PingFangSC-Regular, PingFang SC;\
                                    font-weight: 400;\
                                    color: rgba(0, 0, 0, 0.85);\
                                    line-height: 20px;");
    isClearCacheSBtn = new SwitchButton(isClearCacheWidget);
    QHBoxLayout *clearCachLayout = new QHBoxLayout(isClearCacheWidget);

    clearCachLayout->addWidget(isClearCacheLab,0,Qt::AlignLeft);
    clearCachLayout->addWidget(isClearCacheSBtn,1,Qt::AlignRight);
    clearCachLayout->setSpacing(0);
//    autoCheckLayout->setMargin(0);

    isClearCacheWidget->setStyleSheet("width: 560px;\
                                     height: 50px;\
                                     background: #F2F2F2;\
                                     border-radius:6px;");
/**************/

    updateSourceSetting = new QPushButton(updateSettingTab);
    updateSourceSetting->setText("更新源设置");
    updateSourceSetting->setStyleSheet("width: 120px;\
                                       font-size: 14px;\
                                       color: rgba(0, 0, 0, 0.85);\
                                       height: 36px;\
                                       background: #F2F2F2;\
                                       border-radius: 6px;");





    tab2VLayout->addWidget(isAutoCheckWidget,Qt::AlignTop);
    tab2VLayout->addWidget(isAutoDownloadWidget,0,Qt::AlignTop);
//    tab2VLayout->addWidget(isClearCacheWidget,Qt::AlignTop);
//    tab2VLayout->addWidget(intellMirrSourceWidget,Qt::AlignTop);
//    tab2VLayout->addSpacing(8);
//    tab2VLayout->addWidget(updateSourceSetting,0,Qt::AlignLeft|Qt::AlignTop);

    isClearCacheWidget->hide();
    intellMirrSourceWidget->hide();
    updateSourceSetting->hide();



    mainTabLayout->addWidget(updateWidget);
//    updateWidget->addTab()

//    updateWidget->addTab(updateTab,"更新");
    updateWidget->addTab(scrollArea,"更新");
    updateWidget->addTab(updateSettingTab,"更新设置");


    updateWidget->setStyleSheet("QTabWidget::tab-bar{alignment:center;}"
                                "QTabBar::tab{width: 120px;\
                                height: 36px;\
                                color:rgba(0, 0, 0, 0.85);\
                                background: #E7E7E7;\
                                border-radius: 6px;\
                                border: 0px solid #999999;\
                                font-size: 14px;\
                                font-family: PingFangSC-Regular, PingFang SC;\
                                font-weight: 400;\
                                color: rgba(0, 0, 0, 0.85);\
                                line-height: 20px;}"
                                "QTabBar::tab:selected{background: #3790FA;\
                                color:rgba(255, 255, 255, 0.85);}");


this->setLayout(mainTabLayout);
}

void TabWid::getAppUpdateMsg()
{
    int cnum = UpdateDbus::updateMutual->cnameList.size();
    int inum = UpdateDbus::updateMutual->inameList.size();

    QStringList thisInameList = UpdateDbus::updateMutual->inameList;

    for(inumber = 0; inumber < inum; inumber++)
    {
        QString app_name = thisInameList[inumber];
        AppUpdateWid *appWidget = new AppUpdateWid(updateTab);
        appWidget->appName->setText(app_name);
        appWidget->appIcon->setIcon(QIcon::fromTheme(app_name));
        QListWidgetItem *item1 = new QListWidgetItem(appUpdateListWidget);
//        item1->setSizeHint(QSize(100,80));
        item1->setSizeHint(QSize(0,160));
        appUpdateListWidget->setItemWidget(item1,appWidget);
//        connect(appWidget->detaileInfo,&QPushButton::clicked,this,&TabWid::setItemHeight);

    }




}

void TabWid::updateNowBtnConnect()
{
    //    emit parameterSignal(inumber);
    QString impName =  UpdateDbus::updateMutual->inameList[inumber];
    bool isupdate = UpdateDbus::updateMutual->instalOneApp(impName);
//    qDebug() << "impName:" << impName << "  :" << isupdate;

}

void TabWid::setItemHeight()
{
//    QWidget itemWid = appUpdateListWidget->itemWidget(item(0));
//    detailInfoBtnList = itemWid.findChildren<QPushButton*>();
//    detailInfoBtnList[]
}

void TabWid::tabUI1()
{
    systemPortraitLab = new QLabel(systemWidget);
    tab1HLayout = new QHBoxLayout(systemWidget);
    systemPortraitLab->setFixedSize(68,68);
    systemPortraitLab->setStyleSheet("border-image:url(:/image/refresh.png);");

    inforLayout = new QVBoxLayout(systemWidget);
    lastRefreshTime = new QLabel(systemWidget);
    lastRefreshTime->setText("上次更新时间：2020.11.7 14:56");
    lastRefreshTime->setStyleSheet("width: 202px;\
                                   height: 20px;\
                                   font-size: 14px;\
                                   font-family: PingFangSC-Regular, PingFang SC;\
                                   font-weight: 400;\
                                   color: rgba(0, 0, 0, 0.85);\
                                   line-height: 20px;");


    versionInformationLab = new QLabel(systemWidget);
    versionInformationLab->setText("当前系统版本：2004.1 LTS");
    versionInformationLab->setStyleSheet("width: 176px;\
                                         height: 22px;\
                                         font-size: 16px;\
                                         font-family: PingFangSC-Medium, PingFang SC;\
                                         font-weight: 500;\
                                         color: rgba(0, 0, 0, 0.85);\
                                         line-height: 22px;"
                                         );


    inforLayout->addWidget(versionInformationLab);
    inforLayout->addWidget(lastRefreshTime);
    QWidget *inforWidget = new QWidget(systemWidget);
    inforWidget->setLayout(inforLayout);

    updateAllBtn = new QPushButton(systemWidget);
    updateAllBtn->setText("检测更新");
    updateAllBtn->setStyleSheet("width: 120px;\
                                height: 36px;\
                                background: #FFFFFF;\
                                border-radius: 6px;\
                                border: 0px solid #979797;"
                                "font-size: 14px;\
                                font-family: PingFangSC-Regular, PingFang SC;\
                                font-weight: 400;\
                                color: #000000;\
                                line-height: 20px;\
                                ");

    tab1HLayout->addWidget(systemPortraitLab,0,Qt::AlignLeft);
    tab1HLayout->addWidget(inforWidget,Qt::AlignLeft|Qt::AlignTop);
    tab1HLayout->addWidget(updateAllBtn);

    tab1HLayout->setMargin(20);
    tab1HLayout->setSpacing(20);




}

void TabWid::tabUI2()
{
    systemPortraitLab = new QLabel(systemWidget);
    tab1HLayout = new QHBoxLayout(systemWidget);
    systemPortraitLab->setFixedSize(68,68);
    systemPortraitLab->setStyleSheet("border-image:url(:/image/refresh.png);");

    inforLayout = new QVBoxLayout(systemWidget);
    lastRefreshTime = new QLabel(systemWidget);
    lastRefreshTime->setText("上次更新时间：2020.11.7 14:56");
    lastRefreshTime->setStyleSheet("width: 202px;\
                                   height: 20px;\
                                   font-size: 14px;\
                                   font-family: PingFangSC-Regular, PingFang SC;\
                                   font-weight: 400;\
                                   color: rgba(0, 0, 0, 0.85);\
                                   line-height: 20px;");


    versionInformationLab = new QLabel(systemWidget);
    versionInformationLab->setText("当前系统版本：2004.1 LTS");
    versionInformationLab->setStyleSheet("width: 176px;\
                                         height: 22px;\
                                         font-size: 16px;\
                                         font-family: PingFangSC-Medium, PingFang SC;\
                                         font-weight: 500;\
                                         color: rgba(0, 0, 0, 0.85);\
                                         line-height: 22px;"
                                         );


    inforLayout->addWidget(versionInformationLab);
    inforLayout->addWidget(lastRefreshTime);
    QWidget *inforWidget = new QWidget(systemWidget);
    inforWidget->setLayout(inforLayout);

    updateAllBtn = new QPushButton(systemWidget);
    updateAllBtn->setText("正在更新");
    updateAllBtn->setStyleSheet("width: 120px;\
                                height: 36px;\
                                background: #FFFFFF;\
                                border-radius: 6px;\
                                border: 0px solid #979797;"
                                "font-size: 14px;\
                                font-family: PingFangSC-Regular, PingFang SC;\
                                font-weight: 400;\
                                color: #000000;\
                                line-height: 20px;\
                                ");

    tab1HLayout->addWidget(systemPortraitLab,0,Qt::AlignLeft);
    tab1HLayout->addWidget(inforWidget,Qt::AlignLeft|Qt::AlignTop);
    tab1HLayout->addWidget(updateAllBtn);

    tab1HLayout->setMargin(20);
    tab1HLayout->setSpacing(20);

}

void TabWid::tabUI3()
{
    systemPortraitLab = new QLabel(systemWidget);
    tab1HLayout = new QHBoxLayout(systemWidget);
    systemPortraitLab->setFixedSize(68,68);
    systemPortraitLab->setStyleSheet("border-image:url(:/image/refresh.png);");

    inforLayout = new QVBoxLayout(systemWidget);
    lastRefreshTime = new QLabel(systemWidget);
    lastRefreshTime->setText("上次更新时间：2020.11.7 14:56");
    lastRefreshTime->setStyleSheet("width: 202px;\
                                   height: 20px;\
                                   font-size: 14px;\
                                   font-family: PingFangSC-Regular, PingFang SC;\
                                   font-weight: 400;\
                                   color: rgba(0, 0, 0, 0.85);\
                                   line-height: 20px;");


    versionInformationLab = new QLabel(systemWidget);
    versionInformationLab->setText("当前系统版本：2004.1 LTS");
    versionInformationLab->setStyleSheet("width: 176px;\
                                         height: 22px;\
                                         font-size: 16px;\
                                         font-family: PingFangSC-Medium, PingFang SC;\
                                         font-weight: 500;\
                                         color: rgba(0, 0, 0, 0.85);\
                                         line-height: 22px;"
                                         );


    inforLayout->addWidget(versionInformationLab);
    inforLayout->addWidget(lastRefreshTime);
    QWidget *inforWidget = new QWidget(systemWidget);
    inforWidget->setLayout(inforLayout);

    updateAllBtn = new QPushButton(systemWidget);
    updateAllBtn->setText("检测更新");
    updateAllBtn->hide();
    updateAllBtn->setStyleSheet("width: 120px;\
                                height: 36px;\
                                background: #FFFFFF;\
                                border-radius: 6px;\
                                border: 0px solid #979797;"
                                "font-size: 14px;\
                                font-family: PingFangSC-Regular, PingFang SC;\
                                font-weight: 400;\
                                color: #000000;\
                                line-height: 20px;\
                                ");

    tab1HLayout->addWidget(systemPortraitLab,0,Qt::AlignLeft);
    tab1HLayout->addWidget(inforWidget,Qt::AlignLeft|Qt::AlignTop);
    tab1HLayout->addWidget(updateAllBtn);

    tab1HLayout->setMargin(20);
    tab1HLayout->setSpacing(20);

}

