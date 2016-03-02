#pragma once
#include <QMainWindow>
#include <QtWidgets>
#include <QTcpSocket>
#include <QLocalSocket>
#include <QtNetwork>
#include "../OnlineTanks/tanksgame.h"

namespace Ui {
class ServerTankWindow;
}

class ServerTankWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerTankWindow(QWidget *parent = 0);
    ~ServerTankWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void sessionOpened();
    void newClient();

    /// оповещение второго приложения о наших действиях
    void sendMessage(int key);
    /// получение оповещения о действиях вражеского танка
    void readMessage();
    /// обрабатывают конец игры
    void iWin();
    void iLose();

private:
    Ui::ServerTankWindow *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    quint16 blockSize;

    int historySize;

    QNetworkSession *networkSession;

    TanksGame *game;
};

