#include "mainwindow.h"
#include <QApplication>
#include <QScreen>
#include <QPainter>

class MainWindow : public QMainWindow {
public:
    void paintEvent(QPaintEvent*) override {
        QPainter painter(this);
        for (int i = 0; i < 8; i += 1) {
            for (int j = 0; j < 8; j += 1) {
                QColor white = "#F0D9B5";
                QColor black = "#B58863";
                if ((i + j) % 2 == 0) {
                    painter.setBrush(white);
                }
                else {
                    painter.setBrush(black);
                }
                QPen pen = painter.pen(); 
                pen.setWidth(0); 
                painter.setPen(pen);
                painter.drawRect(i * 100, j * 100, 100, 100);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(800, 800);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - w.width()) / 2;
    int y = (screenGeometry.height() - w.height()) / 2 - 30;
    w.move(x, y);
    w.show();
    return a.exec();
}
