#ifndef BASE_H
#define BASE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Base: public QObject,public QGraphicsPixmapItem{
public:
    Base();
};
#endif // BASE_H
