#pragma once

#include <QtCore/qstring.h>

class CTBString
{
private:
    CTBString();

public:	
	//sqlite中转义字符的处理
	static QString ToEscape(const QString& strData);
	static QString FromEscape(const QString& strData);
};

