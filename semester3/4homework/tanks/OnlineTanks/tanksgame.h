#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>

#include "pieceoflandscape.h"
#include "tank.h"

class TanksGame : public QObject
{
    Q_OBJECT

public:
    explicit TanksGame(bool isServer, QWidget *parent = 0);
    ~TanksGame();
    /// возвращает построенную сцену
    QGraphicsScene *getScene();
    /// обрабатывают нажатия клавиш нашего и вражеского танка
    void myTankMoved(QKeyEvent *event);
    void enemyTankMoved(QKeyEvent *event);

private slots:
    /// вызывается по таймеру, чтобы обновить положение пуль и других автоматически двигающихся объектов
    void moveObjects();

/// сигналы об окончании игры
signals:
    void iWin();
    void iLose();

private:
    QTimer *redrawingTimer;
    QGraphicsScene *scene;
    QVector<PieceOfLandscape*> *landscape;
    QVector<Bullet*> *bullets;
    QVector<Explosion*> *explosions;
    Tank *myTank;
    Tank *enemyTank;

    void checkForCollisions();
    /// строит карты, landscape
    void buildMap();
};

