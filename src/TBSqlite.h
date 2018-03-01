#ifndef TB_SQLITE_H
#define TB_SQLITE_H

#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlquery.h>

class QSqlQuery;


/**
 * @brief
 */
class CTBSqlite
{
public:
    CTBSqlite();
    ~CTBSqlite();

public:
    void SetDBFile(QString strDBFile);
	QString GetDBFile();
	void SetConnectionName(QString strConnectName);
    bool Open(const QString& strDBFile, const QString& strConnectionName = "");
    bool IsOpen();

    void Close();

    QSqlDatabase* GetDB();

    bool Select(const QString& strSql, QSqlQuery& query);

    bool NoSelect(const QString& strSql);

    bool IsExistTable(const QString& strTableName);

    bool IsExistColumn(const QString& strTableName, const QString& strColumnName);

private:
    bool Reopen();

public:
    int SelectCount(const QString& strSql);

private:
    QSqlDatabase        m_db;
    QString             m_strDBFile;
	QString				m_connectionName;
};

#endif // TB_SQLITE_H
