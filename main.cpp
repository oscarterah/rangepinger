#include <QApplication>
#include <FelgoApplication>
#include "appwrapper.h"
#include <QQmlApplicationEngine>

// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    AppWrapper wrapper;

    qmlRegisterType<AppWrapper>("io.qt.examples.pingloop", 1, 0, "PingLoop");

    if(!wrapper.initializer())
        return -1;


    return app.exec();
}
