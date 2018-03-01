#include <stdafx.h>
#include "TBNetwork.h"

#include <QtCore/qsettings.h>
#include <QtNetwork/qnetworkinterface.h>
#include <QtNetwork/qnetworkreply.h>
#include <QtCore/quuid.h>

CTBNetwork::CTBNetwork()
{

}

//static
QString CTBNetwork::GetIp()
{
    QString strRet = "";
    //todo
    return strRet;
}

//static
QStringList CTBNetwork::GetIpList()
{
    QStringList slRet;
    //todo
    return slRet;
}

//static
QString CTBNetwork::GetIp4()
{
    QString strRet = "";
    //todo
    return strRet;
}

//static
QStringList CTBNetwork::GetIp4List()
{
    QStringList slRet;
    //todo
    return slRet;
}

//static
QString CTBNetwork::GetIp6()
{
    QString strRet = "";
    //todo
    return strRet;
}

//static
QStringList CTBNetwork::GetIp6List()
{
    QStringList slRet;
    //todo
    return slRet;
}

//static
QString CTBNetwork::GetMac()
{
    QString strRet = "";
    //todo
    return strRet;
}

//static
QStringList CTBNetwork::GetMacList()
{
    QStringList slRet;
    //todo
    return slRet;
}

//static
QString CTBNetwork::GetMac4()
{
	static QString strMacAddress;
	if (!strMacAddress.isEmpty())
	{
		return strMacAddress;
	}

	QSettings set;
	QString strKey = "clientguid";
	strMacAddress = set.value(strKey).toString();
	if (strMacAddress.trimmed().isEmpty())
	{
		QList<QNetworkInterface> listInterface = QNetworkInterface::allInterfaces();
		for (auto &ni : listInterface)
		{
			if (ni.flags().testFlag(QNetworkInterface::IsUp)
				&& !ni.flags().testFlag(QNetworkInterface::IsLoopBack)  //过滤掉本地回环地址、没有开启的地址
				&& !(ni.humanReadableName().contains("VMware", Qt::CaseInsensitive))) //过滤掉虚拟地址
			{
				strMacAddress = ni.hardwareAddress();
				if (!strMacAddress.isEmpty())
				{
					break;
				}
			}

		}
		// 获取网卡信息失败
		if (strMacAddress.trimmed().isEmpty())
		{
			strMacAddress = QUuid::createUuid().toString(); //使用guid
		}

		set.setValue(strKey, strMacAddress);
	}

	return strMacAddress;
}

//static
QStringList CTBNetwork::GetMac4List()
{
    QStringList slRet;
    //todo
    return slRet;
}

//static
QString CTBNetwork::GetMac6()
{
    QString strRet = "";
    //todo
    return strRet;
}

//static
QStringList CTBNetwork::GetMac6List()
{
    QStringList slRet;
    //todo
    return slRet;
}


