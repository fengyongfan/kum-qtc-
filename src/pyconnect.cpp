#include "pyconnect.h"
/*
PyConnect::PyConnect(QWidget *parent)
{
    Py_Initialize();
    if (Py_IsInitialized())
    {
          PyRun_SimpleString("import sys");
          PyRun_SimpleString("sys.path.append('/home/liujialin/.cache/kylin-update-manager/kum-python')");
          qDebug() << "sys.path.append('./')";

          pModule = PyImport_ImportModule("dbservice");  //参数为Python脚本的文件名
          qDebug() << "PyImport_ImportModule";

          if (pModule)
          {
              pDict = PyModule_GetDict(pModule);
              if(!pDict) {
                  printf("Cant find dictionary./n");
                  return;
              }
              qDebug() << "find dictionary";

              pClassCalc = PyDict_GetItemString(pDict, "DBService");
              if (!pClassCalc) {
                  printf("Cant find calc class./n");
                  return;
              }
              qDebug() << "find calc class";

              //得到构造函数而不是类实例
              pConstruct = PyInstanceMethod_New(pClassCalc);
              if (!pConstruct) {
                  printf("Cant find calc construct./n");
                  return;
              }
              qDebug() << "find calc construct";

              //实例化类得到类对象
              pInstance=PyObject_CallObject(pConstruct,NULL);
              //调用对象的成员函数
              pRet1=PyObject_CallMethod(pInstance,"get_display_name_cn_by_name","s","wps-office");
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
}
*/
