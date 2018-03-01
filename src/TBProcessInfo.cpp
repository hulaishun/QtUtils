#include "stdafx.h"
#include "TBProcessInfo.h"

CTBProcessInfo::CTBProcessInfo()
	:dwSize(0)
	,cntUsage(0)
	,th32ProcessID(0)
	,th32DefaultHeapID(0)
	,th32ModuleID(0)

	,cntThreads(0)
	,th32ParentProcessID(0)
	,pcPriClassBase(0)
	,dwFlags(0)
	,exeFile("")
{
}


CTBProcessInfo::~CTBProcessInfo()
{
}


CTBProcessInfo::CTBProcessInfo(const CTBProcessInfo& that)
{
	if(this == &that)
	{
		return;
	}

	CopyFrom(that);
}

CTBProcessInfo& CTBProcessInfo::operator=(const CTBProcessInfo& that)
{
	if (this == &that)
	{
		return *this;
	}

	CopyFrom(that);

	return *this;
}

void CTBProcessInfo::Clear()
{
	dwSize = 0;
	cntUsage = 0;
	th32ProcessID = 0;
	th32DefaultHeapID = 0;
	th32ModuleID = 0;

	cntThreads = 0;
	th32ParentProcessID = 0;
	pcPriClassBase = 0;
	dwFlags = 0;
	exeFile = "";
}

QString CTBProcessInfo::GetDesc()
{
	QString str = "";
	str = QStringLiteral("size:%1 usage:%2 进程id:%3 默认堆id:%4 模块id:%5 线程数量:%6 父进程id:%7 优先级:%8 标志:%9 文件:%10")
		.arg(dwSize).arg(cntUsage).arg(th32ProcessID)
		.arg(th32DefaultHeapID).arg(th32ModuleID).arg(cntThreads)
		.arg(th32ParentProcessID).arg(pcPriClassBase).arg(dwFlags)
		.arg(exeFile);
	return str;
}

void CTBProcessInfo::CopyFrom(PROCESSENTRY32 pe32)
{
	Clear();

	this->dwSize = pe32.dwSize;
	this->cntUsage = pe32.cntUsage;
	this->th32ProcessID = pe32.th32ProcessID;
	this->th32DefaultHeapID = pe32.th32DefaultHeapID;
	this->th32ModuleID = pe32.th32ModuleID;

	this->cntThreads = pe32.cntThreads;
	this->th32ParentProcessID = pe32.th32ParentProcessID;
	this->pcPriClassBase = pe32.pcPriClassBase;
	this->dwFlags = pe32.dwFlags;
	this->exeFile = QString::fromUtf16(reinterpret_cast<const unsigned short *>(pe32.szExeFile));
}

void CTBProcessInfo::CopyFrom(const CTBProcessInfo& that)
{
	Clear();

	this->dwSize = that.dwSize;
	this->cntUsage = that.cntUsage;
	this->th32ProcessID = that.th32ProcessID;
	this->th32DefaultHeapID = that.th32DefaultHeapID;
	this->th32ModuleID = that.th32ModuleID;

	this->cntThreads = that.cntThreads;
	this->th32ParentProcessID = that.th32ParentProcessID;
	this->pcPriClassBase = that.pcPriClassBase;
	this->dwFlags = that.dwFlags;
	this->exeFile = that.exeFile;
}

