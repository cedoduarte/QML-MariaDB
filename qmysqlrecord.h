/**
 * @author carlosduarte.1@hotmail.com
 * @date march 11st 2021
 * @brief record
 * @file qmysqlrecord.h
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

#ifndef QMYSQLRECORD_H
#define QMYSQLRECORD_H

#include <map>
#include <QVariant>

/** record or row */
class QMySqlRecord
{
    friend class QMySqlDatabaseHandler;
public:
    /** destructor */
    virtual ~QMySqlRecord()
    {
        // nothing to do here
    }

    /** get value */
    QString value(const QString &fieldName) const;
    QString value(int index) const;

    /** get field count */
    unsigned fieldCount() const
    {
        return m_record.size();
    }

    /** get field names */
    QStringList fieldNames() const
    {
        return m_fieldNames;
    }
private:
    /** destructor */
    explicit QMySqlRecord()
    {
        // nothing to do here
    }

    /** clear content */
    void clear();

    std::map<QString /* fieldName */,
             QString /* value */> m_record; //!< record map

    QStringList m_fieldNames; //!< field names
};

#endif // QMYSQLRECORD_H
