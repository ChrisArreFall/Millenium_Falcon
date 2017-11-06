#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QObject>

class Asteroid: public QObject,public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Asteroid(bool direction);
    bool direction;
    int posX;
    int posY;
public slots:
    void move();
};
#endif // ASTEROID_H
