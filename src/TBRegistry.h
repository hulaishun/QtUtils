#ifndef TB_REGISTRY_H
#define TB_REGISTRY_H

#include <QtCore/qstring.h>

extern QString TB_HKEY_CLASSES_ROOT;
extern QString TB_HKEY_CURRENT_USER;
extern QString TB_HKEY_LOCAL_MACHINE;
extern QString TB_HKEY_USERS;
extern QString TB_HKEY_CURRENT_CONFIG;

class CTBRegistry
{
private:
    CTBRegistry();
    ~CTBRegistry();

public:
    static QString ReadString(const QString& strName, const QString& strSubKey
                              , const QString strMainKey =TB_HKEY_LOCAL_MACHINE);
    static long ReadLong(const QString& strName, const QString& strSubKey
                         , const QString strMainKey =TB_HKEY_LOCAL_MACHINE);

    static void WriteString(const QString& strValue, const QString& strName
                            , const QString& strSubKey, const QString strMainKey =TB_HKEY_LOCAL_MACHINE);
    static void WriteLong(long lValue, const QString& strName
                          , const QString& strSubKey, const QString strMainKey =TB_HKEY_LOCAL_MACHINE);

private:
    static bool IsValidMainKey(const QString& strMainKey);

};

#endif // TB_REGISTRY_H
