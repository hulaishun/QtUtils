#ifndef TB_PROCESS_INFO_H
#define TB_PROCESS_INFO_H

#include <qt_windows.h>
#include <TlHelp32.h>
#include <qglobal.h>

#include <QtCore/qstring.h>

class CTBProcessInfo
{
public:
	CTBProcessInfo();
	~CTBProcessInfo();

	CTBProcessInfo(const CTBProcessInfo& that);
	CTBProcessInfo& operator=(const CTBProcessInfo& that);

	void Clear();
	QString GetDesc();

public:
	void CopyFrom(PROCESSENTRY32 pe32);

private:
	void CopyFrom(const CTBProcessInfo& that);

public:
	unsigned long		dwSize;					//大小
	unsigned long		cntUsage;				//已使用数量
	unsigned long		th32ProcessID;			//当前进程id
	unsigned long		th32DefaultHeapID;		//
	unsigned long		th32ModuleID;			//模块id

	unsigned long		cntThreads;				//线程数量
	unsigned long		th32ParentProcessID;	//当前进程的父进程id
	long				pcPriClassBase;			//
	unsigned long		dwFlags;				//标志
	QString				exeFile;				//路径名称
};

#endif //TB_PROCESS_INFO_H