//获取网络错误原因
//static
QString CTBNetwork::GetReplyErrorName(int iErrorCode)
{
	QString strName = "";
	switch (iErrorCode)
	{
	case QNetworkReply::ConnectionRefusedError:
		//the remote server refused the connection(the server is not accepting requests)
		strName = QStringLiteral("the remote server refused the connection(the server is not accepting requests)");
		break;
	case QNetworkReply::RemoteHostClosedError:
		//the remote server closed the connection prematurely, before the entire reply was received and processed
		strName = QStringLiteral("the remote server closed the connection prematurely, before the entire reply was received and processed");
		break;
	case QNetworkReply::HostNotFoundError:
		//the remote host name was not found(invalid hostname)
		strName = QStringLiteral("the remote host name was not found(invalid hostname)");
		break;
	case QNetworkReply::TimeoutError:
		//the connection to the remote server timed out
		strName = QStringLiteral("the connection to the remote server timed out");
		break;
	case QNetworkReply::OperationCanceledError:
		//the operation was canceled via calls to abort() or close() before it was finished.
		strName = QStringLiteral("the operation was canceled via calls to abort() or close() before it was finished.");
		break;
	case QNetworkReply::SslHandshakeFailedError:
		//the SSL/TLS handshake failed and the encrypted channel could not be established.The sslErrors() signal should have been emitted.
		strName = QStringLiteral("the SSL/TLS handshake failed and the encrypted channel could not be established.The sslErrors() signal should have been emitted.");
		break;
	case QNetworkReply::TemporaryNetworkFailureError:
		//the connection was broken due to disconnection from the network, however the system has initiated roaming to another access point.The request should be resubmitted and will be processed as soon as the connection is re-established.
		strName = QStringLiteral("the connection was broken due to disconnection from the network, however the system has initiated roaming to another access point.The request should be resubmitted and will be processed as soon as the connection is re-established.");
		break;
	case QNetworkReply::NetworkSessionFailedError:
		//the connection was broken due to disconnection from the network or failure to start the network.
		strName = QStringLiteral("the connection was broken due to disconnection from the network or failure to start the network.");
		break;
	case QNetworkReply::BackgroundRequestNotAllowedError:
		//the background request is not currently allowed due to platform policy.
		strName = QStringLiteral("the background request is not currently allowed due to platform policy.");
		break;
		case QNetworkReply::TooManyRedirectsError:
			//while following redirects, the maximum limit was reached.The limit is by default set to 50 or as set by QNetworkRequest::setMaxRedirectsAllowed(). (This value was introduced in 5.6.)
		strName = QStringLiteral("while following redirects, the maximum limit was reached.The limit is by default set to 50 or as set by QNetworkRequest::setMaxRedirectsAllowed(). (This value was introduced in 5.6.)");
		break;
	case QNetworkReply::InsecureRedirectError:
		//while following redirects, the network access API detected a redirect from a encrypted protocol(https) to an unencrypted one(http). (This value was introduced in 5.6.)
		strName = QStringLiteral("while following redirects, the network access API detected a redirect from a encrypted protocol(https) to an unencrypted one(http). (This value was introduced in 5.6.)");
		break;
	case QNetworkReply::ProxyConnectionRefusedError:
		//the connection to the proxy server was refused(the proxy server is not accepting requests)
		strName = QStringLiteral("the connection to the proxy server was refused(the proxy server is not accepting requests)");
		break;				
	case QNetworkReply::ProxyConnectionClosedError:
		//the proxy server closed the connection prematurely, before the entire reply was received and processed
		strName = QStringLiteral("the proxy server closed the connection prematurely, before the entire reply was received and processed");
		break;
	case QNetworkReply::ProxyNotFoundError:
		//the proxy host name was not found(invalid proxy hostname)
		strName = QStringLiteral("the proxy host name was not found(invalid proxy hostname)");
		break;
	case QNetworkReply::ProxyTimeoutError:
		//the connection to the proxy timed out or the proxy did not reply in time to the request sent
		strName = QStringLiteral("the connection to the proxy timed out or the proxy did not reply in time to the request sent");
		break;
	case QNetworkReply::ProxyAuthenticationRequiredError:
		//the proxy requires authentication in order to honour the request but did not accept any credentials offered(if any)
		strName = QStringLiteral("the proxy requires authentication in order to honour the request but did not accept any credentials offered(if any)");
		break;
	case QNetworkReply::ContentAccessDenied:
		//the access to the remote content was denied(similar to HTTP error 403)
		strName = QStringLiteral("the access to the remote content was denied(similar to HTTP error 403)");
		break;
	case QNetworkReply::ContentOperationNotPermittedError:
		//the operation requested on the remote content is not permitted
		strName = QStringLiteral("the operation requested on the remote content is not permitted");
		break;		
	case QNetworkReply::ContentNotFoundError:
		//the remote content was not found at the server(similar to HTTP error 404)
		strName = QStringLiteral("the remote content was not found at the server(similar to HTTP error 404)");
		break;
	case QNetworkReply::AuthenticationRequiredError:
		//the remote server requires authentication to serve the content but the credentials provided were not accepted(if any)
		strName = QStringLiteral("the remote server requires authentication to serve the content but the credentials provided were not accepted(if any)");
		break;
	case QNetworkReply::ContentReSendError:
		//the request needed to be sent again, but this failed for example because the upload data could not be read a second time.
		strName = QStringLiteral("the request needed to be sent again, but this failed for example because the upload data could not be read a second time.");
		break;
	case QNetworkReply::ContentConflictError:
		//the request could not be completed due to a conflict with the current state of the resource.
		strName = QStringLiteral("the request could not be completed due to a conflict with the current state of the resource.");
		break;
	case QNetworkReply::ContentGoneError:
		//the requested resource is no longer available at the server.
		strName = QStringLiteral("the requested resource is no longer available at the server.");
		break;
	case QNetworkReply::InternalServerError:
		//the server encountered an unexpected condition which prevented it from fulfilling the request.
		strName = QStringLiteral("the server encountered an unexpected condition which prevented it from fulfilling the request.");
		break;
	case QNetworkReply::OperationNotImplementedError:
		//the server does not support the functionality required to fulfill the request.
		strName = QStringLiteral("the server does not support the functionality required to fulfill the request.");
		break;
	case QNetworkReply::ServiceUnavailableError:
		//the server is unable to handle the request at this time.
		strName = QStringLiteral("the server is unable to handle the request at this time.");
		break;
	case QNetworkReply::ProtocolUnknownError:
		//the Network Access API cannot honor the request because the protocol is not known
		strName = QStringLiteral("the Network Access API cannot honor the request because the protocol is not known");
		break;
	case QNetworkReply::ProtocolInvalidOperationError:
		//the requested operation is invalid for this protocol
		strName = QStringLiteral("the requested operation is invalid for this protocol");
		break;
	case QNetworkReply::UnknownNetworkError:
		//an unknown network - related error was detected
		strName = QStringLiteral("an unknown network - related error was detected");
		break;
	case QNetworkReply::UnknownProxyError:
		//an unknown proxy - related error was detected
		strName = QStringLiteral("an unknown proxy - related error was detected");
		break;
	case QNetworkReply::UnknownContentError:
		//an unknown error related to the remote content was detected
		strName = QStringLiteral("an unknown error related to the remote content was detected");
		break;
	case QNetworkReply::ProtocolFailure:
		//a breakdown in protocol was detected(parsing error, invalid or unexpected responses, etc.)
		strName = QStringLiteral("a breakdown in protocol was detected(parsing error, invalid or unexpected responses, etc.)");
		break;
	case QNetworkReply::UnknownServerError:
		//an unknown error related to the server response was detected
		strName = QStringLiteral("an unknown error related to the server response was detected");
		break;
	default:
		strName = QStringLiteral("unknown network reply errorcode %1").arg(iErrorCode);
		break;
	}

	return strName;
}
