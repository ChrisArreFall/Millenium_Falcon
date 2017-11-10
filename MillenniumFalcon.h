#ifndef MILENIUMFALCON_H
#define MILENIUMFALCON_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "Map.h"

class mileniumFalcon: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    mileniumFalcon();
    Map map;
public slots:
    void move();
    void spawn();
};

#endif // MILENIUMFALCON_H
