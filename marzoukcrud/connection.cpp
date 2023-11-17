#include "connection.h"

#include <QMessageBox>
#include <cstdlib>
#include <QObject>


Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("mohamed");
    db.setPassword("esprit18");
}

void Connection::testConnection()
{
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("db is closed"), QObject::tr("Connection failed"),
                                 QMessageBox::Cancel);
        exit(EXIT_FAILURE);
    }
}

Connection::~Connection()
{
    db.close();
}
