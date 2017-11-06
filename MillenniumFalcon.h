#ifndef MILENIUMFALCON_H
#define MILENIUMFALCON_H
#include <QGraphicsRectItem>
#include <QObject>
#include "Map.h"

class mileniumFalcon: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    mileniumFalcon();
    Map map;
public slots:
    void move();
    void spawn();
};

#endif // MILENIUMFALCON_H
