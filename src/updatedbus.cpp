#include "updatedbus.h"
#include "ukscconn.h"

UpdateDbus* UpdateDbus::updateMutual = new UpdateDbus();
using namespace std;
UpdateDbus::UpdateDbus()
{

    m_backend = new QApt::Backend(this);
    m_backend->init();

    interface = new QDBusInterface(KYLIN_UPDATE_MANAGER_SERVICE,
                                   KYLIN_UPDATE_MANAGER_PATH,
                                   KYLIN_UPDATE_MANAGER_INTERFACE,
                                   QDBusConnection::systemBus());

//    QDBusConnection::sessionBus().connect(QString(),KYLIN_UPDATE_MANAGER_SERVICE,
//                                          KYLIN_UPDATE_MANAGER_PATH,
//                                          "kum_apt_signal",);

//    QDBusConnection::systemBus().connect(QString("org.freedesktop.NetworkManager"),
//                                         QString("/org/freedesktop/NetworkManager"),
//                                         QString("org.freedesktop.NetworkManager"),
//                                         QString("PropertiesChanged"), this, SLOT(onPropertiesChanged(QVariantMap) ) );
//    QDBusConnection::systemBus().connect(QString(KYLIN_UPDATE_MANAGER_SERVICE),
//                                          QString(KYLIN_UPDATE_MANAGER_PATH),
//                                          QString(KYLIN_UPDATE_MANAGER_INTERFACE),
//                                          QString("copy_finish"), this, SLOT(getAptSigna(string arg)));
    QDBusConnection::systemBus().connect(QString("cn.kylinos.KylinUpdateManager"), QString("/cn/kylinos/KylinUpdateManager"),
                                         QString("cn.kylinos.KylinUpdateManager"),
                                         QString("kum_apt_signal"), this, SLOT(getAptSignal(QString, QVariantMap)));

//    connect(interface, SIGNAL(kum_apt_signal(QString, QVariantMap)), this, SLOT(getAptSignal(QString, QVariantMap)));


//    qDebug() << "ukscConn->getInfoByName" << UKSCConn::ukscConn->getInfoByName("kylin-ipmsg");
    init_cache();

//    installAndUpgrade("kylin-ipmsg");
    // 初始化interface接口
//    getDesktopOrServer();
//    getSourceListFromSinfo();
//    getInameAndCnameList();

//    instalOneApp("kylin-ipmsg");

//    getUpdateAppInfo("kylin-ipmsg");
//    bool ischecked,test;

//    ischecked = checkIsInstalled("kylin-ipmsg");
//    qDebug() << "checkIsInstalled" << ischecked;

//    init_cache();
//    getDependsPkgs("kylin-ipmsg");


/*    QString testAppName = "kylin-ipmsg";
    qDebug() << "测试接口类型:" << getDependsPkgs(testAppName).value() */


//    test = checkLoongson3A4000();
//    qDebug() << "是否安装:" << ischecked;
//    qDebug() << "是否龙芯:" << test;




    /*

    Py_Initialize();
    if (Py_IsInitialized())
    {
          PyRun_SimpleString("import sys");
          PyRun_SimpleString("sys.path.append('/home/liujialin/.cache/kylin-update-manager/kum-python')");
          qDebug() << "sys.path.append('./')";

          PyObject *pModule = PyImport_ImportModule("dbservice");  //参数为Python脚本的文件名
          qDebug() << "PyImport_ImportModule";

          if (pModule)
          {
              PyObject* pDict = PyModule_GetDict(pModule);
              if(!pDict) {
                  printf("Cant find dictionary./n");
                  return;
              }
              qDebug() << "find dictionary";

              PyObject* pClassCalc = PyDict_GetItemString(pDict, "DBService");
              if (!pClassCalc) {
                  printf("Cant find calc class./n");
                  return;
              }
              qDebug() << "find calc class";

              //得到构造函数而不是类实例
              PyObject* pConstruct = PyInstanceMethod_New(pClassCalc);
              if (!pConstruct) {
                  printf("Cant find calc construct./n");
                  return;
              }
              qDebug() << "find calc construct";

              //实例化类得到类对象
              PyObject* pInstance=PyObject_CallObject(pConstruct,NULL);
              //调用对象的成员函数
              PyObject* pRet1=PyObject_CallMethod(pInstance,"get_display_name_cn_by_name","s","wps-office");
//              PyObject* pRet2=PyObject_CallMethod(pInstance,"test","i",10);
//              PyObject* pRet3=PyObject_CallMethod(pInstance,"get_a","");
//              PyObject* pRet4=PyObject_CallMethod(pInstance,"get_b","");

              if (!pRet1)
              {
                  printf("不能找到 pRet");
                  return;
              }
              qDebug() << "find pRet";

              //将Python调用的结果写回C++变量中
              char* info1;
              qDebug() << "QString info1";
//              int info2,info3,info4;
              PyArg_Parse(pRet1, "s", &info1);
              qDebug() << "PyArg_Parse";
//              PyArg_Parse(pRet2, "i", &info2);
//              PyArg_Parse(pRet3, "i", &info3);
//              PyArg_Parse(pRet4, "i", &info4);
              QString res = QString::fromUtf8(info1);
              qDebug()<< "=" << res;
//              qDebug()<<"result2="<<info2<<endl;
//              qDebug()<<"result3="<<info3<<endl;
//              qDebug()<<"result4="<<info4<<endl;
          }
          else
          {
              qDebug()<<QObject::tr("导入Python模块失败...");
          }
      }
      else
      {
          printf("Python环境初始化失败...\n");
    }
    Py_Finalize();
    return;


    /*
    Py_Initialize();   //初始化python环境
    if (!Py_IsInitialized()) {
        qDebug() << "初始化失败";
        return;   //初始化失败
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyObject *pModule = PyImport_ImportModule("dbservice");  //参数为Python脚本的文件名
    if (pModule)
    {
        PyObject* pDict = PyModule_GetDict(pModule);
        if(!pDict) {
          qDebug("Cant find dictionary./n");
          return;
        }
        PyObject* pClassCalc = PyDict_GetItemString(pDict, "DBService");
        if (!pClassCalc) {
          qDebug("Cant find calc class./n");
          return;
        }
        //得到构造函数而不是类实例
        PyObject* pConstruct = PyInstanceMethod_New(pClassCalc);
        if (!pConstruct) {
          qDebug("Cant find calc construct./n");
          return;
        }

        //实例化类得到类对象
        PyObject* pInstance=PyObject_CallObject(pConstruct,NULL);
        //调用对象的成员函数
        PyObject* pRet1=PyObject_CallMethod(pInstance,"get_display_name_cn_by_name","s","wps-office");
        //              PyObject* pRet2=PyObject_CallMethod(pInstance,"test","i",10);
        //              PyObject* pRet3=PyObject_CallMethod(pInstance,"get_a","");
        //              PyObject* pRet4=PyObject_CallMethod(pInstance,"get_b","");

        if (!pRet1)
        {
          qDebug("不能找到 pRet");
          return;
        }
        //将Python调用的结果写回C++变量中
        QString info1;
        //              int info2,info3,info4;
        PyArg_Parse(pRet1, "s", &info1);
        //              PyArg_Parse(pRet2, "i", &info2);
        //              PyArg_Parse(pRet3, "i", &info3);
        //              PyArg_Parse(pRet4, "i", &info4);
        qDebug()<<"="<< info1 << endl;
        //              qDebug()<<"result2="<<info2<<endl;
        //              qDebug()<<"result3="<<info3<<endl;
        //              qDebug()<<"result4="<<info4<<endl;
    }
    else
    {
      qDebug()<<QObject::tr("导入Python模块失败...");
    }
    Py_Finalize();
    */


    /*

    // pyhton test

    Py_Initialize();   //初始化python环境
    if (!Py_IsInitialized()) {
        return;   //初始化失败
    }



    //确定当前运行目录
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");


    //加载python文件
    PyObject* pModule = PyImport_ImportModule("dbservice");
    if (!pModule) {
        qDebug()<<"cant open python file";
        return;
    }


    //加载python方法
    PyObject* pFunHello = PyObject_GetAttrString(pModule,"hello");
    if (!pFunHello) {
        qDebug("get function hello failed");
        return;     //加载失败
    }

//    PyObject* pFungetdisplay = PyObject_GetAttrString(pModule,"get_display_name_cn_by_name");
//    if (!pFungetdisplay) {
//        qDebug("get function hello failed");
//        return;     //加载失败
//    }

    PyObject* args = PyTuple_New(1);
    PyObject *pstr1=Py_BuildValue("s","20"); //i means int
//    PyObject *pstr2=Py_BuildValue("s",30);
//    PyTuple_SetItem(args,"wps-office", pstr1);
    PyTuple_SetItem(args, 0, pstr1);

    PyObject_CallObject(pFunHello,args);

//    PyObject* pRet = PyObject_CallObject(pFunHello,args);
//    QString *reactName = "";
//    PyArg_Parse(pRet,"s",&reactName); //i means int

    //调用python方法
    PyObject_CallFunction(pFunHello,NULL);
    Py_Finalize();   //释放内存

    */




}

