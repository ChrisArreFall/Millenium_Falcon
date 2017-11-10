#include "Base.h"
#include <QGraphicsScene>
#include <QDebug>
Base::Base(){
    // drew the rect
    //setRect(0,0,30,30);
    setPixmap(QPixmap("/Users/Christopher/Millenium_Falcon/img/base.png"));
    setPos(1120,335);
}
