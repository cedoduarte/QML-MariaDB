/**
 * @author carlosduarte.1@hotmail.com
 * @date march 11st 2021
 * @brief abstract database handler
 * @file qabstractdatabasehandler.cpp

    Copyright (C) 2021  Carlos Enrique Duarte Ortiz (carlosduarte.1@hotmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "qabstractdatabasehandler.h"

QAbstractDatabaseHandler::QAbstractDatabaseHandler(QObject *parent)
    : QObject(parent)
{
    m_port = 0;
    m_isOpen = false;
}

QAbstractDatabaseHandler::QAbstractDatabaseHandler(unsigned port, // connection port
                                                     const QString &host, // server host
                                                     const QString &username, // username
                                                     const QString &password, // user's password
                                                     const QString &databaseName, // database name
                                                     QObject *parent // qobject parent
    ) : QObject(parent) {

    m_isOpen = false;
    m_port = port;
    m_host = host;
    m_username = username;
    m_password = password;
    m_databasName = databaseName;
}
