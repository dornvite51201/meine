#include "birditem.h"
#include <QTimer>
#include <QGraphicsScene>

BirdItem::BirdItem(QPixmap pixmap) :
    wingPosition(WingPosition::Up),
    wingDirection(0)
{
    setPixmap(pixmap);

    QTimer * birdWingsTimer = new QTimer(this);

    connect(birdWingsTimer, &QTimer::timeout,[=](){
    updatePixmap();

    });

    birdWingsTimer->start(80);

    groundPosition = scenePos().y() + 290;



    //rotateTo(90,1100,QEasingCurve::InCubic);

    yAnimation = new QPropertyAnimation(this, "y", this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);
    // yAnimation -> start();

    rotationAnimation = new QPropertyAnimation(this, "rotation", this);

   //  rotateTo(90,1200,QEasingCurve::InQuad);
}


qreal BirdItem::y()
{
    return m_y;
}

void BirdItem::shootUp ()
{
    yAnimation->stop();
    rotationAnimation->stop();

    qreal curPosY = y();

    yAnimation->setStartValue(curPosY);
    yAnimation->setEndValue(curPosY - scene()->sceneRect().height()/8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);
    //yAnimation->start();

    connect(yAnimation, &QPropertyAnimation::finished,[=]()
    {
        spadekIfNecessary();
    });

    yAnimation->start();

    rotateTo(-20,200,QEasingCurve::OutCubic);
}

void BirdItem::startFlying()
{
    yAnimation->start();
    rotateTo(90,1200,QEasingCurve::InQuad);
}

void BirdItem::freezeInPlace()
{
    yAnimation->stop();
    rotationAnimation->stop();
}


void BirdItem::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y = y;
}

void BirdItem::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duration);

    rotationAnimation->start();
}

void BirdItem::setRotation(qreal rotation)
{
    m_rotation=rotation;
    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(),c.y());
    t.rotate(rotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);
}

qreal BirdItem::rotation()
{
    return m_rotation;
}

void BirdItem::spadekIfNecessary()
{
    if(y() < groundPosition)
    {
        rotationAnimation->stop();
        // yAnimation->stop();

        yAnimation->setStartValue(y());
        yAnimation->setEasingCurve(QEasingCurve::InQuad);
        yAnimation->setEndValue(groundPosition);
        yAnimation->setDuration(1200);
        yAnimation->start();

        rotateTo(90,1100,QEasingCurve::InCubic);

    }
}


void BirdItem::updatePixmap()
{
    if(wingPosition == WingPosition::Middle)
    {
        if(wingDirection){

            setPixmap(QPixmap(":/Images/bird_up.png"));
            wingPosition = WingPosition::Up;
            wingDirection = 0;
        } else {

            setPixmap(QPixmap(":/Images/bird_down.png"));
            wingPosition = WingPosition::Down;
            wingDirection = 1;
            }
    } else {
    setPixmap(QPixmap(":/Images/bird_middle.png"));
    wingPosition = WingPosition::Middle;

}




}
