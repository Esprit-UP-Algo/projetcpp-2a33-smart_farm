#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commandes.h"
#include "connection.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->reference->setValidator(new QIntValidator(0,999999999,this));
    ui->tab_commandes->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int reference=ui->reference->text().toInt();
    QString entreprise=ui->entreprise->text();
    QString objet=ui->objet->text();
    QString type=ui->type->text();
    QString etat=ui->etat->text();
     int date=ui->date->text().toInt();
    int contact=ui->contact->text().toInt();
    QString Email=ui->Email->text();
    Commandes C(reference,entreprise,objet,type,etat,date,contact,Email);
    bool test=C.ajouter();

    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("ajout effectué.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
         ui->tab_commandes->setModel(C.afficher());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("ajout non effectué;\n"
                                                                                       "Click Cancel to exit."),QMessageBox::Cancel);

    }
    }


void MainWindow::on_supprimer_clicked()
{
    Commandes C1;
    C1.setreference(ui->ref->text().toInt());
    bool test =C1.supprimer(C1.get_reference());
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression affectuée \n"
                                             "click exist to cancel"),QMessageBox::Cancel);
        ui->tab_commandes->setModel(C1.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectué;\n"
                                                                                       "Click Cancel to exit."),QMessageBox::Cancel);


    }
}
void MainWindow:: on_modifier_clicked()
{
    int reference=ui->reference->text().toInt();
    QString entreprise=ui->entreprise->text();
    QString objet=ui->objet->text();
    QString type=ui->type->text();
    QString etat=ui->etat->text();
     int date=ui->date->text().toInt();
    int contact=ui->contact->text().toInt();
    QString Email=ui->Email->text();
    Commandes C(reference,entreprise,objet,type,etat,date,contact,Email);
    bool test=C.ajouter();

    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectué.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
         ui->tab_commandes->setModel(C.afficher());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("modification non effectué;\n"
                                                                                       "Click Cancel to exit."),QMessageBox::Cancel);
ui->tab_commandes->setModel(C.afficher());
    }


}
/*
void MainWindow::on_Tri_clicked()
{
        QSqlQuery query;
        query.prepare("select * from COMMANDES ORDER BY DATES ");
        if (query.exec())
        {
            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(query);
            ui->tab_commandes->setModel(model);
        }
        else
        {
            QMessageBox::warning(this, "Error", query.lastError().text());
        }
}
*/
