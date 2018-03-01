#include "stdafx.h"
#include "TBProcess.h"

#include <QtCore/qprocess.h>
#include <QtCore/qfile.h>

CTBProcess::CTBProcess()
{
}


CTBProcess::~CTBProcess()
{
}

//通过进程名称判断进程是否已存在
//static
bool CTBProcess::IsExistByName(const QString& strProcessName)
{
	QString strname = strProcessName.trimmed().toLower();
	if (strname.isEmpty())
	{
		return false;
	}

	int iindex = -1;
	iindex = strname.lastIndexOf("/");
	if (iindex>0)
	{
		strname = strname.mid(iindex + 1);
	}
	iindex = strname.lastIndexOf("\\");
	if (iindex>0)
	{
		strname = strname.mid(iindex + 1);
	}

	if (!strname.endsWith(".exe"))
	{
		strname.append(".exe");
	}

	QProcess process;
	QStringList listArg;
	//结果是csv格式并且不显示标题
	listArg << "/FO" << "CSV" << "/NH";
	////结果是table格式并且不显示标题
	//listArg << "/FO" << "TABLE" << "/NH";
	listArg << "/FI" << QString("imagename eq %1").arg(strname);
	process.start("tasklist", listArg);
	process.waitForFinished();
	QByteArray baOutput = process.readAllStandardOutput();

	QString strOutput = QString::fromLocal8Bit(baOutput);
	if (strOutput.contains(strname, Qt::CaseInsensitive))
	{
		return true;
	}
	else
	{
		return false;
	}

	return true;
}

//获取进程ID来判断进程是否已存在
//static
bool CTBProcess::IsExistByPid(int iProcessPid)
{
	if (iProcessPid < 0 || iProcessPid > 99999999)
	{
		return false;
	}

	QProcess process;
	QStringList listArg;
	//结果是csv格式并且不显示标题
	listArg << "/FO" << "CSV" << "/NH";
	////结果是table格式并且不显示标题
	//listArg << "/FO" << "TABLE" << "/NH";
	listArg << "/FI" << QString("pid eq %1").arg(iProcessPid);
	process.start("tasklist", listArg);
	process.waitForFinished();
	QByteArray baOutput = process.readAllStandardOutput();
	if (baOutput.indexOf(QString::number(iProcessPid)) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	return true;
}

//获取当前的所有进程名称列表
//static
QStringList CTBProcess::GetAllProcessName()
{
	QStringList listPname;

	QProcess process;
	QStringList listArg;
	//结果是csv格式并且不显示标题
	listArg << "/FO" << "CSV" << "/NH";
	////结果是table格式并且不显示标题
	//listArg << "/FO" << "TABLE" << "/NH";
	process.start("tasklist", listArg);
	process.waitForFinished();
	QByteArray baOutput = process.readAllStandardOutput();	

	//得到进程列表
	QString strOutput = QString::fromLocal8Bit(baOutput);

	QStringList listOut = strOutput.split("\r\n");
	QStringList listLine;
	foreach(QString strLine, listOut)
	{
		listLine = strLine.split(",");
		if (listLine.size()>1)
		{
			listPname.append(listLine[0]);
		}
	}

	return listPname;
}

//获取当前的所有进程pid列表
//static
QList<int> CTBProcess::GetAllProcessPid()
{
	QList<int> listPid;

	QProcess process;
	QStringList listArg;
	//结果是csv格式并且不显示标题
	listArg << "/FO" << "CSV" << "/NH";
	////结果是table格式并且不显示标题
	//listArg << "/FO" << "TABLE" << "/NH";
	process.start("tasklist", listArg);
	process.waitForFinished();
	QByteArray baOutput = process.readAllStandardOutput();

	//得到进程列表
	QString strOutput = QString::fromLocal8Bit(baOutput);

	QStringList listOut = strOutput.split("\r\n");
	QStringList listLine;
	foreach(QString strLine, listOut)
	{
		listLine = strLine.split(",");
		if (listLine.size() > 2)
		{
			listPid.append(listLine[1].toInt());
		}
	}

	return listPid;
}

//通过进程名称来关闭进程
//static
bool CTBProcess::CTBProcess::CloseByName(const QString& strProcessName)
{
	QString strname = strProcessName.trimmed().toLower();
	if (strname.isEmpty())
	{
		return false;
	}

	int iindex = -1;
	iindex = strname.lastIndexOf("/");
	if (iindex > 0)
	{
		strname = strname.mid(iindex + 1);
	}
	iindex = strname.lastIndexOf("\\");
	if (iindex > 0)
	{
		strname = strname.mid(iindex + 1);
	}

	if (!strname.endsWith(".exe"))
	{
		strname.append(".exe");
	}

	QProcess process;
	QStringList listArg;
	listArg << "/IM" << strname;
	process.start("taskkill", listArg);

	return true;
}

//通过进程pid来关闭进程
//static
bool CTBProcess::CloseByPid(int iProcessPid)
{
	if (iProcessPid < 0 || iProcessPid > 99999999)
	{
		return false;
	}

	QProcess process;
	QStringList listArg;
	listArg << "/F" << "/PID" << QString::number(iProcessPid);
	process.start("taskkill", listArg);

	return true;
}

//通过进程文件来开启进程
//static
int CTBProcess::OpenByFile(const QString& strProcessFile)
{
	if (!QFile::exists(strProcessFile))
	{
		return -1;
	}

	return QProcess::execute(strProcessFile, QStringList());
}

//static
int CTBProcess::OpenByFileArg(const QString& strProcessFile, const QStringList &arguments)
{
	if (!QFile::exists(strProcessFile))
	{
		return -1;
	}

	return QProcess::execute(strProcessFile, arguments);
}

//static
int CTBProcess::OpenByCommand(const QString &command)
{
	if (command.isEmpty())
	{
		return -1;
	}

	return QProcess::execute(command);
}
