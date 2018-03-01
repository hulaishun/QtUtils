#include <stdafx.h>
#include "TBUrlMethod.h"

CTBUrlMethod::CTBUrlMethod()
    :m_iType(URL_PROTOCOL_TYPE_HTTP)
    ,m_strAddress("")
    ,m_iPort(80)
    ,m_strPath("")
    ,m_iMethod(URL_REQUEST_METHOD_GET)
    ,m_strParam("")
{
}

CTBUrlMethod::~CTBUrlMethod()
{

}

CTBUrlMethod::CTBUrlMethod(const CTBUrlMethod& src)
{
    if(this == &src)
    {
        return;
    }

    m_iType = src.m_iType;
    m_strAddress = src.m_strAddress;
    m_iPort = src.m_iPort;
    m_strPath = src.m_strPath;
    m_iMethod = src.m_iMethod;
    m_strParam = src.m_strParam;
}

const CTBUrlMethod& CTBUrlMethod::operator=(const CTBUrlMethod& src)
{
    if(this == &src)
    {
        return *this;
    }

    m_iType = src.m_iType;
    m_strAddress = src.m_strAddress;
    m_iPort = src.m_iPort;
    m_strPath = src.m_strPath;
    m_iMethod = src.m_iMethod;
    m_strParam = src.m_strParam;

    return *this;
}

void CTBUrlMethod::Init()
{
    m_iType = URL_PROTOCOL_TYPE_HTTP;
    m_strAddress = "";
    m_iPort = 80;
    m_strPath = "";
    m_iMethod = URL_REQUEST_METHOD_GET;
    m_strParam = "";
}

void CTBUrlMethod::Clear()
{
    m_iType = URL_PROTOCOL_TYPE_HTTP;
    m_strAddress = "";
    m_iPort = 80;
    m_strPath = "";
    m_iMethod = URL_REQUEST_METHOD_GET;
    m_strParam = "";
}

bool CTBUrlMethod::IsValid()
{
    return true;
}

QString CTBUrlMethod::GetFullUrl()
{
    QString strUrl = "";
    //Æ´½Óurl
    if(!m_strAddress.startsWith("http"))
    {
        if(URL_PROTOCOL_TYPE_HTTP == m_iType)
        {
            strUrl.append("http://");
        }

        if(URL_PROTOCOL_TYPE_HTTPS == m_iType)
        {
            strUrl.append("https://");
        }
    }

    strUrl.append(m_strAddress);

    if(80 != m_iPort)
    {
        strUrl.append(QString(":%1").arg(m_iPort));
    }

    if(!m_strPath.isEmpty())
    {
        strUrl.append(m_strPath);
    }

    if(!m_strParam.isEmpty())
    {
        strUrl.append(QString("?%1").arg(m_strParam));
    }

    return strUrl;
}

int CTBUrlMethod::GetType()
{
    return m_iType;
}

void CTBUrlMethod::SetType(int iType)
{
    m_iType = iType;
}

QString CTBUrlMethod::GetAddress()
{
    return m_strAddress;
}

void CTBUrlMethod::SetAddress(const QString& strAddress)
{
    m_strAddress = strAddress;
}

int CTBUrlMethod::GetPort()
{
    return m_iPort;
}

void CTBUrlMethod::SetPort(int iPort)
{
    m_iPort = iPort;
}

QString CTBUrlMethod::GetPath()
{
    return m_strPath;
}

void CTBUrlMethod::SetPath(const QString& strPath)
{
    m_strPath = strPath;
}

int CTBUrlMethod::GetMethod()
{
    return m_iMethod;
}

void CTBUrlMethod::SetMethod(int iMethod)
{
    m_iMethod = iMethod;
}

QString CTBUrlMethod::GetParam()
{
    return m_strParam;
}

void CTBUrlMethod::SetParam(const QString& strParam)
{
    m_strParam = strParam;
}
