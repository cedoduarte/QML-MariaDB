/**
 * @author carlosduarte.1@hotmail.com
 * @date march 11st 2021
 * @brief record
 * @file qmysqlrecord.cpp

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

#include "qmysqlrecord.h"

QString QMySqlRecord::value(const QString &fieldName) const
{
    std::map<QString, QString>::const_iterator i = m_record.find(fieldName);
    if (i != m_record.end())
    {
        return i->second;
    }
    return QString();
}

QString QMySqlRecord::value(int index) const
{
    return value(m_fieldNames.at(index));
}

void QMySqlRecord::clear()
{
    m_fieldNames.clear();
    m_record.clear();
}
