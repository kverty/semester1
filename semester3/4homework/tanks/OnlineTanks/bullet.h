#pragma once
#include <QGraphicsItem>
#include <QPainter>

#include "pieceoflandscape.h"
#include "explosion.h"

/// хранит данные о пуле, рисует ее
class Bullet : public QGraphicsItem
{
public:
    Bullet(QPoint pos, QPoint velocity, int radius, int damage, int radiusOfExplosion);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) override;
    QPainterPath shape() const override;

    ///проверяет столкнулась ли пуля с этим куском земли
    bool collidesWith(PieceOfLandscape *landscape);
    /// пуля взрывается
    Explosion *explode();
    /// обновляет положение пули
    void refresh();
    /// сколько урона наносит этот снаряд
    int dealDamage();
    /// возвращает расстояние до точки
    qreal distanceTo(QPoint point);

protected:

    QPoint position;
    QPoint velocity;
    int radius;
    int counter;
    int damage;
    int radiusOfExplosion;
};
