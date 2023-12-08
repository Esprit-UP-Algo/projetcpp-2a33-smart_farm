#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
public:
    Connection();
    bool createConnection();  // Méthode pour créer la connexion
    void closeConnection();   // Méthode pour fermer la connexion

private:
    QSqlDatabase db;
};

#endif // CONNECTION_H
