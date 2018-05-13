#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include "QGraphicsView"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QWidget *parent);
protected:
    void fixBackgroundPos();
    virtual void
           resizeEvent(QResizeEvent *event);
signals:

public slots:
};

#endif // GRAPHICSVIEW_H
