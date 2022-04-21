#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWeb.h"
#include <QWebEngineView>

class QtWeb : public QMainWindow
{
    Q_OBJECT

public:
    QtWeb(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtWebClass ui;
    QWebEngineView* webView = nullptr;
};
