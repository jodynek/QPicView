#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{

}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);

    fitInView(sceneRect(), Qt::IgnoreAspectRatio);
    fixBackgroundPos();
}

void GraphicsView::fixBackgroundPos()
{
    static QPixmap toBeScaled(backgroundFile);
    if (currentState != EMPTY)
        return;
    QPixmap p = toBeScaled.scaledToHeight(viewport()->height() - 40, Qt::SmoothTransformation);
    int x = viewport()->width() / 2 - p.width() / 2;
    int y = viewport()->height() / 2 - p.height() / 2;
    background->setPixmap(p);
    background->setX(mapToScene(x, 0).x());
    background->setY(mapToScene(y, 20).y());
}
