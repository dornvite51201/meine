#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <pillaritem.h>
#include "birditem.h"



class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    void addBird();
    void startGame();

    bool getGameOn();
    void setGameOn(bool value);

    void incrementScore();

    int getScore();



    void setScore(int newScore);

signals:

public slots:
private:
    void showGameOverGraphics();
    void hideGameOverGraphics();
    void cleanPillars();
    void setUpPillarTimer();
    void freezeBirdAndPillarsInPlace();

    QTimer * pillarTimer;
    BirdItem * bird;
    bool gameOn;
    int score;
    int bestScore;

    QGraphicsPixmapItem * gameOverPix;
    QGraphicsTextItem * scoreTextItem;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
