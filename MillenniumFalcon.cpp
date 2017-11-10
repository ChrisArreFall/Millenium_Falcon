#include "MillenniumFalcon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Asteroid.h"
#include <QDebug>
#include "Base.h"
#include "AStar.h"
#include <list>
#include <fstream>



mileniumFalcon::mileniumFalcon(){
    // drew the rect
    //setRect(0,0,10,10);
    setPixmap(QPixmap("/Users/Christopher/Millenium_Falcon/img/nave.png"));
    setPos(0,345);
    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(25);
}

void mileniumFalcon::move(){
    if(pos().x()>=1100){
        if(pos().y()>330){
            setPos(pos().x(),pos().y()-1);
        }
        else if(pos().y()<205){
            setPos(pos().x(),pos().y()+1);
        }
    }
    else{
        QList<QGraphicsItem *> colliding_items = collidingItems();
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
            temp1 = map.start(pos().x(), pos().y(),1170,335, asteroidPositions);
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
    }
}
void mileniumFalcon::spawn(){
    // create an enemy
    Asteroid * up = new Asteroid(true);
    scene()->addItem(up);
    Asteroid * down = new Asteroid(false);
    scene()->addItem(down);
    Asteroid * down2 = new Asteroid(false);
    scene()->addItem(down2);

}
