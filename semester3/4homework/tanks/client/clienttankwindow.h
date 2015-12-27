#pragma once

#include <QMainWindow>

#include <QtWidgets>
#include <QTcpServer>
#include <QtNetwork>
#include "../OnlineTanks/tanksgame.h"

namespace Ui {
class ClientTankWindow;
}

class ClientTankWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientTankWindow(QWidget *parent = 0);
    ~ClientTankWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void connectToServer();
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();
    /// оповещение второго приложения о наших действиях
    void sendMessage(int key);
    /// получение оповещения о действиях вражеского танка
    void readMessage();
    /// обрабатывают конец игры
    void iWin();
    void iLose();

private:
    Ui::ClientTankWindow *ui;

    QTcpSocket *tcpSocket;
    quint16 blockSize;

    int historySize;

    QNetworkSession *networkSession;

    TanksGame *game;
};
