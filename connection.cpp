#include "connection.h"
#include "QtDebug"
#include <QSqlError>
#include "QSqlQuery"



Connection::Connection()
{

}

bool Connection::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet2A");

    db.setUserName("yassmine");
    db.setPassword("esprit18");
    //QSqlQuery *query = new QSqlQuery(db);
    //query->exec("EMPLOYES");

    if (db.open())
    {
        qDebug() << "Connexion à la base de données réussie";
        return true;
    }
    else
    {
        QSqlError lastError = db.lastError(); // Utilisez QSqlError pour récupérer l'erreur
        qDebug() << "Échec de la connexion à la base de données : " << lastError.text();
        return false;
    }
}

void Connection::closeConnection()
{
     db.commit();
    db.close();
}
