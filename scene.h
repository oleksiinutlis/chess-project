#pragma once

#include "interfaces.h"
#include "mainwindow.h"
#include <QPainter>
#include <QWidget>
#include <QMainWindow>
#include <QScreen>
#include <QVBoxLayout>
#include <QTimer>
#include <QTabWidget>

class Scene : public QWidget {
private:
    Q_OBJECT

    IMouseEventHandler* mouseEventHandler = nullptr;
    mainwindow& m_mainWindow;

signals:
    void updateSignal();

public:

    Scene(mainwindow& mainWindow, QWidget* parent = nullptr) : QWidget(parent), m_mainWindow(mainWindow)
    {
        connect(this, &Scene::updateSignal, this, QOverload<>::of(&Scene::update));
    }   

    void init() {
        m_mainWindow.setFixedSize(800, 800);
        m_mainWindow.centralWidget()->setLayout(new QGridLayout);
        m_mainWindow.centralWidget()->layout()->addWidget(this);
        m_mainWindow.centralWidget()->layout()->setSpacing(0);
        m_mainWindow.centralWidget()->layout()->setContentsMargins(0,0,0,0);
        m_mainWindow.statusBar()->hide();
        //m_mainWindow.setTabShape(QTabWidget::Triangular); TODO???????
        QScreen* screen = QGuiApplication::primaryScreen();
        QRect screenGeometry = screen->geometry();
        int x = (screenGeometry.width() - m_mainWindow.width()) / 2;
        int y = (screenGeometry.height() - m_mainWindow.height()) / 2 - 30;
        m_mainWindow.move(x, y);
        m_mainWindow.show();

    }
protected:
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