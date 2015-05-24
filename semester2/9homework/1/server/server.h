#pragma once

#include <QtWidgets>
#include <QTcpSocket>
#include<QLocalSocket>
#include <QtNetwork>

/// server that can send and recieve messages
class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    ~Server();

private slots:
    void sessionOpened();
    void newClient();

    void sendMessage();
    void readMessage();

    void enableSendButton();

private:
    QLabel *hostLabel;
    QComboBox *hostCombo;
    QPushButton *startButton;

    QLabel *statusLabel;
    QVector<QLabel*> messages;

    QPushButton *quitButton;
    QPushButton *sendButton;

    QLineEdit *newMessage;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    quint16 blockSize;

    int historySize;

    QNetworkSession *networkSession;

    void resetLayout();
};
