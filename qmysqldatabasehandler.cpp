/**
 * @author carlosduarte.1@hotmail.com
 * @date march 11st 2021
 * @brief MySQL/MariaDB database handler
 * @file qmysqldatabasehandler.cpp

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

#include "qmysqldatabasehandler.h"

#include <QDebug>

QMySqlDatabaseHandler::QMySqlDatabaseHandler(QObject *parent)
    : QAbstractDatabaseHandler(3306, "localhost", "root", "root", "", parent)
{
    m_mysql = mysql_init(nullptr);
}

QMySqlDatabaseHandler::QMySqlDatabaseHandler(unsigned port,
                                             const QString &host,
                                             const QString &username,
                                             const QString &password,
                                             const QString &databaseName,
                                             QObject *parent)
    : QAbstractDatabaseHandler(port, host, username, password, databaseName, parent)
{
    m_mysql = mysql_init(nullptr);
}

QMySqlDatabaseHandler::~QMySqlDatabaseHandler()
{
    mysql_close(m_mysql);
}

bool QMySqlDatabaseHandler::open()
{
    if (mysql_real_connect(m_mysql, // mysql interface
                           m_host.toStdString().c_str(), // host server address
                           m_username.toStdString().c_str(), // username
                           m_password.toStdString().c_str(), // password
                           m_databasName.toStdString().c_str(), // database name
                           m_port, // connection port
                           nullptr, // unix socket
                           0 // user flags
                           )
            == nullptr)
    {
        mysql_close(m_mysql);
        m_isOpen = false;
    }
    else
    {
        m_isOpen = true;
    }
    return m_isOpen;
}

void QMySqlDatabaseHandler::close()
{
    mysql_close(m_mysql);
    m_mysql = nullptr;
    m_isOpen = false;
}

QString QMySqlDatabaseHandler::errorString() const
{
    return mysql_error(m_mysql);
}

QMySqlResult QMySqlDatabaseHandler::query(const QString &sql) const
{
    QMySqlResult R; // result
    QMySqlRecord record; // record
    unsigned fieldCount = 0; // number of fields
    MYSQL_ROW row = nullptr; // row
    MYSQL_RES *result = nullptr; // mysql resul
    MYSQL_FIELD *field = nullptr; // field
    if (mysql_query(m_mysql, sql.toStdString().c_str()) == 0)
    {
        result = mysql_store_result(m_mysql);
        if (result != nullptr)
        {
            fieldCount = mysql_num_fields(result);
            if (fieldCount > 0)
            {
                row = mysql_fetch_row(result);
                while (row != nullptr)
                {
                    record.clear();
                    for (unsigned i = 0; i < fieldCount; ++i)
                    {
                        if (i == 0)
                        {
                            // populate column names
                            field = mysql_fetch_field(result);
                            while (field != nullptr)
                            {
                                R.m_fieldNames.append(field->name);
                                field = mysql_fetch_field(result);
                            }
                        }
                        if (row[i] != nullptr)
                        {
                            record.m_record[R.m_fieldNames[i]] = row[i];
                        }
                        else
                        {
                            record.m_record[R.m_fieldNames[i]] = "NULL";
                        }
                    }
                    R.m_rows.push_back(record);
                    row = mysql_fetch_row(result); // next
                }
            }
        }
    }
    return R;
}
