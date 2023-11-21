#include <QtWidgets/QApplication>
#include "QtWeb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QtWeb w;
    w.show();

    return a.exec();
}
