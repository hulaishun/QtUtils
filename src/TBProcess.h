#ifndef TB_PROCESS_H
#define TB_PROCESS_H

#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>

class CTBProcess
{
private:
    CTBProcess();
    ~CTBProcess();

public:
    //通过进程名称判断进程是否已存在
    static bool IsExistByName(const QString& strProcessName);
    //获取进程ID来判断进程是否已存在
    static bool IsExistByPid(int iProcessPid);

    //获取当前的所有进程名称列表
    static QStringList GetAllProcessName();

    //获取当前的所有进程pid列表
    static QList<int> GetAllProcessPid();

    //通过进程名称来关闭进程
    static bool CloseByName(const QString& strProcessName);
    //通过进程pid来关闭进程
    static bool CloseByPid(int iProcessPid);

    //通过进程文件来开启进程
    static int OpenByFile(const QString& strProcessFile);
    static int OpenByFileArg(const QString& strProcessFile, const QStringList &arguments);
    static int OpenByCommand(const QString &command);

public:
	//static 


};

#endif //TB_PROCESS_H

