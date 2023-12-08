#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
#include "video.h"



#include "gestion_equipement.h"

#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include<QPdfWriter>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QPainter>


#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      player(new QMediaPlayer(this))
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ajouter_clicked()
{
    QString id_e_string = ui->id->text();
        bool ok;
        int id_e = id_e_string.toInt(&ok);
        if (!ok) {
            // Display error message for invalid input
            QMessageBox::warning(this, "Invalide", "Entrerz un ID entier.");
            return;
        }

        QString nom_e = ui->nom->text();
        QString etat_e = ui->etat->text();
        QString dispo_e = ui->dispo->text();
        QString qt_e = ui->qt->text();


        // Set up a QIntValidator to accept only integer values
        QIntValidator* phoneValidator = new QIntValidator(this);
        ui->qt->setValidator(phoneValidator);


       QRegularExpression QuantiteRegex("[0-9]");
            QRegularExpressionMatch match = QuantiteRegex.match(qt_e);

            if (!match.hasMatch()) {
                QMessageBox::warning(this, "Invalid Quantity", "Please enter a valid Quantity )");
                return;
            }

            QRegularExpression EtatRegex("^(bon|tres bon|mauvais)$");
            QRegularExpressionMatch match1 = EtatRegex.match(etat_e);

            if (!match1.hasMatch()) {
                QMessageBox::warning(this, "Etat Invalide", "Entrez (bon/tres bon/mauvais)");
                return;
            }


        gestion_equipement tr(id_e, nom_e,etat_e,dispo_e,qt_e);
        bool test = tr.ajouter();

        QMessageBox msgBox;
        if (test) {
            msgBox.setText("ajout avec succes");
            msgBox.exec();
        } else {
            msgBox.setText("echec");
            msgBox.exec();
        }

        ui->affiche_tab->setModel(tr.afficher());
}

