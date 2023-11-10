#include "connection.h"
//#include <QSqlQueryModel>
Connection::Connection(){}
bool Connection::createconnection()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("Source_Projet2A");
    db.setUserName("adem123");
    db.setPassword("adem123");

    if(db.open())test=true;
    return test;
}
void Connection::closeconnection(){db.close();}
