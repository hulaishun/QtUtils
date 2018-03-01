#ifndef TB_MACHINE_H
#define TB_MACHINE_H

#include <QtCore/qstring.h>

class CTBMachine
{
private:
    CTBMachine();

public:
    static QString GetCurUserName();
    static QString GetAppDataPath(const QString strCurLoginedName = "");
};

#endif // TB_MACHINE_H
