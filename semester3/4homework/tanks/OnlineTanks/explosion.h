#pragma once
#include <QGraphicsItem>
#include <QPainter>

/// храниет данные о взрыве, рисует его
class Explosion : public QGraphicsItem
{
public:
    Explosion(QPoint pos, int maxRadius);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) Q_DECL_OVERRIDE;

    /// увеличивает зону поражения
    void refresh();
    /// проверяет затух ли взрыв
    bool isDamped();
    /// сколько урона наносит этот взрыв
    int dealDamage();
    /// расстояние от взрыва до точки
    qreal distanceTo(QPoint point);

private:
    QPoint position;
    int maxRadius;
    int curRadius;
    int damage;
};

