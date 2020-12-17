#include "appupdate.h"


AppUpdateWid::AppUpdateWid(QWidget *parent):QWidget(parent)
{
    updateAppUi();
    this->setObjectName("AppUpdateWid");

    updateAppStyle();
    changeUpdateStatue("500KB/s","90%");
}

void AppUpdateWid::changeUpdateStatue(QString speed, QString progress)
{
    appVersion->setText("正在下载... "+speed+" "+progress);
}

void AppUpdateWid::updateAppUi()
{
    smallHLayout = new QHBoxLayout(this);
    largeVLayout = new QVBoxLayout(this);
    appTitleWid = new QWidget(this);
    largeWidget = new QWidget(this);
    mainVLayout = new QVBoxLayout(this);

//    appTitleWid->setFixedHeight(100);
    appTitleWid->resize(560,100);


    appIcon = new QPushButton(this);
    appName = new QLabel(this);
    appVersion = new QLabel(this);

    appIcon->setFixedSize(32,32);

    appName->setText("麒麟音乐");

    appVersion->setText("可更新至：1.0.3");


    detaileInfo = new QPushButton(this);
    detaileInfo->setText("详情");

    updateAPPBtn = new QPushButton(this);
    updateAPPBtn->setText("更新");


    smallHLayout->addWidget(appIcon,0,Qt::AlignLeft);
    smallHLayout->addWidget(appName,Qt::AlignLeft);
    smallHLayout->addWidget(appVersion,0,Qt::AlignRight);
    smallHLayout->addSpacing(30);
    smallHLayout->addWidget(detaileInfo,0,Qt::AlignRight);
    smallHLayout->addSpacing(30);
    smallHLayout->addWidget(updateAPPBtn,0,Qt::AlignRight);

    smallHLayout->setMargin(10);
//    smallHLayout->setSpacing(10);

    appTitleWid->setLayout(smallHLayout);

    mainVLayout->addWidget(appTitleWid);
    mainVLayout->setMargin(0);
    mainVLayout->setSpacing(0);

    updateContent = new QLabel(largeWidget);
    updateContent->setStyleSheet("margin-left:10px;");
    updateContent->setText("1.xxxxxxxxxx\n2.xxxxxxxxxx\n3.xxxxxxxxxxx");


    updatelogBtn = new QPushButton(largeWidget);
    updatelogBtn->setText("更新日志");


//    QHBoxLayout *updateBtnLeft = new QHBoxLayout(largeWidget);
//    updateBtnLeft->addWidget(updatelogBtn);


    largeVLayout->addWidget(updateContent);
    largeVLayout->addWidget(updatelogBtn,0,Qt::AlignLeft);
    largeVLayout->setSpacing(10);
    largeVLayout->setContentsMargins(50,0,24,5);

    largeWidget->setLayout(largeVLayout);
//    largeWidget->setFixedHeight(80);

    mainVLayout->addWidget(largeWidget);
    largeWidget->hide();


    connect(detaileInfo,&QPushButton::clicked,this,&AppUpdateWid::showDetails);
    connect(updatelogBtn,&QPushButton::clicked,this,&AppUpdateWid::showUpdateLog);
    connect(updateAPPBtn,&QPushButton::clicked,this,&AppUpdateWid::cancelOrUpdate);

    this->setLayout(mainVLayout);

}
void AppUpdateWid::updateAppStyle()
{

    this->setStyleSheet("background:#F2F2F2;border-radius:6px;");


    appTitleWid->setStyleSheet("background:#F2F2F2;border-radius:6px;"
                               "width:560px;");

//    appIcon->setStyleSheet("background-color:grey;border-radius: 6px;");
    appIcon->setIconSize(QSize(30,30));


    appName->setStyleSheet("width: 56px;\
                           height: 20px;\
                           font-size: 14px;\
                           font-family: PingFangSC-Regular, PingFang SC;\
                           font-weight: 400;\
                           color: #000000;\
                           line-height: 20px;");

    appVersion->setStyleSheet("width: 115px;\
                              height: 20px;\
                              font-size: 14px;\
                              font-family: PingFangSC-Regular, PingFang SC;\
                              font-weight: 400;\
                              color: #000000;\
                              line-height: 20px;");

    detaileInfo->setStyleSheet("QPushButton{width: 28px;\
                               height: 20px;\
                               font-size: 14px;\
                               font-family: PingFangSC-Regular, PingFang SC;\
                               font-weight: 400;\
                               color: #000000;\
                               line-height: 20px;}"
                               "QPushButton::hover{color:#3790FA;}");


    updateAPPBtn->setFixedSize(80,36);
//    updateAPPBtn->setStyleSheet("background:");

//    updateAPPBtn->setStyleSheet("width: 80px;\
//                                height: 36px;\
//                                background: #FFFFFF;\
//                                border-radius: 6px;\
//                                font-size: 14px;\
//                                font-family: PingFangSC-Regular, PingFang SC;\
//                                font-weight: 400;\
//                                color: #000000;\
//                                line-height: 20px;");

    largeWidget->setStyleSheet("background:#F2F2F2;");



    updateContent->setStyleSheet("width: 347px;\
                                 height: 78px;\
                                 font-size: 14px;\
                                 font-family: PingFangSC-Regular, PingFang SC;\
                                 font-weight: 400;\
                                 color: rgba(0, 0, 0, 0.85);\
                                 line-height: 20px;");



    updatelogBtn->setStyleSheet("QPushButton{width: 56px;\
                             height: 20px;\
                             font-size: 14px;\
                             font-family: PingFangSC-Regular, PingFang SC;\
                             font-weight: 400;\
                             color: #3790FA;\
                             line-height: 20px;}"
                             "QPushButton::hover{width: 56px;\
                             height: 20px;\
                             font-size: 14px;\
                             text-decoration:underline;\
                             font-family: PingFangSC-Regular, PingFang SC;\
                             font-weight: 400;\
                             color: #3790FA;\
                             line-height: 20px}");

}



void AppUpdateWid::showDetails()
{
    if(largeWidget->isHidden())
    {
        largeWidget->show();
//        this->setFixedHeight(largeWidget->height()+10);
//        this->resize(600,160);
        detaileInfo->setText("收起");
        largeWidget->setStyleSheet("background:#F2F2F2;"
                                   "border-bottom-left-radius:6px;border-bottom-right-radius:6px;"
                                   "border-top-left-radius:0px;border-top-right-radius:0px;");
        appTitleWid->setStyleSheet("background:#F2F2F2;"
                                   "border-top-left-radius:6px;border-top-right-radius:6px;"
                                   "border-bottom-left-radius:0px;border-bottom-right-radius:0px;"
                                   "width:560px;");
    }
    else
    {
        largeWidget->hide();

//        this->resize(600,80);
        detaileInfo->setText("详情");
        appTitleWid->setStyleSheet("background:#F2F2F2;border-radius:6px;"
                                   "width:560px;");

    }
}

void AppUpdateWid::showUpdateLog()
{
    UpdateLog *updatelog1 = new UpdateLog();
    updatelog1->show();
}

void AppUpdateWid::cancelOrUpdate()
{
    if(updateAPPBtn->text() == "更新")
    {
        updateAPPBtn->setText("取消");
//        updateAPPBtn->setStyleSheet("background:#FFFFFF;");
    }
    else
    {
        updateAPPBtn->setText("更新");
    }
}


