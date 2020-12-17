#!/usr/bin/env python
# -*- coding: utf-8 -*-

def hello(name):
    print("hello world this is python " + name)


import sqlite3
import os
from xdg import BaseDirectory as xdg

import gettext
gettext.textdomain("kylin-update-manager")
_ = gettext.gettext


UKSC_CACHE_DIR = os.path.join(xdg.xdg_cache_home, "uksc")
UKSC_DATA_DIR = "/usr/share/kylin-software-center/data"
KUM_DIR = "/usr/share/kylin-update-manager"


class DBService:

    def __init__(self):
        selfDB = os.path.join(KUM_DIR, "uksc.db")
        bakDB = os.path.join(UKSC_DATA_DIR, "uksc.db")
        usrDB = os.path.join(UKSC_CACHE_DIR, "uksc.db")

        if os.path.exists(usrDB):
            self.connect = sqlite3.connect(usrDB, check_same_thread=False)
        elif os.path.exists(bakDB):
            self.connect = sqlite3.connect(bakDB, check_same_thread=False)
        else:
            self.connect = sqlite3.connect(selfDB, check_same_thread=False)

        self.cursor = self.connect.cursor()

    #
    # 函数：获取中文包名
    # name：包名
    #
    def get_display_name_cn_by_name(self, name):
        self.cursor.execute("select display_name_cn from application where app_name=?", (name,))
        res = self.cursor.fetchall()
        for item in res:
            displayName = item[0]
            return displayName

    #
    # 函数：获取解释
    # name：包名
    #
    def get_description_by_name(self, name):
        self.cursor.execute("select description from application where app_name=?", (name,))
        res = self.cursor.fetchall()
        for item in res:
            description = item[0]
            return description


def main():
    db = DBService()
    print(db.get_display_name_cn_by_name("gnome-chess"))
    print(db.get_description_by_name("gnome-chess"))


if __name__ == '__main__':
    main()
