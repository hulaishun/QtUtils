#ifndef TB_URL_METHOD_H
#define TB_URL_METHOD_H

#include <QtCore/qstring.h>

//协议类型
enum EUrlProtocolType
{
    URL_PROTOCOL_TYPE_HTTP      = 1,            //http
    URL_PROTOCOL_TYPE_HTTPS     = 2,            //https
};

//请求方法
enum EUrlRequestMethod
{
    URL_REQUEST_METHOD_GET      = 1,            //get
    URL_REQUEST_METHOD_POST     = 2             //post
};

/**
 * @brief 推宝URL调用方法
 */
class CTBUrlMethod
{
public:
    CTBUrlMethod();
    ~CTBUrlMethod();

    CTBUrlMethod(const CTBUrlMethod& src);
    const CTBUrlMethod& operator=(const CTBUrlMethod& src);

    void Init();

    void Clear();

    bool IsValid();

    QString GetFullUrl();

public:
    int GetType();
    void SetType(int iType);

    QString GetAddress();
    void SetAddress(const QString& strAddress);

    int GetPort();
    void SetPort(int iPort);

    QString GetPath();
    void SetPath(const QString& strPath);

    int GetMethod();
    void SetMethod(int iMethod);

    QString GetParam();
    void SetParam(const QString& strParam);

private:
    int                 m_iType;                //协议类型，默认值为1(http)
    QString             m_strAddress;           //服务器主机地址,如www.baidu.com或对应的ip:14.215.177.38
    int                 m_iPort;                //服务器的端口，默认值为80
    QString             m_strPath;              //服务器的url路径，如/api/user/login.html
    int                 m_iMethod;              //请求方法，默认值为1(get)
    QString             m_strParam;             //url中的参数，一般格式为&k1=v1&k2=v2......&kn=vn
};

#endif // TB_URL_METHOD_H
