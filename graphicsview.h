#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>

class GraphicsView : public QObject
{
    Q_OBJECT
public:
    explicit GraphicsView(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GRAPHICSVIEW_H