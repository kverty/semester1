#include "tank.h"
#include <QPainter>
#include <iostream>

Tank::Tank(QPoint pos, PieceOfLandscape *currentLandscape) : position(pos), currentLandscape(currentLandscape), tankSize(QPoint(30, 30)), gunLength(40), gunKalibr(7), angle(pi / 4), angleSpeed(0.07), direction(left)
{
}

qreal max(qreal number1, qreal number2)
{
    if (number1 > number2)
        return number1;
    return number2;
}

QRectF Tank::boundingRect() const
{
    qreal maxParam = max(tankSize.x(), max(tankSize.y(), gunLength));
    return QRectF(maxParam, maxParam, maxParam, maxParam);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPoint gunCoords[4] =
        {
            position,
            position + QPoint(direction * int(cos(-angle) * gunLength), int(sin(-angle) * gunLength)),
            position + QPoint(direction * int(cos(-angle) * gunLength), int(sin(-angle) * gunLength)) +
                       QPoint(direction * int(sin(angle) * gunKalibr), int(cos(angle) * gunKalibr)),
            position + QPoint(direction * int(sin(angle) * gunKalibr), int(cos(angle) * gunKalibr))
        };

    painter->setBrush(Qt::black);
    painter->drawRect(QRect(position + tankSize / 2, position - tankSize / 2));
    painter->drawConvexPolygon(gunCoords, 4);
}

void Tank::moveLeft()
{
    direction = left;
    if(position == currentLandscape->start() && !currentLandscape->prev())
        return;

    if (position == currentLandscape->start())
        currentLandscape = currentLandscape->prev();

    position = currentLandscape->moveLeft(position);
}

void Tank::moveRight()
{
    direction = right;
    if(position == currentLandscape->finish() && !currentLandscape->next())
        return;

    if (position == currentLandscape->finish())
        currentLandscape = currentLandscape->next();

    position = currentLandscape->moveRight(position);
}

void Tank::decreaseAngle()
{
    if (angle > angleSpeed)
        angle -= angleSpeed;
}

void Tank::increaseAngle()
{
    if (angle < pi / 2 - angleSpeed)
        angle += angleSpeed;
}

void Tank::fireThis(Bullet* &newBullet)
{
    qreal angleOfBullet = angle;
    if (direction == left)
        angleOfBullet = pi - angle;

    newBullet = new Bullet(position + QPoint(direction * int(cos(-angle) * gunLength), int(sin(-angle) * gunLength)), angleOfBullet);
}
