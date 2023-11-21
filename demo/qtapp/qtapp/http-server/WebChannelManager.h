#pragma once

#include "QWebSocketServer"
#include "QWebChannel"

class WebSocketClientWrapper;

class WebChannelManager :public QObject
{
	Q_OBJECT

public:
	static WebChannelManager* getInstance();

	void registerObject(const QString& key, QObject* object);
	void deregisterObject(QObject* object);
	void start(int port);
	void stop();

private:
	WebChannelManager();
	~WebChannelManager();

private:
	QWebChannel* webChannel = nullptr;
	QWebSocketServer* server = nullptr;
	WebSocketClientWrapper* clientWrapper = nullptr;
};

