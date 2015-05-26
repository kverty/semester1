#pragma once

#include <QtWidgets>
#include <QTcpServer>
#include <QtNetwork>

/// client that can send and recieve messages
class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client();

private slots:
    void connectToServer();
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();

    void sendMessage();
    void readMessage();

    void enableSendButton();

private:
    QLabel *hostLabel;
    QLabel *portLabel;
    QLabel *statusLabel;
    QVector<QLabel*> messages;

    QComboBox *hostCombo;

    QLineEdit *portLineEdit;
    QLineEdit *newMessage;

    QPushButton *quitButton;
    QPushButton *connectButton;
    QPushButton *sendButton;
    QDialogButtonBox *buttonBox;

    QTcpSocket *tcpSocket;
    quint16 blockSize;

    int historySize;

    QNetworkSession *networkSession;

    void resetLayout();
};
