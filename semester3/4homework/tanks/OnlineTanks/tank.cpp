#include "tank.h"
#include <QPainter>
#include <iostream>

Tank::Tank(QPoint pos, PieceOfLandscape *currentLandscape, Qt::GlobalColor color):
    position(pos), currentLandscape(currentLandscape), tankSize(18),
    gunLength(40), gunKalibr(7), angle(pi / 4), angleSpeed(0.07), direction(mLeft),
    hp(100), currentType(light), color(color)
{
    //std::cout << "Tank at " << position.rx() << " " << position.ry() << " at landscape " << currentLandscape->start().rx() << " " << currentLandscape->start().ry() << std::endl;
}

qreal max(qreal number1, qreal number2)
{
    if (number1 > number2)
        return number1;
    return number2;
}

QRectF Tank::boundingRect() const
{
    qreal maxParam = max(tankSize, gunLength);
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
    painter->setPen(QPen(color));
    painter->setBrush(QBrush(color));
    painter->drawConvexPolygon(gunCoords, 4);
    painter->drawEllipse(position, tankSize, tankSize);
    painter->setBrush(QBrush(Qt::black));
    painter->setPen(QPen(Qt::black));
    painter->drawText(position, QString::number(hp));
}

void Tank::moveLeft()
{
    //std::cout << "Tank at " << position.rx() << " " << position.ry();
    direction = mLeft;
    if(position == currentLandscape->start() && !currentLandscape->prev())
        return;

    if (position == currentLandscape->start())
        currentLandscape = currentLandscape->prev();

    position = currentLandscape->moveLeft(position);
    //std::cout << " to " << position.rx() << " " << position.ry() << std::endl;
}

void Tank::moveRight()
{
    direction = mRight;
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
    if (direction == mLeft)
        angleOfBullet = pi - angle;
    if (currentType == light)
        newBullet = new LightBullet(position + QPoint(direction * int(cos(-angle) * gunLength), int(sin(-angle) * gunLength)), angleOfBullet);
    else
        newBullet = new HeavyBullet(position + QPoint(direction * int(cos(-angle) * gunLength), int(sin(-angle) * gunLength)), angleOfBullet);
}

void Tank::getDamage(int damage)
{
    hp -= damage;
}

bool Tank::collidesWith(Bullet *bullet)
{
    return bullet->distanceTo(position) < tankSize;
}

bool Tank::collidesWith(Explosion *explosion)
{
    return explosion->distanceTo(position) < tankSize;
}

void Tank::changeBulletType()
{
    currentType = (currentType + 1) % 2;
}

int Tank::getHp()
{
    return hp;
}
