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


# MySQL/MariaDB on Android
android {
# includes
INCLUDEPATH += $$PWD/include/android

# link static libraries
LIBS += -L$$PWD/lib/android

# add dynamic link libraries to APK
}

# MySQL/MariaDB on Unix
unix:!android {
# link with dynamic link library
LIBS += -lmariadbclient
}

# MySQL/MariaDB on Windows
win32 {
# includes
INCLUDEPATH += $$PWD/include/win32

# link dynamic link libraries
LIBS += -L$$PWD/lib/win32
LIBS += -lmariadb
}
