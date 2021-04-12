/**
 * @author carlosduarte.1@hotmail.com
 * @date march 11st 2021
 * @brief result
 * @file qmysqlresult.h
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

#ifndef QMYSQLRESULT_H
#define QMYSQLRESULT_H

#include "qmysqlrecord.h"

/** query result */
class QMySqlResult
{
    friend class QMySqlDatabaseHandler;
public:
    /** destructor */
    virtual ~QMySqlResult()
    {
        // nothing to do here
    }

    /** get records */
    const std::vector<QMySqlRecord> &records() const
    {
        return m_rows;
    }

    /** get number of records */
    unsigned recordCount() const
    {
        return m_rows.size();
    }

    /** get field names */
    QStringList fieldNames() const
    {
        return m_fieldNames;
    }

    /** has content? */
    bool hasContent() const
    {
        return m_rows.size() > 0;
    }

    /** get number of fields */
    unsigned fieldCount() const
    {
        return m_fieldNames.size();
    }
private:
    /** constructor */
    explicit QMySqlResult()
    {
        // nothing to do here
    }

    std::vector<QMySqlRecord> m_rows; //!< records
    QStringList m_fieldNames; //!< field names
};

#endif // QMYSQLRESULT_H
