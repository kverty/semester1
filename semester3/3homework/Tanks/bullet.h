#pragma once
#include <QGraphicsItem>
#include <QPainter>

#include "pieceoflandscape.h"
#include "explosion.h"

/// хранит данные о пуле, рисует ее
class Bullet : public QGraphicsItem
{
public:
    Bullet(QPoint pos, qreal angle);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) Q_DECL_OVERRIDE;

    ///проверяет столкнулась ли пуля с этим куском земли
    bool collidesWith(PieceOfLandscape *landscape);
    /// пуля взрывается
    Explosion *explode();
    /// обновляет положение пули
    void refresh();

private:
    QPoint position;
    QPoint velocity;
    int radius;
};
