#include "Asteroid.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "MillenniumFalcon.h"
#include <QDebug>
Asteroid::Asteroid(bool direction){
    this->direction = direction;
    //set random position
    //true = up
    if(direction){
        int randomNumberY = rand() % 650;
        int randomNumberX = rand() % 900 + 150;
        setPos(randomNumberX,randomNumberY);
    }
    else{
        int randomNumberY = rand() % 650;
        int randomNumberX = rand() % 900 + 150;
        setPos(randomNumberX,randomNumberY);
    }


    // draw the rect
    //setRect(0,0,20,20);
    setPixmap(QPixmap("/Users/Christopher/Millenium_Falcon/img/asteroides.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(2000);
}

void Asteroid::move(){
    // move enemy down
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Asteroid)){
                // remove them both
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                // delete them both
                delete colliding_items[i];
                delete this;
                return;
            }


    }
    if(pos().y()<50||pos().y()>650){
        this->direction = !this->direction;
    }
    else if(this->direction){
        setPos(x(),y()-1);

        if (pos().y() + pixmap().height() < 0){
            this->posX = pos().x();
            this->posY = pos().y();
            scene()->removeItem(this);
            delete this;
        }
    }
    else{
        setPos(x(),y()+1);
        if (pos().y() + pixmap().height() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
}



