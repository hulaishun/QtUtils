#include <stdafx.h>

#include <QtCore/qfile.h>

#include "TBDir.h"
#include "TBFile.h"

CTBFile::CTBFile()
{

}

//static
bool CTBFile::Copy(QString strDestName, QString strSrcName)
{
    strDestName.trimmed();
    strDestName.replace("\\", "/");
    if(strDestName.endsWith("/"))
    {
        strDestName.chop(1);
    }

    strSrcName.trimmed();
    strSrcName.replace("\\", "/");

    //源文件不存在则返回
    if(!QFile::exists(strSrcName))
    {
        return false;
    }

    QString strPath = "";
    strPath = strDestName.left(strDestName.lastIndexOf("/"));
    //确保目录已创建，原有的目标文件已删除
    CTBDir::Mkpath(strPath);
    QFile::remove(strDestName);

    return QFile::copy(strSrcName, strDestName);
}

//static
bool CTBFile::Copy(QString strDestPath, QString strDestFile, QString strSrcName)
{
    strDestPath.trimmed();
    strDestPath.replace("\\", "/");
    if(strDestPath.endsWith("/"))
    {
        strDestPath.chop(1);
    }

    strSrcName.trimmed();
    strSrcName.replace("\\", "/");

    //源文件不存在则返回
    if(!QFile::exists(strSrcName))
    {
        return false;
    }

    //确保目录已创建，原有的目标文件已删除
    CTBDir::Mkpath(strDestPath);
    QString strDestName = strDestPath + "/" + strDestFile;
    QFile::remove(strDestName);

    return QFile::copy(strSrcName, strDestName);
}
