#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aliments.h"
#include "aliments.cpp"
#include "mainwindow.h"
#include <QPdfWriter> // Ajoutez cette ligne pour inclure QPdfWriter
#include <QPainter>
#include <QFont>
#include <QPageSize>
#include <QPageLayout>
#include <QTextDocument>
#include <QMessageBox>
#include <QDate>
#include <QStandardItem>
#include <QStandardPaths>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include <QtCharts/QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include<QChartView>
#include<QChart>
#include <QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts>
#include "sms.h"
#include "ImageDelegate.h"
QString destinationPath;

  using namespace QtCharts;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableView->setModel(afficherAliments());
    ui->tableView->setItemDelegateForColumn(2, new ImageDelegate(this));

    ui->lineEdit_5->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_8->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_2->setValidator(new QIntValidator(0,999,this));
    ui->lineEdit_3->setValidator(new QIntValidator(0,999,this));

    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::showTypeStatistics);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QDate dateimp = ui->dateEdit->date();
    int ref = ui->lineEdit->text().toInt();
    int refc = ui->lineEdit_6->text().toInt();
    int temp=ui->lineEdit_2->text().toInt();
    QDate datexp = ui->dateEdit_2->date();
    int quantite = ui->lineEdit_5->text().toInt();
    QString type = ui->lineEdit_4->text();

    bool idIsValid = false;
               int idValue = ui->lineEdit->text().toInt(&idIsValid);

               if (!idIsValid || ui->lineEdit->text().length() < 6) {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un ref valide (au moins 6 chiffres)."), QMessageBox::Cancel);
                   return;
               }

               QSqlQueryModel *existingAliment = Etmp.rechercher(ref);
                   if (existingAliment->rowCount() > 0) {
                       QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'aliment avec cet ref existe déjà."), QMessageBox::Cancel);
                       delete existingAliment;
                       return;
                   }
                /*if (dateimp.isEmpty() || !dateimp.contains(QRegularExpression("^[a-zA-Z]+$"))) {
                           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une dateimp valide."), QMessageBox::Cancel);
                           return;
                       }

                       if (datexp.isEmpty() || !datexp.contains(QRegularExpression("^[a-zA-Z]+$"))) {
                           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une datexp valide."), QMessageBox::Cancel);
                           return;
                       }*/
                       if (type.isEmpty() || !type.contains(QRegularExpression("^[a-zA-Z]+$"))) {
                           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un type valide."), QMessageBox::Cancel);
                           return;
                       }


    Aliments Etmp (ref,type,temp,quantite,refc,dateimp,datexp,destinationPath);

    bool test = Etmp.ajouter();

        if (test) {
            QMessageBox::information(nullptr, QObject::tr("Succès"),
                                     QObject::tr("Ajout effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de l'ajout.\nClick Cancel to exit."), QMessageBox::Cancel);
        }



           ui->tableView->setModel(afficherAliments());
           ui->tableView->setItemDelegateForColumn(2, new ImageDelegate(this));

}


