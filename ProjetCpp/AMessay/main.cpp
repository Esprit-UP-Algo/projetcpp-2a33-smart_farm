#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool test=C.createconnection();
    MainWindow w;


    if(test)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),
    QObject::tr("connection successful.\n"
                "click cancel to exit"),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed.\n"
                                                                                      "Click cancel to exit"),QMessageBox::Cancel);
    }
    return a.exec();
    Connection c;
    //bool test1=c.createconnection();
    MainWindow w1;
}
