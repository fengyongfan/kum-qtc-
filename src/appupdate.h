#ifndef APPUPDATE_H
#define APPUPDATE_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "updatelog.h"

class UpdateLog;

class AppUpdateWid : public QWidget
{
    Q_OBJECT
public:
    explicit AppUpdateWid(QWidget *parent = nullptr);


    //缩略界面
    QPushButton *appIcon;
    QLabel *appName;
    QLabel *appVersion;

    QPushButton *detaileInfo;
    QPushButton *updateAPPBtn;

    QWidget *appTitleWid;
    QHBoxLayout *smallHLayout;
    QVBoxLayout *largeVLayout;
    QWidget *largeWidget;
    QVBoxLayout *mainVLayout;

    UpdateLog *updatelog1;


    //展开界面
    QLabel *updateContent;  //更新内容
    QPushButton *updatelogBtn;

//    AppMsg *thisAppMessage;

    void changeUpdateStatue(QString speed,QString progress);



public slots:
    void showDetails();

    void showUpdateLog();

    void cancelOrUpdate();


private:

    void updateAppUi();
    void updateAppStyle();

};


class AppMsg
{
public:
    AppMsg() {}
    QString thisAppName = "";
//    QString NAME = "";
//    QString ICON = "";
    QString thisAppSize = "";
    int bytesize = 0;
    QString CANDIDATEVERSION = "";
    QString DESCRIPTION = "";
    QString STATUE = "";
    QString TIME = "";
    QString ARCHITECTURE = "";
    QString FULLVERSION = "";
    QString TYPE = "";
    QString availableVersion = "";
    QString changLogUrl = "";

};
#endif // APPUPDATE_H
