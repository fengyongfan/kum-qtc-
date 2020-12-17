/*
 * Copyright (C) 2020, KylinSoft Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include "metatypes.h"

MainWindow::MainWindow(QString arg,QWidget *parent)
    : QMainWindow(parent)
{
    AppMessage appMessage = new AppMessage("kylin-ipmsg");

    qDBusRegisterMetaType<CustomData>();
    // 界面获取焦点
    setFocus();

    // 用户手册功能
    mDaemonIpcDbus = new DaemonIpcDbus();

    // 初始化组件
    setWidgetUi();

    // 初始化样式
    setWidgetStyle();

    my_time =new QTimer;
    my_time->start(100);
    connect(my_time,&QTimer::timeout,this,&MainWindow::getDBusService);


}

MainWindow::~MainWindow()
{

}

// 初始化组件
void MainWindow::setWidgetUi()
{
    // 窗口设置
    // 无边框、界面置顶
//     this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    // 窗体透明
//    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setStyleSheet("background-color:#FFFFFF;");


    // 设置图标
    // this->setWindowTitle("麒麟计算器");
    // this->setWindowIcon(QIcon("/usr/share/icons/ukui-icon-theme-default/64x64/apps/calc.png"));

    // 整体界面widget
    mainWid = new QWidget(this);

    // 整体界面布局
    mainLayout = new QVBoxLayout();

    // 设置整体界面布局
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    myTabwidget = new TabWid(this);
//    myTabwidget->resize(620,580);

    mainLayout->addWidget(myTabwidget);


    this->mainWid->setLayout(mainLayout);

    // 将mainWid作为整体界面
    this->setCentralWidget(mainWid);
    this->show();
}

// 初始化样式
void MainWindow::setWidgetStyle()
{
    // 设置窗体大小
    this->resize(WINDOWW, WINDOWH);

    //在屏幕中央显示
    QRect availableGeometry = qApp->primaryScreen()->availableGeometry();
    this->move((availableGeometry.width() - this->width())/2, (availableGeometry.height() - this->height())/2);

    // 读取主题颜色配置文件 监听主题颜色改变
    if(QGSettings::isSchemaInstalled(FITTHEMEWINDOW))
    {
        gSettings = new QGSettings(FITTHEMEWINDOW);
        if(gSettings->get("style-name").toString() == "ukui-dark" || gSettings->get("style-name").toString() == "ukui-black"){
            WidgetStyle::themeColor = 1;
        }
        else
        {
            WidgetStyle::themeColor = 0;
        }

        connect(gSettings,&QGSettings::changed,this,[=]()
        {
            qDebug() << "主题颜色" << gSettings->get("style-name").toString();
            if(gSettings->get("style-name").toString() == "ukui-dark" || gSettings->get("style-name").toString() == "ukui-black"){
                WidgetStyle::themeColor = 1;
                changeDarkTheme();
            }
            else
            {
                WidgetStyle::themeColor = 0;
                changeLightTheme();
            }

        });
    }

    this->mainWid->setObjectName("mainWid");
    this->mainWid->setStyleSheet("#mainWid{}");
}

// 切换深色模式
void MainWindow::changeDarkTheme()
{
    this->mainWid->setStyleSheet("#mainWid{background-color:black;}");
}

// 切换浅色模式
void MainWindow::changeLightTheme()
{
    this->mainWid->setStyleSheet("#mainWid{background-color:white;}");
}

// 实现键盘响应
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // F1快捷键打开用户手册
    if (event->key() == Qt::Key_F1) {
        if (!mDaemonIpcDbus->daemonIsNotRunning()){
            // F1快捷键打开用户手册，如kylin-update-manager
            mDaemonIpcDbus->showGuide("kylin-update-manager");
        }
    }
}

void MainWindow::getDBusService()
{
    qDebug() << "MainWindow" << UpdateDbus::updateMutual->checkIsInstalled("kylin-ipmsg");
    my_time->stop();
}

