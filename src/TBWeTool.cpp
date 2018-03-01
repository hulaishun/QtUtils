#include <stdafx.h>
#include "TBWeTool.h"

#include <QtCore/qdatetime.h>
#include <QtCore/qcoreapplication.h>

#include "TBDir.h"
#include "TBMachine.h"
#include "version.h"

CTBWeTool::CTBWeTool()
{

}

//static
int CTBWeTool::sm_iAppType = APP_TYPE_WETOOL;            //程序类型
//设置程序类型
//static
void CTBWeTool::SetAppType(int iAppType)
{
    sm_iAppType = iAppType;
}

//static
QString CTBWeTool::GetMainAppName(int iAppType /*= APP_TYPE_WETOOL*/)
{
	//升级程序名为wetao,显示程序为byn
	switch (iAppType)
	{
	case APP_TYPE_WETOOL:
		return "WeTool";
		break;
	case APP_TYPE_WECOP:
		return "WeCop";
		break;
	case APP_TYPE_BYN:
		return "Byn";
		break;
	case APP_TYPE_BYN_TOOL:
		return "BynTool";
		break;
	case APP_TYPE_BYN_COLLECT:
		return "BynCollect";
	default:
        //return qApp->applicationName();
        return "";
		break;
	}
}

//static
QString CTBWeTool::GetCachePath()
{
    QString strValue = "";

    //格式：C:/Users/当前用户名称/AppData/Roaming/WeTool
    strValue = QString("%1/%2")
            .arg(CTBMachine::GetAppDataPath())
            .arg(GetMainAppName(sm_iAppType));

    return strValue;
}

//static
QString CTBWeTool::GetCacheImagePath()
{
    QString strValue = "";

    //格式：C:/Users/当前用户名称/AppData/Roaming/WeTool/images
    strValue = QString("%1/%2/images")
            .arg(CTBMachine::GetAppDataPath())
            .arg(GetMainAppName(sm_iAppType));

    return strValue;
}

//static
QString CTBWeTool::GetSysCfgFile()
{
    //C:\Users\当前系统登录用户\AppData\Roaming\WeTool\system\cfg\sys_cfg.db
    QString strPath = GetCachePath() + "/system/cfg";
    CTBDir::Mkpath(strPath);

    QString strValue = strPath + "/sys_cfg.db";

    return strValue;
}

//获取系统配置ini文件
//static
QString CTBWeTool::GetSysCfgIniFile()
{
	//C:\Users\当前系统登录用户\AppData\Roaming\WeTool\system\cfg\sys_cfg.ini
	QString strPath = GetCachePath() + "/system/cfg";
	CTBDir::Mkpath(strPath);

	QString strValue = strPath + "/sys_cfg.ini";

	return strValue;
}

QString CTBWeTool::GetHeadImgPath()
{
	static QString strPath;
	if (strPath.isEmpty())
	{
		strPath = GetCachePath() + "/headimgs";
		CTBDir::Mkpath(strPath);
	}
	return strPath;
}

//获取微淘数据库的路径(包含全路径)
//static
QString CTBWeTool::GetWetaoDBPath()
{
    static QString strPath = "";
    if (strPath.isEmpty())
    {
        strPath = GetCachePath() + "/system/cfg";
        CTBDir::Mkpath(strPath);
    }
    return strPath;
}

//获取微淘数据库的文件(包含全路径和文件名后缀)
//static
QString CTBWeTool::GetWetaoDBFile()
{
    static QString strFile = "";
    if (strFile.isEmpty())
    {
        strFile = GetWetaoDBPath() + "/byn.db";
    }
    return strFile;
}

//获取必应鸟工具的路径(包括全路径)
QString CTBWeTool::GetBynToolDBPath()
{
	static QString strPath = "";
	if (strPath.isEmpty())
	{
		strPath = GetCachePath() + "/system/cfg";
		CTBDir::Mkpath(strPath);
	}
	return strPath;
}

//获取必应鸟工具数据库的文件(包含全路径和文件名后缀)
QString CTBWeTool::GetBynToolDBFile()
{
	static QString strFile = "";
	if (strFile.isEmpty())
	{
		strFile = GetBynToolDBPath() + "/BynTool.db";
	}
	return strFile;
}

//获取dump文件(包含全路径)
QString CTBWeTool::GetDumpFile()
{
	QString strPath = GetSysLogPath();
	CTBDir::Mkpath(strPath);

	QString strName = QString("dump%1_%2_%3.dmp")
        .arg(GetMainAppName(sm_iAppType))
		.arg(VERSTRING)
		.arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));

	QString strFile = QString("%1/%2").arg(strPath).arg(strName);

	return strFile;
}

