#include "heavybullet.h"

HeavyBullet::HeavyBullet(QPoint pos, qreal angle):
    Bullet(pos, QPoint(int(4 *  cos(-angle)), int(4 * sin(-angle))), 5, 5, 30)
{
}

QRectF HeavyBullet::boundingRect() const
{
    return QRectF(radius, radius, 2 * radius, 2 * radius);
}

void HeavyBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawEllipse(position, radius, radius);
}

QPainterPath HeavyBullet::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0), radius, radius);
    return path;
}
