#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aliments.h"
#include "aliments.cpp"
#include "mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(afficherAliments());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString dateimp = ui->lineEdit_2->text();
    int ref = ui->lineEdit->text().toInt();
    int refc = ui->lineEdit_6->text().toInt();
    QString datexp = ui->lineEdit_3->text();
    int quantite = ui->lineEdit_5->text().toInt();
    QString type = ui->lineEdit_4->text();
    Aliments a (ref,type,quantite,refc,dateimp,datexp);
    if (a.ajouter() == false) {
        std::cout << "Operation Failed" <<std::endl;
    }
    else {
        ui->tableView->setModel(afficherAliments());
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    Aliments A1; A1.setref(ui->lineEdit_7->text().toInt());
    //QSqlQuery query;
    //QString ref= QString::number(ui->lineEdit_7->text().toInt());
    //.prepare("DELETE from aliments where REF_AL= :ref");
    //query.bindValue(":REF_AL",ref);
    bool test=A1.supprimer(A1.getref());

    if (test) {
            QMessageBox::information(nullptr, QObject::tr("SUCCES"), QObject::tr("Operation Effectuée"),
                                     QMessageBox::Ok);
            ui->tableView->setModel(afficherAliments());
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"), QObject::tr("Operation ECHOUEE"),
                                 QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_13_clicked()
{
    int ref=ui->lineEdit_8->text().toInt();
    QString dateimp=ui->lineEdit_9->text();
    QString datexp=ui->lineEdit_10->text();
    QString type=ui->lineEdit_11->text();
    int quantite=ui->lineEdit_12->text().toInt();
    int refc=ui->lineEdit_13->text().toInt();
    Aliments A2 (ref,type,quantite,refc,dateimp,datexp);
    bool test=A2.modifier(ref);


    if(test)
    {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Update effectue\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);




    }
        else
            { QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Update non effectue.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }



}
void MainWindow::on_pushButton_15_clicked()
{
    Aliments c;
    QSqlQueryModel MyModel;
    ui->tableView_2->setModel(c.trier_type());
    ui->tableView_2->setModel(afficherAliments());

    bool test=c.trier_type();
    if(test)
    {
        ui->tableView_2->setModel(c.trier_type());

                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("tri par type effectué \n"
                                                         "Click Cancel to exist ."),QMessageBox::Cancel);


                }
                else
                     { QMessageBox::critical(nullptr, QObject::tr("non"),
                                  QObject::tr("tri par typr failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
}
void MainWindow::on_pushButton_16_clicked()
{
    Aliments a;
    int refrech = ui->lineEdit_14->text().toInt();

       // Utilisez la méthode Employe::rechercher pour obtenir le modèle de données
       QSqlQueryModel *resultModel = a.rechercher(refrech);

       // Assurez-vous que le modèle de données n'est pas vide et qu'il contient des informations
       if (resultModel && resultModel->rowCount() > 0) {
           // Assurez-vous que votre QTableView "aff3" est correctement configuré dans votre interface graphique
           ui->tableView_2->setModel(resultModel);
       } else {
           // Si le modèle est vide, affichez un message d'erreur
           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet ID.", QMessageBox::Cancel);
       }
}
void MainWindow::on_pushButton_14_clicked()
{     Aliments a;

            // L'onglet "Statistique" est sélectionné
            QMap<QString, int> statistics =a.getquantiteStatistics();
            int totalqt = 0;

            // Calculer le nombre total
            for (const QString &quantite : statistics.keys()) {
                totalqt += statistics[quantite];
            }

            QString message = "\n";

            for (const QString &quantite : statistics.keys()) {
                int count = statistics[quantite];
                double percentage = (static_cast<double>(count) / totalqt) * 100.0;
                message += quantite + ": " + QString::number(count) + " aliments (" + QString::number(percentage, 'f', 2) + "%)\n";
            }

            ui->label_18->setText(message); // Afficher les statistiques dans le QLabel

}

