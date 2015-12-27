#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <cmath>
#include <QTimer>

#include "pieceoflandscape.h"
//#include "bullet.h"
#include "lightbullet.h"
#include "heavybullet.h"

#define pi 3.14159265

enum Direction
{
    mRight = 1,
    mLeft = -1
};

enum TypeOfBullet
{
    heavy = 0,
    light = 1
};

class QBasicTimer;

class Tank : public QGraphicsItem
{
public:
    Tank(QPoint pos, PieceOfLandscape *currentLandscape, Qt::GlobalColor color);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) Q_DECL_OVERRIDE;
    /// методы, вызываемые при нажатии клавиш
    /// D
    void moveRight();
    /// A
    void moveLeft();
    /// W
    void increaseAngle();
    /// S
    void decreaseAngle();
    /// пробел
    void fireThis(Bullet* &newBullet);
    /// X
    void changeBulletType();

    /// расстояние от точки до танка
    qreal distanceTo(QPoint point);
    /// танк получает урон
    void getDamage(int damage);
    /// проверяет не попала ли эта пуля в танк
    bool collidesWith(Bullet *bullet);
    /// проверяет не попал ли танк в зону взрыва
    bool collidesWith(Explosion *explosion);
    /// возвращает сколько жизней осталось
    int getHp();

private:
    QPoint position;
    qreal angle;
    int tankSize;
    int gunLength;
    int gunKalibr;
    int direction;
    int hp;
    int currentType;
    /// указатель на кусок земли, на к-ром стоит танк
    PieceOfLandscape *currentLandscape;
    qreal angleSpeed;
    Qt::GlobalColor color;
};
