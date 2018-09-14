/**
 *Copyright (c) 2018 ilaocai
 *
 *This software is released under the MIT License.
 *https://opensource.org/licenses/MIT
 */

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include "downloadwidget.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *root = engine.rootObjects().first();

    DownloadWidget wid(root);

    return app.exec();
}
