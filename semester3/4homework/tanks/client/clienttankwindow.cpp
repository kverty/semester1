#include "clienttankwindow.h"
#include "ui_clienttankwindow.h"
#include <QtWidgets>
#include <QtNetwork>
#include <iostream>

ClientTankWindow::ClientTankWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientTankWindow),
    tcpSocket(new QTcpSocket(this)), blockSize(0), historySize(10),
    networkSession(nullptr), game(new TanksGame(false))
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

    ui->portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    ui->hostCombo->setEditable(true);

    ui->hostLabel->setBuddy(ui->hostCombo);
    ui->portLabel->setBuddy(ui->portLineEdit);

    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    setWindowTitle(tr("Tank Client"));
    ui->portLineEdit->setFocus();

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
}

ClientTankWindow::~ClientTankWindow()
{
    delete ui;
}

void ClientTankWindow::keyPressEvent(QKeyEvent *event)
{
    std::cout << "i am still working! " << event->key();
    game->myTankMoved(event);
    std::cout << "i am still working! " << event->key();
    if (tcpSocket != nullptr)
        sendMessage(event->key());
}

void ClientTankWindow::connectToServer()
{
    ui->connectButton->setEnabled(false);
    ui->statusLabel->setText("Connected to server, you can send messages");
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(ui->hostCombo->currentText(),
                             ui->portLineEdit->text().toInt());
}

void ClientTankWindow::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Message Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Message Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the message server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Message Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSocket->errorString()));
    }
}

void ClientTankWindow::sessionOpened()
{
    // Save the used configuration
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

    ui->statusLabel->setText(tr("This examples requires that you run the "
                            "Message Server example as well."));

}

void ClientTankWindow::sendMessage(int key)
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

void ClientTankWindow::readMessage()
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

void ClientTankWindow::iWin()
{
    QMessageBox::information(this, "The end", "You win!!", QMessageBox::Ok);
    this->deleteLater();
    QApplication::quit();
}

void ClientTankWindow::iLose()
{
    QMessageBox::information(this, "The end", "You lose", QMessageBox::Ok);
    this->deleteLater();
    QApplication::quit();
}

