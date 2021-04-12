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

#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <QObject>
#include <QMetaType>

class UserObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
    Q_PROPERTY(QString genre READ genre WRITE setGenre NOTIFY genreChanged)
    Q_PROPERTY(QString birthyear READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString passphrase READ passphrase WRITE setPassphrase NOTIFY passphraseChanged)
public:
    explicit UserObject(QObject *parent = nullptr);
    explicit UserObject(const UserObject &other);
    void operator=(const UserObject &other);
    virtual ~UserObject();

    void setId(const QString &id);
    void setName(const QString &name);
    void setLastname(const QString &lastname);
    void setGenre(const QString &genre);
    void setBirthyear(const QString &birthyear);
    void setEmail(const QString &email);
    void setPassphrase(const QString &passphrase);

    QString id() const
    {
        return m_id;
    }

    QString name() const
    {
        return m_name;
    }

    QString lastname() const
    {
        return m_lastname;
    }

    QString genre() const
    {
        return m_genre;
    }

    QString birthyear() const
    {
        return m_birthyear;
    }

    QString email() const
    {
        return m_email;
    }

    QString passphrase() const
    {
        return m_passphrase;
    }
signals:
    void idChanged();
    void nameChanged();
    void lastnameChanged();
    void genreChanged();
    void birthyearChanged();
    void emailChanged();
    void passphraseChanged();
private:
    QString m_id;
    QString m_name;
    QString m_lastname;
    QString m_genre;
    QString m_birthyear;
    QString m_email;
    QString m_passphrase;
};
Q_DECLARE_METATYPE(UserObject)

#endif // USEROBJECT_H
