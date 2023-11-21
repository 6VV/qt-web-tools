#include "JsCpp.h"
#include "QMessageBox"


double JsCpp::add(double a, double b)
{
	return a + b;
}

void JsCpp::showMsg(const QString& msg1, const QString& msg2)
{
	QMessageBox::information(nullptr, "title", msg1 + " " + msg2);
}
