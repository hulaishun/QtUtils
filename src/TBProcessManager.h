#ifndef TB_PROCESS_MANAGER_H
#define TB_PROCESS_MANAGER_H

#include <QtCore/qlist.h>

#include "TBProcessInfo.h"

class CTBProcessManager
{
private:
	CTBProcessManager();
	~CTBProcessManager();

public:
	//获取机器当前的所有进程信息
	static QList<CTBProcessInfo> GetAllProcess();

	//进程是否已开启
	static bool IsOpenByName(const QString& strProcessName);
	static bool IsOpenById(long lProcessId);

	//WeTool是否已开启
	static bool IsOpenWeTool();
	//WeCop是否已开启
	static bool IsOpenWeCop();
	//Byn是否已开启
	static bool IsOpenByn();

};

#endif //TB_PROCESS_MANAGER_H

