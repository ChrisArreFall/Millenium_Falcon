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

int main(int argc,char *argv[]){
    QApplication a(argc, argv);



    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to add to the scene
    Base * base = new Base();
    mileniumFalcon * player = new mileniumFalcon();
    player->setRect(0,0,10,10);
    // add the item to the scene
    scene->addItem(player);
    scene->addItem(base);

    // create a view to visualize the scene
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(1200,700);
    scene->setSceneRect(0,0,1200,700);

    //player->setPos(0,200);
    player->setPos(0,345);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2500);

    return a.exec();

}
