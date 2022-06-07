# qt-web-tools
## 说明
### 通过Qt加载Web界面的相关工具
## 示例
### 1、加载本地文件
进入demo/vs目录，采用visual studio打开解决方案，编译并执行，会启动http服务器，并加载demo/vs/bin/web下的index.html页面。
### 2、Web与Qt交互
#### （1）启动Web服务
进入demo/angular目录，执行指令：
> npm install

> npm run build

该操作会在demo/vs/bin/web下生成前端页面。
#### （2）执行程序
进入demo/vs目录，采用visual studio打开解决方案，运行程序，加载步骤（1）生成的Web页面。
### 3、加载其它Web页面
进入demo/vs/QtWeb目标，修改QtWeb.cpp，修改webView加载的URL地址：
> webView->load(QUrl("MyWebUrl"));


