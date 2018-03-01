#ifndef TB_WE_TOOL_H
#define TB_WE_TOOL_H

#include <QtCore/qstring.h>

//程序类型
enum EAppType
{
	APP_TYPE_WETOOL			= 1,		//wetool
	APP_TYPE_WECOP			= 2,		//代理版
	APP_TYPE_BYN			= 3,		//淘客版
	APP_TYPE_BYN_TOOL		= 4,		//淘客工具
	APP_TYPE_BYN_COLLECT	= 5,		//qq群采集工具
};

class CTBWeTool
{
private:
    CTBWeTool();

public:
    //设置程序类型
    static void SetAppType(int iAppType);

    static QString GetMainAppName(int iAppType = APP_TYPE_WETOOL);
    static QString GetCachePath();
    static QString GetCacheImagePath();
    static QString GetSysCfgFile();
	//获取系统配置ini文件
	static QString GetSysCfgIniFile();
	static QString GetHeadImgPath(); //头像存储路径
    //获取微淘数据库的路径(包含全路径)
    static QString GetWetaoDBPath();
    //获取微淘数据库的文件(包含全路径和文件名后缀)
    static QString GetWetaoDBFile();

	//获取必应鸟工具的路径(包括全路径)
	static QString GetBynToolDBPath();
	//获取必应鸟工具数据库的文件(包含全路径和文件名后缀)
	static QString GetBynToolDBFile();

	//获取dump文件(包含全路径)
	static QString GetDumpFile();
	//获取压缩日志文件(包含全路径)
	static QString GetZipLogFile(const QString& strUserName);

	//wecop的优惠券DB
	static QString GetWeCopDBFile(const QString& wecop_user_name);

	//发单的db文件
	static QString GetBillDBFile(const QString& strBynId, const QString& strWxid);

	//获取系统日志路径
	static QString GetSysLogPath();
	static QString GetSysLogFile();
	static QString GetSysLogCfgFile();
	//获取程序当前路径
	static QString GetAppCurPath();
	//获取订单路径
	static QString GetPayPath();

    static QString GetWxidPath(const QString& strCurWxid);
    static QString GetWxidDBFile(const QString& strCurWxid);
    static QString GetWxidDBPath(const QString& strCurWxid);
    static QString GetWxidCfgFile(const QString& strCurWxid);
	static QString GetWxidNewFriendFile(const QString& strCurWxid);

	//聊天的db路径
	static QString GetWxidChatDBPath(const QString strCurWxid);
	static QString GetWxidMiscDBPath(const QString strCurWxid);

private:
    static int          sm_iAppType;            //程序类型
};

#endif // TB_WE_TOOL_H
