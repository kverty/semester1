#include "servertankwindow.h"
#include "ui_servertankwindow.h"

#include <stdlib.h>
#include <iostream>

ServerTankWindow::ServerTankWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerTankWindow),
    tcpServer(nullptr), tcpSocket(nullptr),
    historySize(10), networkSession(nullptr), blockSize(0),
    game(new TanksGame(true))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(game->getScene());
    connect(game, SIGNAL(iLose()), this, SLOT(iLose()));
    connect(game, SIGNAL(iWin()), this, SLOT(iWin()));

    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        ui->hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            ui->hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QString("localhost"))
        ui->hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        if (!ipAddressesList.at(i).isLoopback())
            ui->hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        if (ipAddressesList.at(i).isLoopback())
            ui->hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    ui->hostCombo->setEditable(true);

    ui->hostLabel->setBuddy(ui->hostCombo);


    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        ui->statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(sessionOpened()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));

    setWindowTitle(tr("Tank Server"));
}

ServerTankWindow::~ServerTankWindow()
{
    delete ui;
}

void ServerTankWindow::keyPressEvent(QKeyEvent *event)
{
    game->myTankMoved(event);
    if (tcpSocket != nullptr)
        sendMessage(event->key());
}

void ServerTankWindow::sessionOpened()
{
    ui->startButton->setEnabled(false);
    ui->hostCombo->setEnabled(false);
    // Save the used configuration
    if (networkSession)
    {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }
    //this->
    tcpServer = new QTcpServer(this);

    QLocalSocket *socketForServer = new QLocalSocket();
    socketForServer->setServerName(ui->hostCombo->currentText());

    tcpServer->setSocketDescriptor(socketForServer->socketDescriptor());
    if (!tcpServer->listen())
    {
        QMessageBox::critical(this, tr("Tank Server"),
                              tr("Unable to start the server: %1.")
                              .arg(tcpServer->errorString()));
        close();
        return;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    ui->statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Tank Client example now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newClient()));
}

void ServerTankWindow::newClient()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    ui->statusLabel->setText(ui->statusLabel->text() + "\nClient connected, you can play");
}

void ServerTankWindow::sendMessage(int key)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << key;

    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    tcpSocket->write(block);
}

void ServerTankWindow::readMessage()
{
    QDataStream in(tcpSocket);

    if (blockSize == 0)
    {
        if (tcpSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (tcpSocket->bytesAvailable() < blockSize)
        return;

    int newMessage;
    in >> newMessage;

    game->enemyTankMoved(new QKeyEvent(QEvent::KeyPress, newMessage, Qt::NoModifier));
    blockSize = 0;
}

void ServerTankWindow::iWin()
{
    QMessageBox::information(this, "The end", "You win!!", QMessageBox::Ok);
    this->deleteLater();
    QApplication::quit();
}

void ServerTankWindow::iLose()
{
    QMessageBox::information(this, "The end", "You lose", QMessageBox::Ok);
    this->deleteLater();
    QApplication::quit();
}
