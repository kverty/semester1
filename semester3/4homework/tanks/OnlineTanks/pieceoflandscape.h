#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>

class PieceOfLandscape : public QGraphicsItem
{
public:
    PieceOfLandscape(QPoint start, QPoint finish);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    /// возвращают соотвествующие поля
    QPoint start();
    QPoint finish();
    PieceOfLandscape *next();
    PieceOfLandscape *prev();

    /// задают соотв поля
    void setNext(PieceOfLandscape *next);
    void setPrev(PieceOfLandscape *prev);

    /// функции, которые описывают движение танка по этому куску земли
    QPoint moveLeft(QPoint position);
    QPoint moveRight(QPoint position);

    /// как считать расстояние до этого куска земли
    qreal distanceTo(QPoint point);

private:
    QPoint mStart;
    QPoint mFinish;
    /// эти два указателя позволяют танку менять кусок земли, на котором он стоит, с помощью одной строчки
    PieceOfLandscape *mNext;
    PieceOfLandscape *mPrev;
    qreal dx;
    qreal dy;
    qreal speed; /// зависит от fps, не от скорости танка
};
