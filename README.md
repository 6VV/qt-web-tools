# qt-web-tools
## 说明
### 通过Qt加载Web界面的相关工具，本示例基于Qt+Http+Angular实现，若仅需实现C++和Web的交互，Http和Angular都不是必须的，仅需要使用Qt端提供的WebChannelManager类注册QObject对象，并在Web端接收调用即可。
## 示例
### 1、加载本地文件
采用visual studio打开demo/qtapp目录，编译后会将可执行文件生成到demo/out/bin目录下，执行程序，会启动http服务器，并加载demo/out/bin/web下的index.html页面。
### 2、Web与Qt交互
#### （1）启动Web服务
进入demo/angular目录，执行指令：
> npm install

> npm run build

该操作会在demo/out/bin/web下生成前端页面。
#### （2）执行程序
进入demo/qtapp目录，采用visual studio打开目录，运行程序，加载步骤（1）生成的Web页面。
#### （3）Qt端
Qt端提供了WebChannelManager类，用于注册远程对象，通过实现QObject的子类，并将该子类的实例注册到Web中，可实现远程调用。
#### （4）Web端
Web端通过WebSocket接收注册的对象，并调用该对象的信号、槽，实现双向通信。Web端提供了CppChannelService类用于接收注册的C++对象，并提供了TypeScript的类型系统，用于实现类型检查及智能提示。若不希望使用TypeScript，可自行参考CppChannelService类接收对象并调用。
### 3、加载其它Web页面
进入demo/vs/QtWeb目标，修改QtWeb.cpp，修改webView加载的URL地址：
> webView->load(QUrl("MyWebUrl"));


