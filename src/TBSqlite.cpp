#include <stdafx.h>

#include "TBSqlite.h"

#include <QtCore/qdir.h>
#include <QtCore/qvariant.h>
#include <QtCore/qdebug.h>
#include <QtSql/qsqlerror.h>

CTBSqlite::CTBSqlite()
    :m_strDBFile("")
	,m_connectionName("")
{

}

CTBSqlite::~CTBSqlite()
{
    m_strDBFile = "";
    m_db.close();
}

void CTBSqlite::SetDBFile(QString strDBFile)
{
    m_strDBFile = strDBFile;
}

QString CTBSqlite::GetDBFile()
{
	return m_strDBFile;
}

void CTBSqlite::SetConnectionName(QString strConnectName)
{
	m_connectionName = strConnectName;
}

bool CTBSqlite::Open(const QString& strDBFile, const QString& strConnectionName /*= ""*/)
{
	//已经打开的话直接返回
	if (IsOpen())
	{
		return true;
	}

    m_strDBFile = "";
    if(strDBFile.trimmed().size() <= 0)
    {
        return false;
    }

    int iindex = -1;
    iindex = strDBFile.lastIndexOf("/");
    if(iindex <= 0)
    {
        iindex = strDBFile.lastIndexOf("\\");
    }
    if (iindex <= 0)
    {
        return false;
    }

    m_strDBFile = strDBFile;

    QString strPath = "";
    QString strFile = "";
    strPath = strDBFile.left(iindex);
    strFile = strDBFile.mid(iindex+1);

    QDir dirPath(strPath);
    if(!dirPath.exists())
    {
        dirPath.mkpath(strPath);
	}

	QString strConn = strConnectionName;
	if (strConn.isEmpty())
	{
		strConn = m_connectionName;
	}
	if (strConn.isEmpty())
	{
		strConn = m_strDBFile;
	}

	m_db = QSqlDatabase::addDatabase("QSQLITE", strConn);
    m_db.setDatabaseName(m_strDBFile);
	bool bopen = false;
	bopen = m_db.open();

	return bopen;
}

bool CTBSqlite::IsOpen()
{
    return m_db.isOpen();
}

void CTBSqlite::Close()
{
    m_db.close();
}

QSqlDatabase* CTBSqlite::GetDB()
{
    return &m_db;
}

bool CTBSqlite::Select(const QString& strSql, QSqlQuery& query)
{
    query.clear();

    QString str = strSql.trimmed().toUpper();
    //非查询语句直接返回0
    if(!str.startsWith("SELECT", Qt::CaseInsensitive))
    {
        return false;
    }

    if(!Reopen())
    {
        return false;
    }

    query = m_db.exec(strSql);

    return true;
}

bool CTBSqlite::NoSelect(const QString& strSql)
{
    QString str = strSql.trimmed().toUpper();
    //查询语句直接返回0
    if(str.startsWith("SELECT"), Qt::CaseInsensitive)
    {
        return false;
    }

    if(!Reopen())
    {
        return false;
    }


	bool bok = false;
	QSqlQuery query(m_db); 
	bok = query.exec(strSql);
	
	if (!bok)
	{
		QSqlError se = m_db.lastError();
		qDebug() << m_db.lastError().databaseText() << m_db.lastError().driverText() << m_db.lastError().nativeErrorCode();
	}

    return true;
}

bool CTBSqlite::IsExistTable(const QString& strTableName)
{
    QString strSql = "";
    strSql = QString("select count(*) from sqlite_master where type='table' and name='%1';").arg(strTableName);
    int iRow = SelectCount(strSql);

    return (iRow>0)?true:false;
}

bool CTBSqlite::IsExistColumn(const QString& strTableName, const QString& strColumnName)
{
    QString strSql = "";
    strSql = QString("select count(%1) from %2;").arg(strColumnName).arg(strTableName);
    int iRow = SelectCount(strSql);

    //列不存在-1，列存在无数据0，列存在有数据>0
    return (iRow<0)?false:true;
}

bool CTBSqlite::Reopen()
{
    if(!IsOpen())
    {
        return Open(m_strDBFile);
    }
    else
    {
        return true;
    }
}

int CTBSqlite::SelectCount(const QString& strSql)
{
    QString str = strSql.trimmed().toUpper();
    if(str.size() <= 0)
    {
        return -1;
    }

    //非查询语句直接返回0
    if(!str.startsWith("SELECT"),Qt::CaseInsensitive)
    {
        return -1;
    }

    if(str.indexOf("COUNT(") <= 0)
    {
        return -1;
    }

    if(!Reopen())
    {
        return -1;
    }

    QSqlQuery query = m_db.exec(strSql);

    int iRow = -1;
	while (query.next())
	{
		iRow = query.value(0).toInt();
	}
    

    return iRow;
}
