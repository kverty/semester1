#pragma once
#include <QGraphicsItem>
#include <QPainter>

/// храниет данные о взрыве, рисует его
class Explosion : public QGraphicsItem
{
public:
    Explosion(QPoint pos, int radius);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *styleOption, QWidget *widget) Q_DECL_OVERRIDE;

    /// увеличивает зону поражения
    void refresh();
    /// проверяет затух ли взрыв
    bool isDamped();

private:
    QPoint position;
    int maxRadius;
    int curRadius;
};

