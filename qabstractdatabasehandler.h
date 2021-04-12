/**
 * @author carlosduarte.1@hotmail.com
 * @date march 11st 2021
 * @brief abstract database handler
 * @file qabstractdatabasehandler.h
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

#ifndef QABSTRACTDATABASEHANDLER_H
#define QABSTRACTDATABASEHANDLER_H

#include <QObject>

/** abstract database handler */
class QAbstractDatabaseHandler : public QObject
{
    Q_OBJECT
public:
    /** constructor */
    explicit QAbstractDatabaseHandler(QObject *parent = nullptr);

    /** constructor */
    explicit QAbstractDatabaseHandler(unsigned port, //!< connection port
                                        const QString &host, //!< server host
                                        const QString &username, //!< username
                                        const QString &password, //!< user's password
                                        const QString &databaseName, //!< database name
                                        QObject *parent = nullptr //!< qobject parent
    );

    /** destructor */
    virtual ~QAbstractDatabaseHandler()
    {
        // nothing to do here
    }

    /** open database connection */
    virtual bool open() = 0;

    /** close database connection */
    virtual void close() = 0;

    /** get last error as string */
    virtual QString errorString() const = 0;

    /** set port */
    void setPort(unsigned port)
    {
        m_port = port;
    }

    /** set database name */
    void setDatabaseName(const QString &dbname)
    {
        m_databasName = dbname;
    }

    /** set user name */
    void setUsername(const QString &username)
    {
        m_username = username;
    }

    /** set password */
    void setPassword(const QString &password)
    {
        m_password = password;
    }

    /** set host */
    void setHost(const QString &host)
    {
        m_host = host;
    }

    /** set port */
    unsigned port() const
    {
        return m_port;
    }

    /** get database name */
    QString databaseName() const
    {
        return m_databasName;
    }

    /** get username */
    QString username() const
    {
        return m_username;
    }

    /** get password */
    QString password() const
    {
        return m_password;
    }

    /** get host */
    QString host() const
    {
        return m_host;
    }

    /** is database connection opened? */
    bool isOpen() const
    {
        return m_isOpen;
    }
protected:
    bool m_isOpen; //!< connection is open
    unsigned m_port; //!< connection port
    QString m_host; //!< server host address
    QString m_username; //!< userame
    QString m_password; //!< user's password
    QString m_databasName; //!< database name
};

#endif // QABSTRACTDATABASEHANDLER_H
