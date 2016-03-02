#include "explosion.h"

Explosion::Explosion(QPoint pos, int maxRadius): position(pos), maxRadius(maxRadius), curRadius(0), damage(1)
{
}

QRectF Explosion::boundingRect() const
{
    return QRectF(maxRadius, maxRadius, 2 * maxRadius, 2 * maxRadius);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::white);
    for (int r = curRadius / 2; r > 0; r--)
        painter->drawEllipse(position, 2 * r, 2 * r);
}

void Explosion::refresh()
{
    if (curRadius < maxRadius)
        curRadius += 4;
}

bool Explosion::isDamped()
{
    return curRadius >= maxRadius;
}

int Explosion::dealDamage()
{
    return damage;
}

qreal Explosion::distanceTo(QPoint point)
{
    return sqrt((point.rx() - position.rx()) * (point.rx() - position.rx()) +
                (point.ry() - position.ry()) * (point.ry() - position.ry())) - curRadius;
}

