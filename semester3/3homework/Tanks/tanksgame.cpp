#include "tanksgame.h"
#include <iostream>

TanksGame::TanksGame(QWidget *) :
    redrawingTimer(new QTimer()),
    scene(new QGraphicsScene(this)),
    landscape(new QVector<PieceOfLandscape*>()),
    bullets(new QVector<Bullet*>()),
    explosions(new QVector<Explosion*>())
{
    scene->setSceneRect(-200, -200, 200, 200);

    setScene(scene);

    PieceOfLandscape *firstPiece = new PieceOfLandscape(QPoint(-200, -200), QPoint(0, 100));
    PieceOfLandscape *secondPiece = new PieceOfLandscape(QPoint(0, 100), QPoint(100, -100));
    secondPiece->setPrev(firstPiece);
    firstPiece->setNext(secondPiece);
    landscape->append(secondPiece);
    landscape->append(firstPiece);
    for (int i = 0; i < landscape->length(); i++)
        scene->addItem(landscape->at(i));

    tank = new Tank(landscape->at(0)->start(), landscape->at(0));
    scene->addItem(tank);

    connect(redrawingTimer, SIGNAL(timeout()), this, SLOT(moveObjects()));
    redrawingTimer->start(100);
}

TanksGame::~TanksGame()
{
    delete scene;
    delete bullets;
    delete redrawingTimer;
    delete landscape;
}

void TanksGame::keyPressEvent(QKeyEvent *event)
{
    //std::cout << event->key() << " pressed!!";
    switch(event->key())
    {
        case Qt::Key_Right:
            tank->moveRight();
            break;

        case Qt::Key_Left:
            tank->moveLeft();
            break;
        case Qt::Key_Up:
            tank->increaseAngle();
            break;
        case Qt::Key_Down:
            tank->decreaseAngle();
            break;
        case Qt::Key_Space:
            Bullet *newBullet = nullptr;
            tank->fireThis(newBullet);
            if (newBullet)
            {
                scene->addItem(newBullet);
                bullets->append(newBullet);
            }
            break;
    }
    scene->update();
}

void TanksGame::moveObjects()
{
    for (int i = 0; i < bullets->length(); i++)
    {
        bullets->at(i)->refresh();
    }

    QVector<Explosion*> *toDelete = new QVector<Explosion*>();

    for (int i = 0; i < explosions->length(); i++)
    {
        explosions->at(i)->refresh();
        if (explosions->at(i)->isDamped())
        {
            scene->removeItem(explosions->at(i));
            toDelete->append(explosions->at(i));
        }
    }

    for (int i = 0; i < toDelete->length(); i++)
    {
        explosions->removeAll(toDelete->at(i));
        delete toDelete->at(i);
    }
    delete toDelete;

    checkForCollisions();
    scene->update();
}

void TanksGame::checkForCollisions()
{
    QVector<Bullet*> *toDelete = new QVector<Bullet*>();
    for (int i = 0; i < bullets->length(); i++)
    {
        for (int j = 0; j < landscape->length(); j++)
        {
            if (bullets->at(i)->collidesWith(landscape->at(j)))
            {
                scene->removeItem(bullets->at(i));
                toDelete->append(bullets->at(i));

                Explosion *newExplosion = bullets->at(i)->explode();
                explosions->append(newExplosion);
                scene->addItem(newExplosion);
                break;
            }
        }
    }

    for (int i = 0; i < toDelete->length(); i++)
    {
        bullets->removeAll(toDelete->at(i));
        delete toDelete->at(i);
    }
    delete toDelete;
}

