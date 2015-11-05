#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>

#include "pieceoflandscape.h"
#include "tank.h"

class TanksGame : public QGraphicsView
{
    Q_OBJECT

public:
    explicit TanksGame(QWidget *parent = 0);
    ~TanksGame();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    /// вызывается по таймеру, чтобы обновить положение пуль и других автоматически двигающихся объектов
    void moveObjects();

private:
    QTimer *redrawingTimer;
    QGraphicsScene *scene;
    QVector<PieceOfLandscape*> *landscape;
    QVector<Bullet*> *bullets;
    QVector<Explosion*> *explosions;
    Tank *tank;

    void checkForCollisions();
};

