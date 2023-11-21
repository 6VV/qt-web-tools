#include "WebChannelManager.h"
#include "WebSocketClientWrapper.h"
#include "WebSocketTransport.h"

WebChannelManager* WebChannelManager::getInstance()
{
	static WebChannelManager instance;
	return &instance;
}

void WebChannelManager::registerObject(const QString& key, QObject* object)
{
	if (webChannel != nullptr)
	{
		webChannel->registerObject(key, object);
	}
}

void WebChannelManager::deregisterObject(QObject* object)
{
	if (webChannel != nullptr)
	{
		webChannel->deregisterObject(object);
	}
}

void WebChannelManager::start(int port)
{
	stop();

	// setup the QWebSocketServer
	server = new QWebSocketServer(QStringLiteral("QWebChannel Standalone Example Server"), QWebSocketServer::NonSecureMode);
	if (!server->listen(QHostAddress::LocalHost, port)) {
		qFatal("Failed to open web socket server.");
		return;
	}

	// wrap WebSocket clients in QWebChannelAbstractTransport objects
	clientWrapper = new WebSocketClientWrapper(server);

	// setup the channel
	webChannel = new QWebChannel();
	QObject::connect(clientWrapper, &WebSocketClientWrapper::clientConnected, webChannel, &QWebChannel::connectTo);
}

void WebChannelManager::stop()
{
	if (server != nullptr)
	{
		server->deleteLater();
		server = nullptr;
	}

	if (webChannel != nullptr)
	{
		webChannel->deleteLater();
		webChannel = nullptr;
	}

	if (clientWrapper != nullptr)
	{
		clientWrapper->deleteLater();
		clientWrapper = nullptr;
	}
}

WebChannelManager::WebChannelManager()
{
}

WebChannelManager::~WebChannelManager()
{
	stop();
}
