#include "pillaritem.h"
#include <QRandomGenerator>
#include <QDebug>
#include "birditem.h"
#include <QGraphicsScene>
#include "scene.h"
PillarItem::PillarItem() :
    topPillar(new QGraphicsPixmapItem(QPixmap(":/Images/pillar2.png"))),
    bottomPillar(new QGraphicsPixmapItem(QPixmap(":/Images/pillar2.png"))),
    pastBird(false)
{

    topPillar->setPos(QPointF(0,0) - QPointF(topPillar->boundingRect().width()/2,
    topPillar->boundingRect().height() +100));

    bottomPillar->setPos(QPointF(0,0) + QPointF(-bottomPillar->boundingRect().width()/2,
                                                100));
    addToGroup(topPillar);
    addToGroup(bottomPillar);

    yPos = QRandomGenerator::global()->bounded(150);
    int XRandomizer = QRandomGenerator::global()->bounded(200);

    setPos(QPoint(0,0) + QPoint(260 + XRandomizer,yPos));

    xAnimation = new QPropertyAnimation(this,"x", this);
    xAnimation->setStartValue(260 + XRandomizer);
    xAnimation->setEndValue(-260);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500);


    connect(xAnimation,&QPropertyAnimation::finished,[=]()
    { qDebug() << "Animation finished";
      scene() -> removeItem(this);
      delete this;
    });

    xAnimation->start();

}

PillarItem::~PillarItem()
{
    qDebug() << "Deleting Pillar";
    delete topPillar;
    delete bottomPillar;
}

qreal PillarItem::x() const
{
    return m_x;
}

void PillarItem::freezeInPlace()
{
    xAnimation->stop();
}

void PillarItem::setX(qreal newX)
{
    m_x = newX;

    if(x()<0 && !pastBird){
        pastBird=true;
        QGraphicsScene * mScene = scene();
        Scene * myScene = dynamic_cast<Scene * > (mScene);
        if(myScene){
            myScene->incrementScore();
        }
    }


    if(collidesWithBird())
    {
        emit collideFail();
    }

    setPos(QPointF(0,0) + QPointF(newX,yPos));
}

bool PillarItem::collidesWithBird()
{
    QList<QGraphicsItem*>collidingItems = topPillar->collidingItems();
    collidingItems.append(bottomPillar->collidingItems());

    foreach (QGraphicsItem * item, collidingItems) {
    BirdItem * birdItem = dynamic_cast<BirdItem*>(item);
    if(birdItem){
        return true;
        }
    }
    return false;
}
