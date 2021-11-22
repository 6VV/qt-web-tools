#pragma once

#include "QThread"
#include "httplib.h"

class HttpWorker :public QObject
{
	Q_OBJECT

public:
	~HttpWorker();

	void start();
	void stop();

private:
	httplib::Server server;
};

class HttpServer :public QObject
{
	Q_OBJECT

signals:
	void sigStartServer();

public:
	static HttpServer* getInstance();

	void startServer();
	void stopServer();

private:
	HttpServer();
	~HttpServer();

private:
	QThread httpThread;
	HttpWorker httpWorker;
};

