#pragma once

#include <QWidget>

class IMouseEventHandler
{
protected:
    virtual ~IMouseEventHandler() = default;

public:
    virtual void mousePressEvent(QMouseEvent* event) = 0;
    virtual void mouseMoveEvent(QMouseEvent* event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent* event) = 0;
};
