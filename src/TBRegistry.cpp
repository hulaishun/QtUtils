#include <stdafx.h>

#include "TBRegistry.h"

#include <QtCore/qsettings.h>

//extern
QString TB_HKEY_CLASSES_ROOT = "HKEY_CLASSES_ROOT";
//extern
QString TB_HKEY_CURRENT_USER = "HKEY_CURRENT_USER";
//extern
QString TB_HKEY_LOCAL_MACHINE = "HKEY_LOCAL_MACHINE";
//extern
QString TB_HKEY_USERS = "HKEY_USERS";
//extern
QString TB_HKEY_CURRENT_CONFIG = "HKEY_CURRENT_CONFIG";

CTBRegistry::CTBRegistry()
{

}

CTBRegistry::~CTBRegistry()
{

}


//static
QString CTBRegistry::ReadString(const QString& strName, const QString& strSubKey
                                , const QString strMainKey /*=TB_HKEY_LOCAL_MACHINE*/)
{
    QString strValue = "";

    if(!IsValidMainKey(strMainKey))
    {
        return strValue;
    }

    if(strName.size() <= 0 || strSubKey.size() <= 0)
    {
        return strValue;
    }

    QString strKey = strSubKey.trimmed();
    if(!strKey.startsWith("/") && !strKey.startsWith("\\"))
    {
        strKey = strMainKey + "/" + strKey;
    }
    else
    {
        strKey = strMainKey + strKey;
    }

    QSettings settings(strKey, QSettings::NativeFormat);

    strValue = settings.value(strName).toString();

    return strValue;
}

//static
long CTBRegistry::ReadLong(const QString& strName, const QString& strSubKey
                           , const QString strMainKey /*=TB_HKEY_LOCAL_MACHINE*/)
{
    long lValue = 0;

    if(!IsValidMainKey(strMainKey))
    {
        return lValue;
    }

    if(strName.size() <= 0 || strSubKey.size() <= 0)
    {
        return lValue;
    }

    QString strKey = strSubKey.trimmed();
    if(!strKey.startsWith("/") && !strKey.startsWith("\\"))
    {
        strKey = strMainKey + "/" + strKey;
    }
    else
    {
        strKey = strMainKey + strKey;
    }

    QSettings settings(strKey, QSettings::NativeFormat);

    lValue = (long)settings.value(strName).toLongLong();

    return lValue;
}

//static
void CTBRegistry::WriteString(const QString& strValue,const QString& strName
                              , const QString& strSubKey, const QString strMainKey /*=TB_HKEY_LOCAL_MACHINE*/)
{
    if(!IsValidMainKey(strMainKey))
    {
        return;
    }

    if(strName.size() <= 0 || strSubKey.size() <= 0)
    {
        return;
    }

    QString strKey = strSubKey.trimmed();
    if(!strKey.startsWith("/") && !strKey.startsWith("\\"))
    {
        strKey = strMainKey + "/" + strKey;
    }
    else
    {
        strKey = strMainKey + strKey;
    }

    QSettings settings(strKey, QSettings::NativeFormat);

    settings.setValue(strName, strValue);
}

//static
void CTBRegistry::WriteLong(long lValue,const QString& strName
                            , const QString& strSubKey, const QString strMainKey /*=TB_HKEY_LOCAL_MACHINE*/)
{
    if(!IsValidMainKey(strMainKey))
    {
        return;
    }

    if(strName.size() <= 0 || strSubKey.size() <= 0)
    {
        return;
    }

    QString strKey = strSubKey.trimmed();
    if(!strKey.startsWith("/") && !strKey.startsWith("\\"))
    {
        strKey = strMainKey + "/" + strKey;
    }
    else
    {
        strKey = strMainKey + strKey;
    }

    QSettings settings(strKey, QSettings::NativeFormat);

    settings.setValue(strName, lValue);
}

//static
bool CTBRegistry::IsValidMainKey(const QString& strMainKey)
{
    QString strKey = strMainKey.trimmed().toUpper();

    if(strKey.size() <= 0)
    {
        return false;
    }

    if (strKey !=TB_HKEY_CLASSES_ROOT
            && strKey !=TB_HKEY_CURRENT_CONFIG
            && strKey !=TB_HKEY_CURRENT_USER
            && strKey !=TB_HKEY_LOCAL_MACHINE
            && strKey !=TB_HKEY_USERS)
    {
        return false;
    }

    return true;
}
