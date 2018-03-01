#include <stdafx.h>
#include "TBDir.h"

#include <QtCore/qdir.h>

CTBDir::CTBDir()
{

}

//static
void CTBDir::Mkpath(const QString& strPath)
{
    QDir dir(strPath);

    dir.mkpath(strPath);
}

//static
QString CTBDir::GetUpPath(const QString& strPath, unsigned int iUpLevel /*= */)
{
    QString strValue = strPath;
    strValue.replace("\\", "/");

    if(strValue.endsWith("/"))
    {
        strValue = strValue.left(strValue.size()-1);
    }

    int iindex = -1;
    if(iUpLevel > 10)
    {
        iUpLevel = 10;
    }
    for (int i = 0;i < (int)iUpLevel; i++)
    {
        iindex = strValue.lastIndexOf("/");
        if (iindex > 0)
        {
           strValue = strValue.left(iindex);
        }
    }

    return strValue;
}

//static
int CTBDir::GetSonFileCount(const QString& strPath)
{
    Q_UNUSED(strPath);
    int iValue = 0;
    //todo
    return iValue;
}

//static
int CTBDir::GetSonPathCount(const QString& strPath)
{
    Q_UNUSED(strPath);
    int iValue = 0;
    //todo
    return iValue;
}

//static
QStringList CTBDir::GetSonFileName(const QString& strPath)
{
    Q_UNUSED(strPath);
    QStringList slValue;
    //todo
    return slValue;
}

//static
QStringList CTBDir::GetSonPathName(const QString& strPath)
{
    Q_UNUSED(strPath);
    QStringList slValue;
    //todo
    return slValue;
}

//static
long CTBDir::GetAllSize(const QString& strPath)
{
    Q_UNUSED(strPath);
    long lSize = 0;
    //todo
    return lSize;
}

//static
int CTBDir::GetAllFileCount(const QString& strPath)
{
    Q_UNUSED(strPath);
    int iValue = 0;
    //todo
    return iValue;
}

//static
int CTBDir::GetAllPathCount(const QString& strPath)
{
    Q_UNUSED(strPath);
    int iValue = 0;
    //todo
    return iValue;
}

//static
QStringList CTBDir::GetAllFileName(const QString& strPath)
{
    Q_UNUSED(strPath);
    QStringList slValue;
    //todo
    return slValue;
}

//static
QStringList CTBDir::GetAllPathName(const QString& strPath)
{
    Q_UNUSED(strPath);
    QStringList slValue;
    //todo
    return slValue;
}
