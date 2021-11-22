#include "HttpServer.h"
#include "QApplication"

using namespace httplib;

HttpServer* HttpServer::getInstance()
{
	static HttpServer instance;
	return &instance;
}

void HttpServer::startServer()
{
	if (httpThread.isRunning())
	{
		return;
	}

	httpThread.start();
	emit(sigStartServer());
}

void HttpServer::stopServer()
{
	httpWorker.stop();
	httpThread.quit();
	httpThread.wait();
}

HttpServer::HttpServer()
{
	httpWorker.moveToThread(&httpThread);
	connect(this, &HttpServer::sigStartServer, &httpWorker, &HttpWorker::start);
}

HttpServer::~HttpServer()
{
	stopServer();
}

HttpWorker::~HttpWorker()
{
	stop();
}

void HttpWorker::start()
{
	if (server.is_running())
	{
		return;
	}

	server.set_mount_point("/", (QApplication::applicationDirPath() + "/web").toStdString());
	server.listen("0.0.0.0", 8080);
}

void HttpWorker::stop()
{
	if (server.is_running())
	{
		server.stop();
	}
}

