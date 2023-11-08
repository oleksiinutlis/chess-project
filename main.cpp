#include "mainwindow.h"
#include <QApplication>
#include "scene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;

    Scene scene(w);
    scene.init();

    return a.exec();
}
