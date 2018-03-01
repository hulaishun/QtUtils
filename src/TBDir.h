#ifndef TB_DIR_H
#define TB_DIR_H

#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>


class CTBDir
{
private:
    CTBDir();

public:
    static void Mkpath(const QString& strPath);

    static QString GetUpPath(const QString& strPath, unsigned int iUpLevel = 1);

    static int GetSonFileCount(const QString& strPath);
    static int GetSonPathCount(const QString& strPath);

    static QStringList GetSonFileName(const QString& strPath);
    static QStringList GetSonPathName(const QString& strPath);

    static long GetAllSize(const QString& strPath);

    static int GetAllFileCount(const QString& strPath);
    static int GetAllPathCount(const QString& strPath);

    static QStringList GetAllFileName(const QString& strPath);
    static QStringList GetAllPathName(const QString& strPath);
};

#endif // TB_DIR_H
