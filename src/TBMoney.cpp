#include "stdafx.h"
#include "TBMoney.h"


CTBMoney::CTBMoney()
{
}


CTBMoney::~CTBMoney()
{
}

//static
double CTBMoney::ToDouble(const QString& strMoney)
{
	double dblValue = strMoney.toDouble();

	return dblValue;
}

//static
QString CTBMoney::ToString(double dblMoney, char format /*= 'g'*/, int precision /*= 2*/)
{
	QString strValue = QString::number(dblMoney, format, precision);

	int iIndex = -1;
	iIndex = strValue.lastIndexOf(".");
	if (iIndex < 0)
	{
		strValue += "." + QString("").leftJustified(precision, '0');
	}
	else
	{
		int ilen = strValue.size() - iIndex - 1;
		if (ilen < precision)
		{
			strValue += QString("").leftJustified(ilen - precision, '0');
		}

		if (ilen > precision)
		{
			strValue = strValue.left(strValue.size() - (ilen - precision));
		}
	}

	return strValue;
}

//static
QString CTBMoney::ToString(const QString& strMoney, int precision /*= 2*/, const QString& strPrefix /*= ""*/, const QString& strSuffix /*= ""*/)
{
	QString strValue = "";
	int iIndex = -1;
	iIndex = strMoney.lastIndexOf(".");
	if (iIndex < 0)
	{
		strValue = strMoney + "." + QString("").leftJustified(precision, '0');
	}
	else
	{
		int ilen = strMoney.size() - iIndex - 1;
		if (ilen < precision)
		{
			strValue = strMoney + QString("").leftJustified(precision - ilen, '0');
		}
		else if (ilen > precision)
		{
			strValue = strMoney.left(strMoney.size() - (ilen - precision));
		}
		else if (ilen == precision)
		{
			strValue = strMoney;
		}
	}

	//增加前缀
	if (!strPrefix.isEmpty())
	{
		strValue.prepend(strPrefix);
	}

	//增加后缀
	if (!strSuffix.isEmpty())
	{
		strValue.append(strSuffix);
	}

	return strValue;
}
