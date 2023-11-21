#pragma once

#include "QThread"
#include "httplib.h"

class HttpWorker :public QObject
{
	Q_OBJECT

public:
	~HttpWorker();

	void start(int port, const QString& ip);
	void stop();

private:
	httplib::Server server;
};

class HttpServer :public QObject
{
	Q_OBJECT

signals:
	void sigStartServer(int port, const QString& ip);

public:
	static HttpServer* getInstance();

	void startServer(int port, const QString& ip = "0.0.0.0");
	void stopServer();

private:
	HttpServer();
	~HttpServer();

private:
	QThread httpThread;
	HttpWorker httpWorker;
};

