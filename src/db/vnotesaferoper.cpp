/*
* Copyright (C) 2019 ~ 2019 UnionTech Software Technology Co.,Ltd.
*
* Author:     V4fr3e <V4fr3e@deepin.io>
*
* Maintainer: V4fr3e <liujinli@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "vnotesaferoper.h"
#include "common/datatypedef.h"
#include "db/dbvisitor.h"
#include "db/vnotedbmanager.h"

#include <DLog>

//const QStringList VNoteSaferOper::saferColumnsName = {
//    "id",
//    "folder_id",
//    "note_id",
//    "path",
//    "state",
//    "meta_data",
//    "create_time",
//};

VNoteSaferOper::VNoteSaferOper()
{

}

VNoteSaferOper::VNoteSaferOper(const VDataSafer &safer)
    :m_dataSafer(safer)
{

}

SafetyDatas *VNoteSaferOper::loadSafers()
{
    SafetyDatas* safers = new SafetyDatas();

    SaferQryDbVisitor folderVisitor(VNoteDbManager::instance()->getVNoteDb(), nullptr, safers);

    if (!VNoteDbManager::instance()->queryData(&folderVisitor) ) {
      qCritical() << "Query faild!";
    }

    return safers;
}

void VNoteSaferOper::addSafer(const VDataSafer &safer)
{
    if (safer.isValid()) {
        AddSaferDbVisitor addSaferVisitor(VNoteDbManager::instance()->getVNoteDb(), &safer, nullptr);

        if (Q_UNLIKELY(!VNoteDbManager::instance()->insertData(&addSaferVisitor))) {
            qInfo() << "Add safer failed:" << safer;
        }
    } else {
        qInfo() << "Invalid parameter:" << safer;
    }
}

void VNoteSaferOper::rmSafer(const VDataSafer &safer)
{
    if (safer.isValid()) {
        DelSaferDbVisitor delSaferVisitor(VNoteDbManager::instance()->getVNoteDb(), &safer, nullptr);

        if (Q_UNLIKELY(!VNoteDbManager::instance()->deleteData(&delSaferVisitor))) {
            qInfo() << "Delete safer failed:" << safer;
        }
    } else {
        qInfo() << "Invalid parameter:" << safer;
    }
}
