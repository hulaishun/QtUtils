#include "stdafx.h"
#include "TBMisc.h"

#include <QtCore/qregexp.h>
#include <QtCore/quuid.h>

QString CTBMisc::GenUUID()
{
	static QRegExp filter("[{}-]");
	QString uuid = QUuid::createUuid().toString();
	uuid.remove(filter);
	return uuid;
}
