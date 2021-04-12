#    Copyright (C) 2021  Carlos Enrique Duarte Ortiz (carlosduarte.1@hotmail.com)

#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.

QT += core
QT += gui
QT += quick
QT += quickcontrols2

CONFIG += c++11

HEADERS += \
    mydatabasemanager.h \
    qabstractdatabasehandler.h \
    qmysqldatabasehandler.h \
    qmysqlrecord.h \
    qmysqlresult.h \
    userobject.h

SOURCES += \
        main.cpp \
        mydatabasemanager.cpp \
        qabstractdatabasehandler.cpp \
        qmysqldatabasehandler.cpp \
        qmysqlrecord.cpp \
        userobject.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include($$PWD/3rdparty/mariadb/mariadb.pri)
