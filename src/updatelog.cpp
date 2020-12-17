#include "updatelog.h"


UpdateLog::UpdateLog(QWidget *parent) : QWidget(parent)
{
    logUi();
    logStyle();

}
void UpdateLog::logUi()
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    this->setFixedSize(460,560);

    logVLayout = new QVBoxLayout(this);
    logMainLayout = new QVBoxLayout(this);

    logAppHLayout = new QHBoxLayout(this);
    logAppVLayout = new QVBoxLayout(this);

    logAppIcon = new QPushButton(this);
    logAppName = new QLabel(this);
    logAppVerson = new QLabel(this);

    logWidget = new QWidget(this);
    logAppWidget = new QWidget(this);

    logContent = new QTextEdit(this);
    logCloseBtn = new QPushButton(this);

    logAppName->setText("麒麟音乐更新日志");
    logAppVerson->setText("当前版本 1.0.2");
    logAppIcon->setFixedSize(48,48);

    //    logContent->setFixedSize(396,411);

    logCloseBtn->setFixedSize(30,30);

    logContent->setReadOnly(true);
    logContent->append("1.新增了录音列表，录音文件编辑功功能\n2.修复了插入耳机无法检测到设备进行录音\n3.修复了部分界面ui\n");
    logContent->append("1.新增了录音列表，录音文件编辑功功能\n2.修复了插入耳机无法检测到设备进行录音\n3.修复了部分界面ui\n");

    logContent->append("1.新增了录音列表，录音文件编辑功功能\n2.修复了插入耳机无法检测到设备进行录音\n3.修复了部分界面ui\n");

    logContent->append("1.新增了录音列表，录音文件编辑功功能\n2.修复了插入耳机无法检测到设备进行录音\n3.修复了部分界面ui\n");

    logContent->append("1.新增了录音列表，录音文件编辑功功能\n2.修复了插入耳机无法检测到设备进行录音\n3.修复了部分界面ui\n");




    logAppVLayout->addWidget(logAppName);
    logAppVLayout->addWidget(logAppVerson);
    logAppVLayout->setMargin(0);
    logAppVLayout->setSpacing(0);

    logAppHLayout->addWidget(logAppIcon);
    logAppHLayout->addLayout(logAppVLayout);
    logAppHLayout->setMargin(0);
    logAppHLayout->setSpacing(8);


    logAppWidget->setLayout(logAppHLayout);



    logVLayout->addWidget(logCloseBtn,0,Qt::AlignTop|Qt::AlignRight);
    logVLayout->addWidget(logAppWidget);
    logVLayout->addSpacing(12);
    logVLayout->addWidget(logContent);
    logVLayout->setContentsMargins(24,0,24,24);
//    logVLayout->setMargin(0);
    logVLayout->setSpacing(0);







    connect(logCloseBtn,&QPushButton::clicked,this,&UpdateLog::close);

    logWidget->setLayout(logVLayout);

//    logWidget->setStyleSheet("border-radius:12px;");

    logMainLayout->addWidget(logWidget);
    logMainLayout->setMargin(5);
    logMainLayout->setSpacing(0);

//    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(this);
//    effect->setOffset(0, 0);          //设置向哪个方向产生阴影效果(dx,dy)，特别地，(0,0)代表向四周发散
//    effect->setColor(Qt::black);       //设置阴影颜色，也可以setColor(QColor(220,220,220))
//    effect->setBlurRadius(30);        //设定阴影的模糊半径，数值越大越模糊
//    logWidget->setGraphicsEffect(effect);

    this->setLayout(logMainLayout);
    this->setStyleSheet("border-radius:12px;");
}

void UpdateLog::logStyle()
{


    logAppVerson->setStyleSheet("width: 100px;\
                                height: 20px;\
                                font-size: 14px;\
                                font-family: PingFangSC-Regular, PingFang SC;\
                                font-weight: 400;\
                                color: rgba(0, 0, 0, 0.85);\
                                line-height: 20px;");

    logAppName->setStyleSheet("width: 144px;\
                              height: 25px;\
                              font-size: 18px;\
                              font-family: PingFangSC-Medium, PingFang SC;\
                              font-weight: 500;\
                              color: rgba(0, 0, 0, 0.85);\
                              line-height: 25px;");

    logCloseBtn->setStyleSheet("border-image:url(:/image/close.png)");
    logAppIcon->setStyleSheet("width: 48px;\
                              height: 48px;\
                              background: #D8D8D8;\
                              border-radius: 6px;\
                              border: 1px solid #979797;");
    logContent->setStyleSheet("width: 396px;\
                              height: 411px;\
                              background: #F2F2F2;\
                              border-radius: 6px;");

    logWidget->setStyleSheet("width: 460px;\
                            height: 560px;\
                            background: #FFFFFF;\
                            border-radius: 12px;");
}

// 实现圆角阴影效果
void UpdateLog::paintEvent(QPaintEvent *event)
{
    WidgetStyle::paintEvent(event, this);
}

//void UpdateLog::closeUpdateLog()
//{
//    this->close();
//}
