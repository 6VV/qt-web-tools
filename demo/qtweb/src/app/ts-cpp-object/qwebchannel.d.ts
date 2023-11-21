declare class QWebChannel{
    constructor(socket: WebSocket, initCallback: (data: any) => void);
}

export { QWebChannel };