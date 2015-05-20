#include <QtWidgets>
#include <QtNetwork>

#include "client.h"

Client::Client(QWidget *parent): QDialog(parent), hostLabel(new QLabel(tr("&Server name:"))), portLabel(new QLabel(tr("S&erver port:"))),
    statusLabel(new QLabel(tr("This examples requires that you run the ""Message Server example as well."))),
    hostCombo(new QComboBox), portLineEdit(new QLineEdit), newMessage(new QLineEdit("")), quitButton(new QPushButton(tr("Quit"))),
    connectButton(new QPushButton(tr("Connect"))), sendButton(new QPushButton("Send")), buttonBox(new QDialogButtonBox),
    tcpSocket(new QTcpSocket(this)), blockSize(0), historySize(10), networkSession(nullptr)
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

    portLineEdit->setValidator(new QIntValidator(1, 65535, this));
    hostCombo->setEditable(true);
    sendButton->setEnabled(false);

    hostLabel->setBuddy(hostCombo);
    portLabel->setBuddy(portLineEdit);

    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
    buttonBox->addButton(connectButton, QDialogButtonBox::ActionRole);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(newMessage, SIGNAL(textChanged(QString)), this, SLOT(enableSendButton()));

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    resetLayout();

    setWindowTitle(tr("Message Client"));
    portLineEdit->setFocus();

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
}

Client::~Client()
{
    delete hostLabel;
    delete portLabel;
    delete statusLabel;

    for (int i = 0; i < messages.length(); i++)
        delete messages[i];

    delete hostCombo;

    delete portLineEdit;
    delete newMessage;

    delete quitButton;
    delete connectButton;
    delete sendButton;
    delete buttonBox;

    delete tcpSocket;

    delete networkSession;
}

void Client::connectToServer()
{
    connectButton->setEnabled(false);
    statusLabel->setText("Connected to server, you can send messages");
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost(hostCombo->currentText(),
                             portLineEdit->text().toInt());
}

void Client::displayError(QAbstractSocket::SocketError socketError)
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

void Client::sessionOpened()
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

    statusLabel->setText(tr("This examples requires that you run the "
                            "Message Server example as well."));

}

void Client::sendMessage()
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

void Client::enableSendButton()
{
    sendButton->setEnabled(!newMessage->text().isEmpty() && tcpSocket != nullptr);
}

void Client::readMessage()
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

    messages.append(new QLabel("server: " + newMessage));
    resetLayout();
    blockSize = 0;
}


void Client::resetLayout()
{
    delete layout();

    QGridLayout *mainLayout = new QGridLayout;
    /*mainLayout->addWidget(hostLabel, 0, 0);
    mainLayout->addWidget(hostCombo, 0, 1);
    mainLayout->addWidget(portLabel, 1, 0);
    mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);*/
    mainLayout->addWidget(hostLabel);
    mainLayout->addWidget(hostCombo);
    mainLayout->addWidget(portLabel);
    mainLayout->addWidget(portLineEdit);
    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(buttonBox);

    mainLayout->addWidget(statusLabel);
    int startIndex = 0;
    if (historySize < messages.length())
        startIndex = messages.length() - historySize;
    for (int i = startIndex; i < messages.length(); i++)
        mainLayout->addWidget(messages.at(i));
    mainLayout->addWidget(newMessage);
    mainLayout->addWidget(sendButton);

    setLayout(mainLayout);
}
