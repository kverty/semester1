#include "bullet.h"

Bullet::Bullet(QPoint pos, QPoint velocity, int radius, int damage, int radiusOfExplosion):
    position(pos), velocity(velocity),
    radius(radius), counter(0), damage(damage),
    radiusOfExplosion(radiusOfExplosion)
{
}

QRectF Bullet::boundingRect() const
{
    return QRectF(radius, radius, 2 * radius, 2 * radius);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->setPen(Qt::black);
    painter->drawEllipse(position, radius, radius);
}

QPainterPath Bullet::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0), radius, radius);
    return path;
}

bool Bullet::collidesWith(PieceOfLandscape *landscape)
{
    return landscape->distanceTo(position) < radius;
}

Explosion *Bullet::explode()
{
    return new Explosion(position, radiusOfExplosion);
}

void Bullet::refresh()
{
    position += velocity;
    counter++;
    if (counter % 8 == 0)
        velocity += QPoint(0, 1);
}

int Bullet::dealDamage()
{
    return damage;
}

qreal Bullet::distanceTo(QPoint point)
{
    return sqrt((point.rx() - position.rx()) * (point.rx() - position.rx()) +
                (point.ry() - position.ry()) * (point.ry() - position.ry())) - radius;
}


