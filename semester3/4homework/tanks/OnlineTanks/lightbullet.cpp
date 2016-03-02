#include "lightbullet.h"

LightBullet::LightBullet(QPoint pos, qreal angle):
    Bullet(pos, QPoint(int(6 *  cos(-angle)), int(6 * sin(-angle))), 3, 1, 4)
{
}

QRectF LightBullet::boundingRect() const
{
    return QRectF(radius, radius, 2 * radius, 2 * radius);
}

void LightBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawEllipse(position, radius, radius);
}

QPainterPath LightBullet::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0), radius, radius);
    return path;
}

