#include "tanksgame.h"
#include <iostream>

TanksGame::TanksGame(bool isServer, QWidget *) :
    redrawingTimer(new QTimer()),
    scene(new QGraphicsScene(this)),
    landscape(new QVector<PieceOfLandscape*>()),
    bullets(new QVector<Bullet*>()),
    explosions(new QVector<Explosion*>())
{
    buildMap();

    if (isServer)
    {
        myTank = new Tank(QPoint(-100, 125), landscape->last(), Qt::red);
        enemyTank = new Tank(QPoint(175, 175), landscape->first(), Qt::blue);
    }
    else
    {
        enemyTank = new Tank(QPoint(-100, 125), landscape->last(), Qt::blue);
        myTank = new Tank(QPoint(175, 175), landscape->first(), Qt::red);
    }

    scene->addItem(myTank);
    scene->addItem(enemyTank);

    connect(redrawingTimer, SIGNAL(timeout()), this, SLOT(moveObjects()));
    redrawingTimer->start(17);
}

TanksGame::~TanksGame()
{
    delete scene;
    delete myTank;
    delete enemyTank;

    for (int i = 0; i < bullets->length(); i++)
    {
        delete bullets->at(i);
    }
    delete bullets;

    delete redrawingTimer;

    for (int i = 0; i < bullets->length(); i++)
    {
        delete landscape->at(i);
    }
    delete landscape;
}

QGraphicsScene *TanksGame::getScene()
{
    return scene;
}

void TanksGame::myTankMoved(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_D:
            myTank->moveRight();
            break;

        case Qt::Key_A:
            myTank->moveLeft();
            break;

        case Qt::Key_W:
            myTank->increaseAngle();
            break;

        case Qt::Key_S:
            myTank->decreaseAngle();
            break;

        case Qt::Key_X:
            myTank->changeBulletType();
            break;

        case Qt::Key_Space:
            Bullet *newBullet = nullptr;
            myTank->fireThis(newBullet);
            if (newBullet)
            {
                scene->addItem(newBullet);
                bullets->append(newBullet);
            }
            break;
    }
    scene->update();
}

void TanksGame::enemyTankMoved(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_D:
            enemyTank->moveRight();
            break;

        case Qt::Key_A:
            enemyTank->moveLeft();
            break;

        case Qt::Key_W:
            enemyTank->increaseAngle();
            break;

        case Qt::Key_S:
            enemyTank->decreaseAngle();
            break;

        case Qt::Key_X:
            enemyTank->changeBulletType();
            break;

        case Qt::Key_Space:
            Bullet *newBullet = nullptr;
            enemyTank->fireThis(newBullet);
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
    if (myTank->getHp() <= 0)
    {
        emit iLose();
        return;
    }
    if (enemyTank->getHp() <= 0)
    {
        emit iWin();
        return;
    }
    QVector<Bullet*> *toDelete = new QVector<Bullet*>();

    for (int i = 0; i < explosions->length(); i++)
    {
        if (myTank->collidesWith(explosions->at(i)))
            myTank->getDamage(explosions->at(i)->dealDamage());

        if (enemyTank->collidesWith(explosions->at(i)))
            enemyTank->getDamage(explosions->at(i)->dealDamage());
    }

    for (int i = 0; i < bullets->length(); i++)
    {
        if (myTank->collidesWith(bullets->at(i)))
        {
            scene->removeItem(bullets->at(i));
            toDelete->append(bullets->at(i));

            Explosion *newExplosion = bullets->at(i)->explode();
            explosions->append(newExplosion);
            scene->addItem(newExplosion);
            myTank->getDamage(bullets->at(i)->dealDamage());
            continue;
        }

        if (enemyTank->collidesWith(bullets->at(i)))
        {
            scene->removeItem(bullets->at(i));
            toDelete->append(bullets->at(i));

            Explosion *newExplosion = bullets->at(i)->explode();
            explosions->append(newExplosion);
            scene->addItem(newExplosion);
            enemyTank->getDamage(bullets->at(i)->dealDamage());
            continue;
        }

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

void TanksGame::buildMap()
{
    PieceOfLandscape *firstPiece = new PieceOfLandscape(QPoint(-200, 150), QPoint(0, 100));
    PieceOfLandscape *secondPiece = new PieceOfLandscape(QPoint(0, 100), QPoint(100, 200));
    PieceOfLandscape *thirdPiece = new PieceOfLandscape(QPoint(100, 200), QPoint(150, 150));
    PieceOfLandscape *forthPiece = new PieceOfLandscape(QPoint(150, 150), QPoint(200, 200));

    firstPiece->setNext(secondPiece);
    secondPiece->setPrev(firstPiece);
    secondPiece->setNext(thirdPiece);
    thirdPiece->setPrev(secondPiece);
    thirdPiece->setNext(forthPiece);
    forthPiece->setPrev(thirdPiece);

    landscape->append(forthPiece);
    landscape->append(thirdPiece);
    landscape->append(secondPiece);
    landscape->append(firstPiece);

    for (int i = 0; i < landscape->length(); i++)
        scene->addItem(landscape->at(i));
}

