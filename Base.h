#ifndef BASE_H
#define BASE_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QObject>

class Base: public QObject,public QGraphicsRectItem{
public:
    Base();
};
#endif // BASE_H
