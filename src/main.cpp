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

#include <QApplication>
#include <QStringList>
#include <QStandardPaths>
#include <fcntl.h>
#include <syslog.h>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(argv[1]);  //传入参数 判断是定时器拉起或手动打开
    w.show();

    // 文件锁形式添加vnc单例功能
    QStringList homePath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    //需要给文件锁加一个DISPLAY标识  QtSingleApplication-Name改为应用名，如kylin-update-manager
    int fd = open(QString(homePath.at(0) + "/.config/kylin-update-manager%1.lock").arg(getenv("DISPLAY")).toUtf8().data(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0) { exit(1); }
    if (lockf(fd, F_TLOCK, 0)) {
        syslog(LOG_ERR, "Can't lock single file, kylin-update-manager is already running!");
        exit(0);
    }



    return a.exec();
}
