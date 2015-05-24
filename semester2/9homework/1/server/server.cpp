#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include "server.h"


Server::Server(QWidget *parent): QDialog(parent), hostLabel(new QLabel(tr("&Server name:"))), hostCombo(new QComboBox),
    startButton(new QPushButton(tr("Start"))), statusLabel(new QLabel), quitButton(new QPushButton(tr("Quit"))),
    sendButton(new QPushButton("Send")), newMessage(new QLineEdit("")), tcpServer(nullptr), tcpSocket(nullptr),
    historySize(10), networkSession(nullptr), blockSize(0)

{
    // find out name of this machine
    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        hostCombo->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            hostCombo->addItem(name + QChar('.') + domain);
    }
    if (name != QString("localhost"))
        hostCombo->addItem(QString("localhost"));
    // find out IP addresses of this machine
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // add non-localhost addresses
    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        if (!ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }
    // add localhost addresses
    for (int i = 0; i < ipAddressesList.size(); i++)
    {
        if (ipAddressesList.at(i).isLoopback())
            hostCombo->addItem(ipAddressesList.at(i).toString());
    }

    hostCombo->setEditable(true);

    hostLabel->setBuddy(hostCombo);


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

        statusLabel->setText(tr("Opening network session."));
        networkSession->open();
    }

    connect(startButton, SIGNAL(clicked()), this, SLOT(sessionOpened()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(newMessage, SIGNAL(textChanged(QString)), this, SLOT(enableSendButton()));

    resetLayout();

    setWindowTitle(tr("Message Server"));
}

void Server::sessionOpened()
{
    startButton->setEnabled(false);
    hostCombo->setEnabled(false);
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
    socketForServer->setServerName(hostCombo->currentText());

    tcpServer->setSocketDescriptor(socketForServer->socketDescriptor());
    if (!tcpServer->listen())
    {
        QMessageBox::critical(this, tr("Message Server"),
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
    statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Message Client example now.")
                         .arg(ipAddress).arg(tcpServer->serverPort()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newClient()));
}

void Server::newClient()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    statusLabel->setText(statusLabel->text() + "\nClient connected, you can send messages");
}

void Server::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << newMessage->text();

    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    messages.append(new QLabel("me: " + newMessage->text()));
    resetLayout();
    newMessage->setText("");
    sendButton->setEnabled(false);

    tcpSocket->write(block);
}

void Server::readMessage()
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

    QString newMessage;
    in >> newMessage;

    messages.append(new QLabel("client: " + newMessage));
    resetLayout();
    blockSize = 0;
}

void Server::enableSendButton()
{
    sendButton->setEnabled(!newMessage->text().isEmpty() && tcpSocket != nullptr);
}

void Server::resetLayout()
{
    delete layout();
    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(hostLabel);
    gridLayout->addWidget(hostCombo);
    gridLayout->addWidget(startButton);
    gridLayout->addWidget(statusLabel);

    int startIndex = 0;
    if (historySize < messages.length())
        startIndex = messages.length() - historySize;
    for (int i = startIndex; i < messages.length(); i++)
        gridLayout->addWidget(messages.at(i));

    gridLayout->addWidget(newMessage);
    gridLayout->addWidget(sendButton);
    gridLayout->addWidget(quitButton);

    setLayout(gridLayout);
}

Server::~Server()
{
    delete statusLabel;

    for (int i = 0; i < messages.length(); i++)
        delete messages[i];

    delete quitButton;
    delete sendButton;

    delete newMessage;

    delete tcpSocket;
}
