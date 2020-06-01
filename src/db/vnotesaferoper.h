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
#ifndef VNOTESAFEROPER_H
#define VNOTESAFEROPER_H

#include "common/datatypedef.h"

class VNoteSaferOper
{
public:
    VNoteSaferOper();
    VNoteSaferOper(const VDataSafer& safer);

    SafetyDatas* loadSafers();

    void addSafer(const VDataSafer& safer);
    void rmSafer(const VDataSafer& safer);
protected:
    VDataSafer m_dataSafer;
};

#endif // VNOTESAFEROPER_H
