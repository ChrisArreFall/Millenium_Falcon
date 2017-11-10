#include "Enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Asteroid.h"
#include <QDebug>
#include "Base.h"
#include "AStar.h"
#include <list>
#include <fstream>

#include <QDebug>
Enemy::Enemy(bool status): QObject(), QGraphicsRectItem(){
    // drew the rect
    setRect(0,0,10,10);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    if(status){
        timer->start(33);
    }
    else{
        timer->start(30);
    }
}

void Enemy::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Base)){
                qDebug() << "Felicidades se llego a la base!!!......";
                return;
            }
        }
    if(pos().x()<1160){
        std::list<position> asteroidPositions;
        for(int i = 0;i<scene()->items(Qt::SortOrder::DescendingOrder).size();i++){
            position asteroid;
            asteroid.x = scene()->items(Qt::SortOrder::DescendingOrder)[i]->pos().x();
            asteroid.y = scene()->items(Qt::SortOrder::DescendingOrder)[i]->pos().y();
            if(asteroid.x==pos().x() && asteroid.y==pos().y() || asteroid.x == 1170&&asteroid.y==335){

            }
            else{
                qDebug() << asteroid.x << ", " << asteroid.y << "Num: "<< i;
                asteroidPositions.push_front(asteroid);
            }
        }
        qDebug() << "--------------------------------------------";
        position nextPos;
        position temp1;
        qDebug() << "Current Position: "<<pos().x()<<", "<<pos().y();
        temp1 = map.start(pos().x(), pos().y(),end,345, asteroidPositions);
        end=end+2;
        if(temp1.x>1200 || temp1.x <0){
            qDebug() << "Error Positions: "<<temp1.x<<", "<<temp1.y;
            qDebug() << "ERROR!!!";
        }
        else{
            nextPos.x = temp1.x;
            nextPos.y = temp1.y;
            qDebug() << "Position after: "<<nextPos.x<<", "<<nextPos.y;
            setPos(nextPos.x,nextPos.y);
        }
        asteroidPositions.clear();
        temp1.x = 0;
        temp1.y = 0;

    }
    //aqui seria el uso de a*

}

