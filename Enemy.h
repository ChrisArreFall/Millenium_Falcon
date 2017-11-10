#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Map.h"

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(bool status);
    Map map;
    int end = 0;
public slots:
    void move();
};

#endif // ENEMY_H
