#include "bullet.h"

Bullet::Bullet(QPoint pos, qreal angle): position(pos), velocity(QPoint(int(11 *  cos(-angle)), int(11 * sin(-angle)))), radius(6)
{
}

QRectF Bullet::boundingRect() const
{
    return QRectF(radius, radius, 2 * radius, 2 * radius);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(position, radius, radius);
}

bool Bullet::collidesWith(PieceOfLandscape *landscape)
{
    return landscape->distanceTo(position) < radius;
}

Explosion *Bullet::explode()
{
    return new Explosion(position, 4 * radius);
}

void Bullet::refresh()
{
    position += velocity;
    velocity += QPoint(0, 1);
}
