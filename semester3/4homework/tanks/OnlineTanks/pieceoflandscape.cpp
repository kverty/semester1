#include "pieceoflandscape.h"

#include <iostream>

PieceOfLandscape::PieceOfLandscape(QPoint start, QPoint finish) :
    mStart(start), mFinish(finish), mNext(nullptr),
    mPrev(nullptr), speed(5)
{
    if (mStart.x() == mFinish.x())
    {
        dy = speed;
        dx = 0;
        return;
    }

    if (mStart.y() == mFinish.y())
    {
        dx = speed;
        dy = 0;
        return;
    }

    if (abs((mStart - mFinish).x()) > abs((mStart - mFinish).y()))
    {
        dy = speed;
        dx = (speed * (mStart - mFinish).x()) / (mStart - mFinish).y();
    }
    else
    {
        dx = speed;
        dy = (speed * (mStart - mFinish).y()) / (mStart - mFinish).x();
    }

    if (dx < 0)
    {
        dx = -dx;
        dy = -dy;
    }
    std::cout << dx << " " << dy << std::endl;
}

QRectF PieceOfLandscape::boundingRect() const
{
    return QRectF(mStart, mFinish);
}

void PieceOfLandscape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::green);
    painter->drawLine(mStart, mFinish);
}

QPoint PieceOfLandscape::start()
{
    return mStart;
}

QPoint PieceOfLandscape::finish()
{
    return mFinish;
}

PieceOfLandscape *PieceOfLandscape::next()
{
    return mNext;
}

PieceOfLandscape *PieceOfLandscape::prev()
{
    return mPrev;
}

void PieceOfLandscape::setNext(PieceOfLandscape *next)
{
    mNext = next;
}

void PieceOfLandscape::setPrev(PieceOfLandscape *prev)
{
    mPrev = prev;
}

QPoint PieceOfLandscape::moveLeft(QPoint position)
{
    return position - QPoint(dx, dy);  
}

QPoint PieceOfLandscape::moveRight(QPoint position)
{
    return position + QPoint(dx, dy);
}

/// две нужные для подсчета расстояния функции
int vectorProduct(QPoint point1, QPoint point2)
{
    return point1.x() * point2.y() - point1.y() * point2.x();
}

int scalarProduct(QPoint point1, QPoint point2)
{
    return point1.x() * point2.x() + point1.y() * point2.y();
}

qreal PieceOfLandscape::distanceTo(QPoint point)
{
    qreal distanceToLine = qreal(vectorProduct(mStart - mFinish, point - mFinish)) / sqrt(scalarProduct(mStart - mFinish, mStart - mFinish));
    if (scalarProduct(mStart - mFinish, point - mFinish) < 0)
        return sqrt(scalarProduct(mFinish - point, mFinish - point));

    if (scalarProduct(mFinish - mStart, point- mStart) < 0)
        return sqrt(scalarProduct(mStart - point, mStart - point));

    return distanceToLine;
}

