#ifndef BIRDITEM_H
#define BIRDITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class BirdItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)

public:

    explicit BirdItem(QPixmap pixmap);

    qreal y();
    qreal rotation();

    void shootUp();
    void startFlying();
    void freezeInPlace();
signals:

public slots:

    void setRotation(qreal rotation);

    void setY(qreal y);

    void rotateTo(const qreal &end, const int& duration, const QEasingCurve& curve);

    void spadekIfNecessary();

private:


    enum WingPosition
    {   Up,
        Middle,
        Down
    };

    void updatePixmap();

    WingPosition wingPosition;
    bool wingDirection ; // 0 : down, 1; UP
    qreal m_y;
    qreal m_rotation;
    QPropertyAnimation * yAnimation;
    QPropertyAnimation * rotationAnimation;
    qreal groundPosition;
};

#endif // BIRDITEM_H
