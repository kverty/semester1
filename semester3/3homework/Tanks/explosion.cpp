#include "explosion.h"

Explosion::Explosion(QPoint pos, int maxRadius): position(pos), maxRadius(maxRadius), curRadius(0)
{
}

QRectF Explosion::boundingRect() const
{
    return QRectF(maxRadius, maxRadius, 2 * maxRadius, 2 * maxRadius);
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::red);
    for (int r = 1; r <= curRadius; r++)
        painter->drawEllipse(position, r, r);
}

void Explosion::refresh()
{
    if (curRadius < maxRadius)
        curRadius += 4;
}

bool Explosion::isDamped()
{
    return curRadius == maxRadius;
}

