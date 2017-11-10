#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsItem>

#include <QGraphicsPixmapItem>
#include <QObject>

class Asteroid: public QObject,public QGraphicsPixmapItem{
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
