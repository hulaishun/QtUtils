#ifndef TB_FILE_H
#define TB_FILE_H

#include <QtCore/qstring.h>

class CTBFile
{
private:
    CTBFile();

public:
    static bool Copy(QString strDestName, QString strSrcName);

    static bool Copy(QString strDestPath, QString strDestFile, QString strSrcName);
};

#endif // TB_FILE_H
