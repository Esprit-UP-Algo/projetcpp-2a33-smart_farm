#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");
db.setUserName("hadilchaffar");
db.setPassword("esprit18");

if (db.open())
test=true;
    return  test;
}
void Connection:: closeconnect() {db.close();};
