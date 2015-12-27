#pragma once

#include "bullet.h"

/// переопределен конструктор - задаются параметры тяжелой пули
class HeavyBullet : public Bullet
{
public:
    HeavyBullet(QPoint pos, qreal angle);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) override;
    QPainterPath shape() const override;
};
