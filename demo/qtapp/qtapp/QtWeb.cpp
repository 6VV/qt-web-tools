#include "QtWeb.h"
#include "http-server/HttpServer.h"
#include "http-server/WebChannelManager.h"
#include "JsCpp.h"
#include "QVBoxLayout"
#include "QPushButton"

QtWeb::QtWeb(QWidget *parent)
    : QMainWindow(parent)
{
    HttpServer::getInstance()->startServer(9000);
    ui.setupUi(this);

    webView = new QWebEngineView(this);
    webView->load(QUrl("http://localhost:9000/"));
    webView->show();

    auto jsCpp = new JsCpp();
    WebChannelManager::getInstance()->start(12345);
    WebChannelManager::getInstance()->registerObject("JsCpp", jsCpp);

    auto changeNameButton = new QPushButton("Change Name", this);
    auto changeAgeButton = new QPushButton("Change Age", this);
    auto buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(changeNameButton);
    buttonLayout->addWidget(changeAgeButton);

    auto layout = new QVBoxLayout(this->centralWidget());
    layout->addLayout(buttonLayout);
    layout->addWidget(webView);
    
	connect(changeNameButton, &QPushButton::clicked, [this, jsCpp]() {
        emit(jsCpp->sigNameChanged("new name"));
    });
    connect(changeAgeButton, &QPushButton::clicked, [this, jsCpp]() {
        emit(jsCpp->sigAgeChanged(20));
    });
}