void MainWindow::on_pushButton_12_clicked()
{
    Aliments Etmp; Etmp.setref(ui->lineEdit_7->text().toInt());
    //QSqlQuery query;
    //QString ref= QString::number(ui->lineEdit_7->text().toInt());
    //.prepare("DELETE from aliments where REF_AL= :ref");
    //query.bindValue(":REF_AL",ref);
    QSqlQueryModel *existingAliment = Etmp.rechercher(ui->lineEdit_7->text().toInt());
        if (existingAliment->rowCount() == 0) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'aliment avec cet ref n'existe pas."), QMessageBox::Cancel);
            delete existingAliment;
            return;
        }
    bool test=Etmp.supprimer(Etmp.getref());

    if (test) {
            QMessageBox::information(nullptr, QObject::tr("SUCCES"), QObject::tr("Operation Effectuée"),
                                     QMessageBox::Ok);
            ui->tableView->setModel(afficherAliments());
            ui->tableView->setItemDelegateForColumn(2, new ImageDelegate(this));
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"), QObject::tr("Operation ECHOUEE"),
                                 QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_13_clicked()
{
    int ref=ui->lineEdit_8->text().toInt();
    QDate dateimp=ui->dateEdit_3->date();
    QDate datexp=ui->dateEdit_4->date();
    int temp=ui->lineEdit_3->text().toInt();
    QString type=ui->lineEdit_11->text();
    int quantite=ui->lineEdit_12->text().toInt();
    int refc=ui->lineEdit_13->text().toInt();
    Aliments Etmp (ref,type,temp,quantite,refc,dateimp,datexp,destinationPath);
    //bool test=Etmp.modifier(ref);
    bool idIsValid = false;
               int idValue = ui->lineEdit_8->text().toInt(&idIsValid);

               if (!idIsValid || ui->lineEdit_8->text().length() < 6) {
                   QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un ref valide (au moins 6 chiffres)."), QMessageBox::Cancel);
                   return;
               }

               QSqlQueryModel *existingAliment = Etmp.rechercher(ref);
                   if (existingAliment->rowCount() == 0) {
                       QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'aliment avec cet ref n'existe pas."), QMessageBox::Cancel);
                       delete existingAliment;
                       return;
                   }
               /*if (dateimp.isEmpty() || !dateimp.contains(QRegularExpression("^[a-zA-Z]+$"))) {
                           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une dateimp valide."), QMessageBox::Cancel);
                           return;
                       }

                       if ( !datexp.contains(QRegularExpression("^[a-zA-Z]+$"))) {
                           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une datexp valide."), QMessageBox::Cancel);
                           return;
                       }*/
                       if (type.isEmpty() || !type.contains(QRegularExpression("^[a-zA-Z]+$"))) {
                           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un type valide."), QMessageBox::Cancel);
                           return;
                       }



    bool test=Etmp.modifier(ref);
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
/*void MainWindow::on_pushButton_14_clicked()
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

}*/
void MainWindow::on_pb_pdf_clicked()
{


    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        if (QFileInfo(fileName).suffix().isEmpty()) {
            fileName.append(".pdf");
        }

        QPdfWriter writer(fileName);
        QPainter painter(&writer);

        int rowCount = ui->tableView->model()->rowCount();
        int columnCount = ui->tableView->model()->columnCount();

        // Décalage vers le bas
        int verticalOffset = 200;

        QString strStream;
        QTextStream out(&strStream);

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("TITLE")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            // Décalage du titre
            "<h1 style='color:#341763; font-family:Montserrat SemiBold; font-size:25px; position:absolute; top:" + QString::number(verticalOffset) + "px; left:50%; transform: translateX(-50%);'>Liste des aliments</h1>\n"

            "<table border=1 cellspacing=0 cellpadding=2 width='100%'>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView->isColumnHidden(column))
                out << QString("<th width='%1%'>%2</th>").arg(100/columnCount).arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView->isColumnHidden(column)) {
                    QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0 width='%1%'>%2</td>").arg(100/columnCount).arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        // Scale the painter
        double scale = 15.0;  // Adjust the scale factor here
        painter.scale(scale, scale);

        document->drawContents(&painter);

        delete document;
    }


}

void MainWindow::showTypeStatistics()
{
    Aliments a;

    // Obtenez les statistiques par type
    QMap<QString, int> statistics = a.getTypeStatistics();

    // Créez un graphique à barres pour afficher les statistiques
    QBarSeries *series = new QBarSeries();

    for (const QString &type : statistics.keys()) {
        QBarSet *set = new QBarSet(type);
        *set << statistics[type];
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par Type");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    //for (const QString &type : statistics.keys()) {
       // categories << type;
    //}

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créez un widget QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Afficher le widget QChartView dans votre interface graphique où vous le souhaitez
    // par exemple, si vous avez un layout horizontal nommé horizontalLayout
    ui->horizontalLayout_2->addWidget(chartView);
}

int MainWindow::getTotalTypeCount(const QMap<QString, int> &statistics)
{
    int totalCount = 0;
    for (int count : statistics.values()) {
        totalCount += count;
    }
    return totalCount;
}

/*void MainWindow::on_crud_tabBarClicked(int index)
{
    // Récupérer l'index de l'onglet "Statistiques" sous l'onglet "CRUD"
    int statisticsTabIndex = ui->crud->indexOf(ui->STATISTIQUE);

    // Vérifier si l'onglet "Statistiques" a été cliqué
    if (index == statisticsTabIndex) {
        // Mettre à jour les statistiques sur le type ici
        updateTypeStatisticsChart();
    } else {
        // Si l'onglet actif n'est pas "Statistiques", supprimer le graphique s'il existe
        clearTypeStatisticsChart();
    }
}

void MainWindow::updateTypeStatisticsChart()
{
    // Récupérer les statistiques réelles

    QMap<QString, int> statistics = Etmp.getTypeStatistics();  // Assurez-vous que "a" est une instance valide de votre classe Aliments

    int totalAliments = 0;

    // Calculer le nombre total d'aliments
    for (const QString &type : statistics.keys()) {
        totalAliments += statistics[type];
    }

    // Créer une série pour le graphique à barres
    QBarSeries *series = new QBarSeries();

    // Ajouter des barres au graphique pour chaque type d'aliment
    for (const QString &type : statistics.keys()) {
        QBarSet *set = new QBarSet(type);
        *set << statistics[type];
        series->append(set);
    }

    // Supprimer le graphique précédent s'il existe
    clearTypeStatisticsChart();

    // Créer un graphique à barres et le configurer
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques par Type d'Aliment");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    for (const QString &type : statistics.keys()) {
        categories << type;
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Créer un widget QChartView pour afficher le graphique
    typeStatisticsChartView = new QChartView(chart);
    typeStatisticsChartView->setRenderHint(QPainter::Antialiasing);
    typeStatisticsChartView->setParent(ui->STATISTIQUE);

    // Ajuster la taille du graphique (par exemple, 600x400 pixels)
    typeStatisticsChartView->setGeometry(70, 50, 600, 400);

    // Afficher le graphique
    typeStatisticsChartView->show();
}

void MainWindow::clearTypeStatisticsChart()
{
    if (typeStatisticsChartView) {
        delete typeStatisticsChartView;
        typeStatisticsChartView = nullptr;
    }
}*/



void MainWindow::on_pushButton_17_clicked()
{
    sms s;
    s.sendSMS("+21628793424","attention temperature est éleve");
}

void MainWindow::on_pushButton_18_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp *jpeg)"));


        if (!imagePath.isEmpty()) {
            // Determine the current working directory
            QString currentDir = QDir::currentPath();


            // Create the Resources folder if it doesn't exist
            QString saveDirectory = currentDir + "/Resources/";
            QDir().mkpath(saveDirectory);


            // Extract the file name from the full path
            QString fileName = QFileInfo(imagePath).fileName();


            // Create the destination path
            destinationPath = saveDirectory + fileName;


            // Copy the file
            if (QFile::copy(imagePath, destinationPath)) {
                qDebug() << "Image copied successfully to:" << destinationPath;


                // Now you can use destinationPath as needed (e.g., store it in the database or display the image)
            } else {
                qDebug() << "Failed to copy image!";
            }
        }
}
