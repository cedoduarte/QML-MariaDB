/**
 * @author carlosduarte.1@hotmail.com
 * @date march 11st 2021
 * @brief MySQL/MariaDB database handler
 * @file qmysqldatabasehandler.h
 *
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

#ifndef QMYSQLDATABASEHANDLER_H
#define QMYSQLDATABASEHANDLER_H

#include "qabstractdatabasehandler.h"
#include "qmysqlresult.h"

#include <mysql.h>

/** MySQL/MariaDB database manager */
class QMySqlDatabaseHandler : public QAbstractDatabaseHandler
{
    Q_OBJECT
public:
    /** constructor */
    explicit QMySqlDatabaseHandler(QObject *parent = nullptr);

    /** constructor */
    explicit QMySqlDatabaseHandler(unsigned port = 3306, //!< connection port
                                     const QString &host = "localhost", //!< server host
                                     const QString &username = "root", //!< username
                                     const QString &password = "root", //!< user's password
                                     const QString &databaseName = "", //!< database name
                                     QObject *parent = nullptr //!< qobject parent
    );

    /** destructor */
    virtual ~QMySqlDatabaseHandler();

    /** open database connection */
    bool open() override;

    /** close database connection */
    void close() override;

    /** get last error as string */
    QString errorString() const override;

    /** execute query */
    QMySqlResult query(const QString &sql) const;
private:
    MYSQL *m_mysql; //!< MySQL/MariaDB connection
};

#endif // QMYSQLDATABASEHANDLER_H
