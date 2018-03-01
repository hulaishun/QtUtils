#include <stdafx.h>
#include "TBMachine.h"

#include <QtCore/qstandardpaths.h>

CTBMachine::CTBMachine()
{

}

QString CTBMachine::GetCurUserName()
{
    QString strValue = "";
    strValue = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    // C:/Users/hulaishun
    // 取最后一个分段就是当前用户名称
    strValue = strValue.section("/",-1);

    return strValue;
}

//static
QString CTBMachine::GetAppDataPath(const QString strCurLoginedName /*= ""*/)
{
    QString strValue = strCurLoginedName.trimmed();
    if(strValue.size() <= 0)
    {
        strValue = GetCurUserName();
    }

    //格式:C:/Users/当前用户名称/AppData/Roaming
    strValue.prepend("C:/Users/");
    strValue.append("/AppData/Roaming");

    return strValue;
}
