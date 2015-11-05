#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <cmath>

#include "pieceoflandscape.h"
#include "bullet.h"

#define pi 3.14159265

enum Direction
{
    right = 1,
    left = -1
};

class Tank : public QGraphicsItem
{
public:
    Tank(QPoint pos, PieceOfLandscape *currentLandscape);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) Q_DECL_OVERRIDE;
    /// методы, вызываемые при нажатии клавиш
    /// стрелка вправо
    void moveRight();
    /// стрелка влево
    void moveLeft();
    /// стрелка вверх
    void increaseAngle();
    /// стрелка вниз
    void decreaseAngle();
    /// пробел
    void fireThis(Bullet* &newBullet);

private:
    QPoint position;
    qreal angle;
    QPoint tankSize;
    int gunLength;
    int gunKalibr;
    int direction;
    /// указатель на кусок земли, на к-ром стоит танк
    PieceOfLandscape *currentLandscape;
    qreal angleSpeed;
};
