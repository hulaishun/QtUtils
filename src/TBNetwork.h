#ifndef TB_NETWORK_H
#define TB_NETWORK_H

#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>

class CTBNetwork
{
private:
    CTBNetwork();

public:
    static QString GetIp();
    static QStringList GetIpList();

    static QString GetIp4();
    static QStringList GetIp4List();

    static QString GetIp6();
    static QStringList GetIp6List();

    static QString GetMac();
    static QStringList GetMacList();

    static QString GetMac4();
    static QStringList GetMac4List();

    static QString GetMac6();
    static QStringList GetMac6List();

	//获取网络错误原因
	static QString GetReplyErrorName(int iErrorCode);
};

#endif // TB_NETWORK_H
