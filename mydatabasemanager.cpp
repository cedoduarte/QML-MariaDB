/*
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

#include "mydatabasemanager.h"

MyDatabaseManager::MyDatabaseManager(QObject *parent)
    : QObject(parent)
{
    m_mysql = new QMySqlDatabaseHandler(this);    
    m_mysql->setHost("localhost");
    m_mysql->setUsername("root");
    m_mysql->setPassword("cedo");
    m_mysql->setDatabaseName("qmlmariadb");
    m_mysql->setPort(3306);
    m_mysql->open();
}

MyDatabaseManager::~MyDatabaseManager()
{
    m_mysql->close();
}

QObjectList MyDatabaseManager::getUsers()
{
    QObjectList users;
    if (m_mysql->isOpen())
    {
        QMySqlResult R = m_mysql->query("select * from quser");
        std::vector<QMySqlRecord> rows = R.records();
        std::for_each(rows.begin(), rows.end(), [&](const QMySqlRecord &row)
        {
            UserObject *U = new UserObject(this);
            U->setBirthyear(row.value("birthyear"));
            U->setEmail(row.value("email"));
            U->setGenre(row.value("genre"));
            U->setId(row.value("id"));
            U->setLastname(row.value("lastname"));
            U->setName(row.value("name"));
            U->setPassphrase(row.value("passphrase"));
            users.append(U);
        });
    }
    return users;
}
