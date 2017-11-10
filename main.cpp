#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "MillenniumFalcon.h"
#include "Base.h"
#include <QTimer>
#include <list>
#include "Map.h"
#include <QDebug>
#include "Enemy.h"

int main(int argc,char *argv[]){
    QApplication a(argc, argv);



    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Base * base = new Base();
    mileniumFalcon * ship = new mileniumFalcon();
    Enemy * enemy = new Enemy(true);
    //Enemy * enemy2 = new Enemy(false);
    // add the item to the scene
    scene->addItem(ship);
    scene->addItem(base);
    scene->addItem(enemy);
    //scene->addItem(enemy2);


    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(1200,700);
    scene->setSceneRect(0,0,1200,700);
    view->setBackgroundBrush(QImage("/Users/Christopher/Millenium_Falcon/img/space.png"));

    // spawn enemies
    for(int i = 0; i<30;i++){
    ship->spawn();
    }
    return a.exec();

}
