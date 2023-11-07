#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QPainter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.resize(800, 800);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - w.width()) / 2;
    int y = (screenGeometry.height() - w.height()) / 2 - 30;
    w.move(x, y);
    w.show();
    return a.exec();
}
