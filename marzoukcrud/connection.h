#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection {
    QSqlDatabase db;
public:
    Connection();
    void testConnection();
    ~Connection();
};


#endif // CONNECTION_H
