#include "mainwindow.h"
#include "connection.h"
#include "gestion_equipement.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Connection c;
    bool test=c.createconnect();
    if(test)
    { w.show();
        QMessageBox::information(nullptr, QObject::tr("Donné ouverte"),
                    QObject::tr("succes de la connection.\n"
                                "Appuiez Cancel to exiter"), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Donné introuvable!"),
                    QObject::tr("echec connection.\n"
                                "Appuiez Cancel to exiter."), QMessageBox::Cancel);


    return a.exec();
}


