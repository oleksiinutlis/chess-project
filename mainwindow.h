#pragma once

#include <QMainWindow>
#include <QPainter>
#include "ui_mainwindow.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

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

private:
    Ui::mainwindowClass ui;
};