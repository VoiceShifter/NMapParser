#include <QGuiApplication>
#include <QQmlApplicationEngine>
# include "Analyzer.hpp"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);    
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Nmap/Main.qml"));
    qmlRegisterType<Analyzer>("com.Analyzer", 1, 0, "Analyzer");
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