void MainWindow::on_modidier_clicked()
{
    int id_e=ui->id->text().toInt();
              QString nom_e=ui->nom->text();
              QString etat_e=ui->etat->text();
              QString dispo_e=ui->dispo->text();
              QString qt_e=ui->qt->text();


              // Set up a QIntValidator to accept only integer values
              QIntValidator* phoneValidator = new QIntValidator(this);
              ui->qt->setValidator(phoneValidator);


             QRegularExpression QuantiteRegex("[0-9]");
                  QRegularExpressionMatch match = QuantiteRegex.match(qt_e);

                  if (!match.hasMatch()) {
                      QMessageBox::warning(this, "Invalid Quantity", "Please enter a valid Quantity )");
                      return;
                  }

                  QRegularExpression EtatRegex("^(bon|tres bon|mauvais)$");
                  QRegularExpressionMatch match1 = EtatRegex.match(etat_e);

                  if (!match1.hasMatch()) {
                      QMessageBox::warning(this, "Invalid Etat", "Please enter a valid etat (bon/tres bon/mauvais)");
                      return;
                  }



           gestion_equipement eq(id_e,nom_e,etat_e,dispo_e,qt_e);



            bool test=eq.modifier(id_e,nom_e,etat_e,dispo_e,qt_e);

              if(test)

            {ui->affiche_tab->setModel(eq.afficher());

            QMessageBox::information(nullptr, QObject::tr("Modifier avec succées "),

                              QObject::tr("invite modifiée.\n"

                                          "Click ok to exit."), QMessageBox::Ok);



            }

              else

                  QMessageBox::critical(nullptr, QObject::tr("Modifier a echoué"),

                              QObject::tr("echec d'ajout !.\n"

                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_clicked()
{
    gestion_equipement eq;
      int id_e = ui->id->text().toInt();
      bool test = eq.supprimer(id_e);
      if (test) {
          QMessageBox::information(nullptr, QObject::tr("Ok"),
                                   QObject::tr("Suppression effectuée.\n"
                                               "Click Ok to exit."), QMessageBox::Ok);
      } else {
          QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                                QObject::tr("Échec de la suppression.\n"
                                            "L'equipement n'existe pas dans la base de données."),
                                QMessageBox::Cancel);
      }
      ui->affiche_tab->setModel(eq.afficher());
}


void MainWindow::on_afficher_clicked()
{
    gestion_equipement eq;
       ui->affiche_tab->setModel(eq.afficher());
}

void MainWindow::on_affiche_tab_activated(const QModelIndex &index)
{
    QString val=ui->affiche_tab->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from EQUIPEMENT where ID_E='"+val+"'");
      if(qry.exec())
      {
       while(qry.next())
       {ui->id->setText(qry.value(0).toString());
        ui->nom->setText(qry.value(1).toString());
        ui->etat->setText(qry.value(2).toString());
        ui->dispo->setText(qry.value(3).toString());
         ui->qt->setText(qry.value(4).toString());

       }
      }
      else
      {//qDebug()<<"Erreur  \n";
       QMessageBox::critical(this,tr("error::"),qry.lastError().text());
      }
}

void MainWindow::on_pb_recherche_clicked()
{  gestion_equipement eq;
    int nbe = ui->rechercher->text().toInt();

    QSqlQueryModel *resultModel = eq.rechercher(nbe);

    if (resultModel && resultModel->rowCount() > 0) {
        // Assuming you have a QTableWidget named ui->recherche_tab
        ui->recherche_tab->setRowCount(resultModel->rowCount());
        ui->recherche_tab->setColumnCount(resultModel->columnCount());

        for (int row = 0; row < resultModel->rowCount(); ++row) {
            for (int col = 0; col < resultModel->columnCount(); ++col) {
                QModelIndex index = resultModel->index(row, col);
                QTableWidgetItem *item = new QTableWidgetItem(index.data().toString());
                ui->recherche_tab->setItem(row, col, item);
            }
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet id.", QMessageBox::Cancel);
    }
}
using namespace QtCharts;



void MainWindow::on_pb_pdf_clicked()
{

    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            filePath = QDir(filePath).filePath("smartfarm0/ListeEquipement.pdf");
            QPdfWriter pdf(filePath);

               QPainter painter(&pdf);
               int i = 4100;
          const QImage image("C:/Users/pc/Desktop/image/logo.png");
                           const QPoint imageCoordinates(155,0);
                           int width1 = 1600;
                           int height1 = 1600;
                           QImage img=image.scaled(width1,height1);
                           painter.drawImage(imageCoordinates, img );


                    QColor dateColor(0x4a5bcf);
                      painter.setPen(dateColor);

                      painter.setFont(QFont("Montserrat SemiBold", 11));
                      QDate cd = QDate::currentDate();
                      painter.drawText(8400,250,cd.toString("Tunis"));
                      painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

                      QColor titleColor(0x341763);
                      painter.setPen(titleColor);
                      painter.setFont(QFont("Montserrat SemiBold", 25));

                      painter.drawText(3000,2700,"liste des equipements");

                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Time New Roman", 15));
                      //painter.drawRect(100,100,9400,2500);
                      painter.drawRect(100,3300,9400,500);

                      painter.setFont(QFont("Montserrat SemiBold", 10));

                      painter.drawText(700,3600,"id");
                      painter.drawText(2100,3600,"nom");
                      painter.drawText(3500,3600,"etat");
                      painter.drawText(4900,3600,"disponibilité");
                      painter.drawText(6300,3600,"qualité") ;
                      painter.setFont(QFont("Montserrat", 10));
                      painter.drawRect(100,3300,9400,9000);

                      QSqlQuery query;
                      query.prepare("select * from EQUIPEMENT");
                      query.exec();
                      int y=4300;
                      while (query.next())
                      {
                          painter.drawLine(100,y,9490,y);
                          y+=500;
                          painter.drawText(700,i,query.value(0).toString());
                          painter.drawText(2100,i,query.value(1).toString());
                          painter.drawText(3500,i,query.value(2).toString());
                          painter.drawText(4900,i,query.value(3).toString());
                          painter.drawText(6300,i,query.value(4).toString());


                         i = i + 500;
                      }
                      QMessageBox::information(nullptr,QObject::tr("Pdf created"),
                      QObject::tr("File created with seccess.\n"
                                  ""),QMessageBox::Ok);
}


void MainWindow::on_pb_stat_clicked()
{

    gestion_equipement eq;
        QStringList equipmentNames = eq.liste_Sum();

        QBarSeries *series = new QBarSeries();

        foreach (const QString &equipmentName, equipmentNames) {
            QBarSet *barSet = new QBarSet(equipmentName);
            int totalQuantity = eq.sumQuantityByNoun(equipmentName);
            *barSet << totalQuantity;
            series->append(barSet);
        }

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistique de la quantité de l'equipement par le nom ");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        foreach (const QString &equipmentName, equipmentNames) {
            categories << equipmentName;
        }

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axisX, series);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(800, 600);
        chartView->show();
}


void MainWindow::on_pdf_trier_clicked()
{


    gestion_equipement eq;

    // Sort the model by ID
    QSqlQueryModel *sortedModel = eq.tri_id();

    if (sortedModel) {
        // Display the sorted model in the table view
        ui->affiche_tab->setModel(sortedModel);

        QMessageBox::information(nullptr, QObject::tr("Trier les équipements par ID"),
                                 QObject::tr("Tri effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Trier les équipements par ID"),
                              QObject::tr("Échec du tri.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }


}



void MainWindow::on_pb_camera_clicked()
{
    camera =new Camera(this);
    camera->show();
}


void MainWindow::on_pb_importervid_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Video File (*.*)");
       if (!filename.isEmpty()) {
           on_pb_stop_clicked();
           player->setMedia(QUrl::fromLocalFile(filename));
           on_pb_play_clicked();
       } else {
           ui->statusbar->showMessage("No file selected.");
       }

}

void MainWindow::on_pb_play_clicked()
{

    if (player->mediaStatus() == QMediaPlayer::NoMedia) {
        ui->statusbar->showMessage("No media loaded.");
        return;
    }

    player->play();
    ui->statusbar->showMessage("Playing");
}
void MainWindow::on_pb_stop_clicked()
{
    player->stop();
    ui->statusbar->showMessage("Stopped...");
}


void MainWindow::on_pb_pause_clicked()
{
    player->pause();
    ui->statusbar->showMessage("Paused...");

}


