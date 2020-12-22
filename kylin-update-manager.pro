
QT += core gui widgets network dbus QApt sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# 项目名
TARGET = kylin-update-manager

# 添加.so库
#LIBS += /usr/lib/libtag.so
#LIBS += /usr/lib/libtag_c.so

# 适配窗口管理器圆角阴影
#QT += x11extras
#LIBS +=-lpthread
#LIBS +=-lX11 -lXrandr -lXinerama -lXi -lXcursor

# 添加.h库文件
#INCLUDEPATH += ./taglib

#添加python支持
#INCLUDEPATH += -I /usr/include/python3.5
#LIBS += /usr/lib/aarch64-linux-gnu/libpython3.5m.so.1 \

# 执行文件装载
target.path = /usr/bin
target.source += $$TARGET

# 应用图标装载
icon.path = /usr/share/pixmaps
icon.files = img/kylin-update-manager.png

# desktop文件装载
desktop.path = /usr/share/applications/
desktop.files = kylin-update-manager.desktop

# gsetting文件装载
schemes.files = data/org.kylin-update-manager-data.gschema.xml
schemes.path = /usr/share/glib-2.0/schemas/

# 安装
INSTALLS += target  \
            icon    \
            desktop \
            schemes

DEFINES += QT_DEPRECATED_WARNINGS

# 配置gsettings
CONFIG += link_pkgconfig
PKGCONFIG += gsettings-qt

SOURCES +=                  \
    src/appupdate.cpp \
    src/main.cpp            \
    src/mainwindow.cpp      \
    src/daemonipcdbus.cpp   \
    src/shadowwidget.cpp \
    src/switchbutton.cpp \
    src/updatedbus.cpp \
    src/updatelog.cpp \
    src/widgetstyle.cpp \
    src/tabwidget.cpp \
    src/pyconnect.cpp \
    src/ukscconn.cpp

HEADERS +=                  \
    src/appupdate.h \
    src/mainwindow.h        \
    src/daemonipcdbus.h     \
    src/shadowwidget.h \
    src/switchbutton.h \
    src/updatedbus.h \
    src/updatelog.h \
    src/widgetstyle.h \
    src/tabwidget.h \
    src/pyconnect.h \
    src/metatypes.h \
    src/ukscconn.h

# 图片资源路径
RESOURCES += \
    image.qrc

# desktop文件
DISTFILES += \
    kylin-update-manager.desktop \
    src/dbservice.py \