//获取压缩日志文件(包含全路径)
 QString CTBWeTool::GetZipLogFile(const QString& strUserName)
{
	 QString strZipFile = QString("%1/%2_%3_%4.zip")
		 .arg(CTBWeTool::GetSysLogPath())
         .arg(CTBWeTool::GetMainAppName(sm_iAppType) + VERSTRING)
		 .arg(strUserName)
		 .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));

	 return strZipFile;
}

QString CTBWeTool::GetWeCopDBFile(const QString& wecop_user_name)
{
	QString strPath = QString("%1/%2/wecop_user_data/%3/")
		.arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType))
		.arg(wecop_user_name);
	CTBDir::Mkpath(strPath);
	QString strValue = strPath + "/wecop.db";
	return strValue;
}

//发单的db文件
//static
QString CTBWeTool::GetBillDBFile(const QString& strBynId, const QString& strWxid)
{
	static QString strFile = "";
	if (strFile.isEmpty())
	{
		strFile = GetWetaoDBPath() + QString("/bill_%1_%2.db").arg(strBynId).arg(strWxid);
	}
	return strFile;
}

//获取系统日志路径
//static
QString CTBWeTool::GetSysLogPath()
{
	QString strValue = "";

	//格式：C:/Users/当前用户名称/AppData/Roaming/WeTool/system/log
	strValue = QString("%1/%2/system/log")
		.arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType));

	CTBDir::Mkpath(strValue);

	return strValue;
}


//static
QString  CTBWeTool::GetSysLogFile()
{
	QDateTime now = QDateTime::currentDateTime();
	QString strFile = QString("%1/%2.log")
		.arg(GetSysLogPath())
        .arg(GetMainAppName(sm_iAppType));
	//QString strFile = QString("%1/%2.log").arg(GetSysLogPath(iAppType)).arg(GetMainAppName(iAppType));
	return strFile;
}


//static
QString CTBWeTool::GetSysLogCfgFile()
{
	QString strPath = GetCachePath() + "/system/cfg";
	CTBDir::Mkpath(strPath);

	QString strValue = strPath + "/log4cxx.properties";

	return strValue;
}

//获取程序当前路径
//static
QString CTBWeTool::GetAppCurPath()
{
	QString strPath = QCoreApplication::applicationDirPath();

	return strPath;
}

//static
QString CTBWeTool::GetWxidPath(const QString& strCurWxid)
{
    QString strValue = "";

    //格式：C:/Users/当前用户名称/AppData/Roaming/WeTool/users/当前微信id
    strValue = QString("%1/%2/users/%3")
            .arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType))
		.arg(strCurWxid);

    return strValue;
}

QString CTBWeTool::GetWxidDBFile(const QString& strCurWxid)
{
    QString strPath = GetWxidDBPath(strCurWxid);
    CTBDir::Mkpath(strPath);

    QString strValue = strPath + "/wt.db";

    return strValue;
}

QString CTBWeTool::GetWxidDBPath(const QString& strCurWxid)
{
    QString strValue = "";

    //格式：C:/Users/当前用户名称/AppData/Roaming/WeTool/users/当前微信id/db
    strValue = QString("%1/%2/users/%3/db")
            .arg(CTBMachine::GetAppDataPath())
            .arg(GetMainAppName(sm_iAppType))
			.arg(strCurWxid);

    return strValue;
}


//static
QString CTBWeTool::GetWxidCfgFile(const QString& strCurWxid)
{
    //C:\Users\当前系统登录用户\AppData\Roaming\WeTool\users\当前微信登录用户id\cfg\user_cfg.db
    QString strPath = GetWxidPath(strCurWxid) + "/cfg";
    CTBDir::Mkpath(strPath);

    QString strValue = strPath + "/user_cfg.db";

    return strValue;
}

QString CTBWeTool::GetWxidNewFriendFile(const QString & strCurWxid)
{
	QString strPath = GetWxidPath(strCurWxid) + "/cfg";
	CTBDir::Mkpath(strPath);

	QString strValue = strPath + "/newFriends.dat";

	return strValue;
}


QString CTBWeTool::GetWxidChatDBPath(const QString strCurWxid)
{
	QString strPath = GetWxidPath(strCurWxid)+"/chatDB";
	CTBDir::Mkpath(strPath);
	QString strValue = strPath + "/chatmessage.db";
	return strValue;
}

QString CTBWeTool::GetWxidMiscDBPath(const QString strCurWxid)
{
	QString strPath = GetWxidDBPath(strCurWxid);
	CTBDir::Mkpath(strPath);
	QString strValue = strPath + "/MiscData.db";
	return strValue;
}

//获取订单路径
//static
QString CTBWeTool::GetPayPath()
{
	QString strValue = "";

	//格式：C:/Users/当前用户名称/AppData/Roaming/BynTool/system/pay
	strValue = QString("%1/%2/system/pay")
		.arg(CTBMachine::GetAppDataPath())
        .arg(GetMainAppName(sm_iAppType));

	CTBDir::Mkpath(strValue);

	return strValue;
}
