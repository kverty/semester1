#pragma once

#include "bullet.h"

/// переопределен конструктор - задаются параметры легкой пули
class LightBullet : public Bullet
{
public:
    LightBullet(QPoint pos, qreal angle);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) override;
    QPainterPath shape() const override;
};
