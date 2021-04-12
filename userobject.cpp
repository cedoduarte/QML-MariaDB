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

#include "userobject.h"

#include <QDebug>

UserObject::UserObject(QObject *parent)
    : QObject(parent)
{
    // nothing to do here
}

UserObject::UserObject(const UserObject &other)
    : QObject(other.parent())
{
    *this = other;
}

UserObject::~UserObject()
{
    // nothing to do here
    qDebug() << "bye user";
}

void UserObject::operator=(const UserObject &other)
{
    m_id = other.m_id;
    m_name = other.m_name;
    m_lastname = other.m_lastname;
    m_genre = other.m_genre;
    m_birthyear = other.m_birthyear;
    m_email = other.m_email;
    m_passphrase = other.m_passphrase;
}

void UserObject::setId(const QString &id)
{
    if (m_id != id)
    {
        m_id = id;
        emit idChanged();
    }
}

void UserObject::setName(const QString &name)
{
    if (m_name != name)
    {
        m_name = name;
        emit nameChanged();
    }
}

void UserObject::setLastname(const QString &lastname)
{
    if (m_lastname != lastname)
    {
        m_lastname = lastname;
        emit lastnameChanged();
    }
}

void UserObject::setGenre(const QString &genre)
{
    if (m_genre != genre)
    {
        m_genre = genre;
        emit genreChanged();
    }
}

void UserObject::setBirthyear(const QString &birthyear)
{
    if (m_birthyear != birthyear)
    {
        m_birthyear = birthyear;
        emit birthyearChanged();
    }
}

void UserObject::setEmail(const QString &email)
{
    if (m_email != email)
    {
        m_email = email;
        emit emailChanged();
    }
}

void UserObject::setPassphrase(const QString &passphrase)
{
    if (m_passphrase != passphrase)
    {
        m_passphrase = passphrase;
        emit passphraseChanged();
    }
}
