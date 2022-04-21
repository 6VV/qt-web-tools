#pragma once

//Cpp测试函数类，用于传递到Web进行调用

#include "QObject"
#include "QString"

class JsCpp :public QObject
{
	Q_OBJECT

signals:
	void sigNameChanged(const QString& newName);
	void sigAgeChanged(int newAge);

public slots:
	double add(double a, double b);
	void showMsg(const QString& msg1, const QString& msg2);
};