bool UpdateDbus::cancel(QString pkgName)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("cancel", pkgName);

    // replyStrreplyStr.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

// 关闭自动更新
bool UpdateDbus::autoStartClose()
{
    //调用关闭自动更新的dbus接口，保存了autostart_close函数的返回值  无参
    replyBool = interface->call("autostart_close");

    //判断返回值是否有效
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

bool UpdateDbus::autoStartOpen()
{
    //调用关闭自动更新的dbus接口，保存了autostart_close函数的返回值  无参
    replyBool = interface->call("autostart_open");

    //判断返回值是否有效
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

// 取消更新应用
void UpdateDbus::cancelDownloadApp(QString appName)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyStr = interface->call("cancel_download_app", appName);

    // replyStrreplyStr.value()作为返回值
    if (replyStr.isValid()) {
        qDebug() << replyStr.value();
        return ;
    }
    else{
        qDebug() << QString("Call failed");
    }
}

bool UpdateDbus::changeSourceListToDefault(QString serviceKey, QString pwd, QString currentUser, QString osCodename, QString availableSource)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("change_source_list_to_default", serviceKey,pwd,currentUser,osCodename,availableSource);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

bool UpdateDbus::changeSourceListToKylinUpdateServer(QStringList lines)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("change_source_list_to_kylin_update_server",lines);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//函数：解决冲突
bool UpdateDbus::configureDpkgByShell(bool queit)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("configure_dpkg_by_shell",queit);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//wget下载软件包
void UpdateDbus::copyFileToInstall(QString srcPath, QString appName, QString destDebname)
{
    replyStr = interface->call("copy_file_to_install",srcPath,appName,destDebname);
    // replyStrreplyStr.value()作为返回值
    if (replyStr.isValid()) {
        qDebug() << replyStr.value();
        return ;
    }
    else{
        qDebug() << QString("Call failed");
    }
}

// 安装单个应用
bool UpdateDbus::instalOneApp(QString appName)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("insone", appName);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//每日更新关闭
bool UpdateDbus::dailyStartClose()
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("dailystart_close");

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//每日更新开启
bool UpdateDbus::dailyStartOpen()
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("dailystart_open");

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//下载deb包
void UpdateDbus::downDepPackage(QString appName)
{
    replyStr = interface->call("down_dep_pkg",appName);
    // replyStrreplyStr.value()作为返回值
    if (replyStr.isValid()) {
        qDebug() << replyStr.value();
        return ;
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//退出dbus
void UpdateDbus::Exit()
{
    replyStr = interface->call("exit");
    // replyStrreplyStr.value()作为返回值
    if (replyStr.isValid()) {
        qDebug() << replyStr.value();
        return ;
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//通过shell解决冲突
bool UpdateDbus::fixConffileByShell(bool quiet)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("fix_conffile_by_shell",quiet);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

QStringList UpdateDbus::getDependsPkgs(QString appName)
{
//    qDebug() << appName ;

    replyStrList = interface->call("get_depends_pkgs",appName);
//    qDebug() << "程序执行" ;
    // replyStrreplyStr.value()作为返回值
    if (replyStrList.isValid()) {
//        qDebug() << replyStrList.value();
        return replyStrList.value();
    }
    else{
        qDebug() << QString("Call failed");
        return QStringList("");
    }
}

//下载pkg列表
bool UpdateDbus::Install(QStringList pkgNames)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("install",pkgNames);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//安装和升级
bool UpdateDbus::installAndUpgrade(QString pkgName)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("install_and_upgrade",pkgName);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//更新软件源
bool UpdateDbus::Update(bool quiet)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("update",quiet);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//通过shell更新软件源
bool UpdateDbus::updateByShell(bool quiet)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("update_by_shell",quiet);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//升级
bool UpdateDbus::Upgrade(QStringList pkgNames)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("upgrade",pkgNames);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//单个升级
bool UpdateDbus::upgradeOne(QString pkgName)
{
    // 有参数的情况下  传参调用dbus接口并保存返回值
    replyBool = interface->call("upone",pkgName);

    // 将reply.value()作为返回值
    if (replyBool.isValid()) {
        qDebug() << replyBool.value();
        return replyBool.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

void UpdateDbus::modifyConf(QString path, QString group, QString key, QString value)
{
    replyStr = interface->call("modify_conf",path,group,key,value);
    // replyStrreplyStr.value()作为返回值
    if (replyStr.isValid()) {
        qDebug() << replyStr.value();
        return ;
    }
    else{
        qDebug() << QString("Call failed");
    }
}

void UpdateDbus::killPid()
{
    replyStr = interface->call("kill_pid");
    // replyStrreplyStr.value()作为返回值
    if (replyStr.isValid()) {
        qDebug() << replyStr.value();
        return ;
    }
    else{
        qDebug() << QString("Call failed");
    }
}

int UpdateDbus::testReturnValue(int arg)
{
    replyInt = interface->call("test_return_value",arg);
    // replyStrreplyStr.value()作为返回值
    if (replyInt.isValid()) {
        qDebug() << replyInt.value();
        return replyInt.value();
    }
    else{
        qDebug() << QString("Call failed");
    }
}

//初始化cache
void UpdateDbus::init_cache()
{
    qDebug() <<"init_cache" << QString("Call failed");

    replyStr = interface->call("init_cache");

    qDebug() << QString("Call failed  init_");

    // replyStrreplyStr.value()作为返回值
    if (replyStr.isValid()) {
        qDebug() << replyStr.value();
        return ;
    }
    else{
        qDebug() << QString("Call failed init_cache");
    }
}

bool UpdateDbus::checkIsInstalled(QString appName)
{
    QProcess os(0);
    QStringList args;
    args.append("-l");
//    args.append("|");
    args.append("grep");
    args.append(appName);
    os.start("dpkg", args);
//    os.start("whereis ",args);
    os.waitForFinished(); //等待完成
//
    QString result = QString::fromLocal8Bit(os.readAllStandardOutput());
//    qDebug() << result;
    if(result.indexOf(appName) == -1)
    {
//        qDebug()<<QString::fromLocal8Bit(os.readAllStandardError());

        return false;
    }

    return true;
}

bool UpdateDbus::checkLoongson3A4000()
{
    QProcess os(0);
    QStringList args;
    args.append("grep");
    args.append("'Loongson-3A4000'");

    os.start("lscpu", args);

    os.waitForFinished(); //等待完成
//
    QString result = QString::fromLocal8Bit(os.readAllStandardOutput());
    qDebug()<<result;
    if(result.indexOf("Loongson-3A4000") == -1)
    {
//        qDebug()<<QString::fromLocal8Bit(os.readAllStandardError());

        return false;
    }

    return true;
}

// 获取更新信息
QStringList UpdateDbus::getUpdateAppInfo(QString appName)
{
    QStringList msg;
//    QString appName = "ukui-greeter";
    m_package = m_backend->package(appName);
    msg.append(m_package->version());
    msg.append(m_package->availableVersion());
    msg.append(m_package->changelogUrl().toString());
    if (!m_package == 0) {
        /*
        qDebug() << m_package->name()   //应用名或包名
         << " " << m_package->section()
         << " " << m_package->origin() //来源
//         << " " << m_package->availableInstalledSize()  //可用安装大小
//         << " " << m_package->maintainer()  //维护者
//         << " " << m_package->sourcePackage() //源包
         << " " << m_package->version()  //当前版本
//         << " " << m_package->downloadSize()  //下载大小
//         << " " << m_package->shortDescription()  //短描述
         << " " << m_package->availableVersion()  //可升级版本
         << " " << m_package->isInUpdatePhase()  //是否在可升级列表中
//         << " " << m_package->archives()
         << " " << m_package->availableVersions()  //可升级版本列表
//         << " " << m_package->architecture()  //系统架构  arm64等
         << " " << m_package->changelogUrl()  //changelog 地址
//         << " " << m_package->compareVersion("1.2.0-67","1.2.0-48")  //比较版本，v1比v2领先的版本数
//         << " " << m_package->currentInstalledSize()  //当前安装大小
//         << " " << m_package->homepage()  //主页地址
//         << " " << m_package->installedFilesList()  //下载文件列表
//         << " " << m_package->isInstalled()  //是否安装
//         << " " << m_package->md5Sum()  //MD5
//         << " " << m_package->requiredByList()  //必须的

//         << " " << m_package->longDescription();  //长描述
*/
        ;
        return msg;
    }

//    m_backend->

}

// 获取sinfo中source.list 将etc/apt/source.list设置为sinfo中[source.list]内容
void UpdateDbus::getSourceListFromSinfo()
{
//    QFile file("L:/qtpro/_qtApp/text/t.txt");
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QByteArray t = file.readAll();
//    ui->text_r->setText(QString(t));
//    file.close();
    QString sInfoPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/kylin/sinfo.206.juniper";

    qDebug() << "sInfoPath" << sInfoPath;

    QFile file(sInfoPath);
    if (!file.exists())
        return ;
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QByteArray t ;
    bool start = false;
    while (!file.atEnd())
    {
        t = file.readLine();
        QString lineStr = QString(t);

        if (start == true)
        {
            // 没有源
            if (lineStr.indexOf('[') != -1 || lineStr.simplified() == "" ||
                lineStr == NULL)
            {
                break;
            }
            else
            {
                QString source = "deb http://archive.kylinos.cn" + lineStr.simplified();
                sourcesList.append(source);
            }
        }
        if (lineStr.indexOf("[sources.list]") != -1)
        {

            start = true;
        }
    }

    file.close();
    qDebug() << "sourcesList" << sourcesList;

    return;


}

void UpdateDbus::getInameAndCnameList()
{

    QString sInfoPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/kylin/sinfo.206.juniper";
    qDebug() << "sInfoPath" << sInfoPath;

    QFile file(sInfoPath);
    if (!file.exists())
        return ;
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QByteArray t ;
    bool start = false;
    while (!file.atEnd())
    {
        t = file.readLine();
        QString lineStr = QString(t);

        if (start == true)
        {
            // 没有源
            if (lineStr.indexOf('[') != -1 || lineStr.simplified() == "" ||
                lineStr == NULL)
            {
                break;
            }
            else
            {
                if (lineStr.indexOf(",") != -1)
                {
                    QStringList lineStrList = lineStr.split(",");
                    if(lineStrList[1].simplified() == "run")
                    {
                        RUNLIST.append(lineStrList[0].simplified());
                    }
                    else
                    {
                        RUNLIST.append(lineStrList[1].simplified());
                    }
                    inameList.append(lineStrList[0].simplified());
                }
                else
                {
                    inameList.append(lineStr.simplified());
                }
            }
        }

        if (lineStr.indexOf("[important." + desktopOrServer + "]") != -1)
        {
            start = true;
        }
    }
    qDebug() << "inameList" << inameList;

    start = false;
    while (!file.atEnd())
    {

        t = file.readLine();
        QString lineStr = QString(t);


        if (start == true)
        {
            // 没有源
            if (lineStr.indexOf('[') != -1 || lineStr.simplified() == "" ||
                lineStr == NULL)
            {
                break;
            }
            else
            {
                if (lineStr.indexOf(",") != -1)
                {
                    QStringList lineStrList = lineStr.split(",");
                    if(lineStrList[1].simplified() == "run")
                    {
                        RUNLIST.append(lineStrList[0].simplified());
                    }
                    else
                    {
                        RUNLIST.append(lineStrList[1].simplified());
                    }
                    cnameList.append(lineStrList[0].simplified());
                }
                else
                {
                    cnameList.append(lineStr.simplified());
                }
            }
        }

        if (lineStr.indexOf("[crucial." + desktopOrServer + "]") != -1)
        {
            start = true;
        }

    }
    qDebug() << "cnameList" << cnameList;

    file.close();


    return;


}

void UpdateDbus::getDesktopOrServer()
{
    QSettings settings("/etc/.kyinfo", QSettings::IniFormat);
    settings.setIniCodec(QTextCodec::codecForName("utf-8"));
    settings.beginGroup("dist");
    QString data = settings.value("dist_id").toString().simplified();
    settings.endGroup();

    if (data.indexOf("server") != -1)
        desktopOrServer = "server";
    else
        desktopOrServer = "desktop";
}

void UpdateDbus::getAptSignal(QString arg, QVariantMap map)
{
    qDebug() << arg;

    QVariantMap::Iterator it;
    for (it = map.begin(); it != map.end(); ++it) {
        qDebug() << it.key().toLatin1().data();
        qDebug() << it.value().toString().toLatin1().data();
    }
}


AppMessage::AppMessage(QString appName)
{
    m_backend = new QApt::Backend();
    m_backend->init();

    m_package = m_backend->package(appName);

    if (!m_package == 0) {
        this->name    = m_package->name();
        this->section = m_package->section();
        this->origin  = m_package->origin();
        this->installedSize = QString::number(m_package->availableInstalledSize());
        this->maintainer = m_package->maintainer();
        this->source  = m_package->sourcePackage();
        this->version = m_package->version();
        this->packageSize = QString::number(m_package->downloadSize());
        this->shortDescription = m_package->shortDescription();
        this->longDescription  = m_package->longDescription();

        this->changelogUrl   = m_package->changelogUrl().toString();
        this->screenshotUrl  = m_package->screenshotUrl(QApt::Thumbnail).toString();
        this->supportedUntil = m_package->supportedUntil().toString("yyyy-MM-dd HH:mm:ss");

        qDebug() << "name" << name << "\n" <<
                    "section" << section << "\n" <<
                    "origin" << origin << "\n" <<
                    "installedSize" << installedSize << "\n" <<
                    "maintainer" << maintainer << "\n" <<
                    "source" << source << "\n" <<
                    "version" << version << "\n" <<
                    "packageSize" << packageSize << "\n" <<
                    "shortDescription" << shortDescription << "\n" <<
                    "longDescription" << longDescription << "\n" <<
                    "changelogUrl" << changelogUrl << "\n" <<
                    "screenshotUrl" << screenshotUrl << "\n" <<
                    "supportedUntil" << supportedUntil;

//        "%1 Installed, %2 upgradeable, %3 available"
//        m_backend->packageCount(QApt::Package::Installed);
//        m_backend->packageCount(QApt::Package::Upgradeable);
//        m_backend->packageCount();

//        "%1 To install, %2 to upgrade, %3 to remove"
//        m_backend->packageCount(QApt::Package::ToInstall);
//        m_backend->packageCount(QApt::Package::ToUpgrade);
//        m_backend->packageCount(QApt::Package::ToRemove);

//        connect(m_backend, SIGNAL(packageChanged()), this, SLOT(updateStatusBar()));
    }

    // 判断是否已经安装
    if (m_package->isInstalled()) {
        this->isInstalled = true;
    }

    // 判断是否可升级
    if (m_package->state() & QApt::Package::Upgradeable) {
        this->upgradeable = true;
    }
}

// 处理获取changelog
void AppMessage::getAppChangelog()
{
    QString keyword = "";
    QString fileName = "";
    QStringList fileNameList;

    fileNameList.append("/usr/share/doc/" + this->name + "/changelog.gz");
    fileNameList.append("/usr/share/doc/" + this->name + "/changelog.Debian.gz");

    // 判断changelog文件路径
    QFile file(fileNameList[0]);
    if (file.exists())
    {
        fileName = fileNameList[0];
    }
    else
    {
        QFile file2(fileNameList[1]);
        if (file2.exists())
        {
            fileName = fileNameList[1];
        }
    }

    // 此方法下载changelog失败
    QProcess os(0);
    QStringList args;

    args.append(this->name);
    args.append(" > /dev/null 2>&1");

    os.start("apt-get changelog", args);
    os.waitForFinished(); //等待完成

    // 解析本地changelog文件
    args.clear();
    args.append(fileName);

    os.start("zless", args);
    os.waitForFinished(); //等待完成

    QString result = QString::fromLocal8Bit(os.readAllStandardOutput());
//    qDebug() << result;
    getChangelog(result);

}

// 解析本地changelog
QString AppMessage::getChangelog(QString result)
{
    QStringList changelogList = result.split("\n");
}
