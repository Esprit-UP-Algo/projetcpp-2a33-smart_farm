#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "QString"
#include "QtDebug"
#include <QMessageBox>
#include "connection.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QPageSize>
#include <QPageLayout>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include<QPdfWriter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts>
#include <QPieSlice>
#include <QDate>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlError>
#include "arduino.h"
#include <QBarSet>
#include <QBarSeries>
#include <QSqlTableModel>
#include <QtNetwork/QSslSocket>
#include <QDesktopServices>
#include <QUrl>
#include <QTextLength>
#include <QVBoxLayout>
#include <QPushButton>
//#include <takeAt>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QStandardItemModel>
#include <QDebug>
#include <QFileSystemWatcher>
#include <QBarSet>
#include <QBarSeries>
#include <QSqlTableModel>
#include <QSqlError>
#include <QObject>
#include <QDate>
#include <QPdfWriter> // Ajoutez cette ligne pour inclure QPdfWriter
#include <QPainter>
#include <QFont>
#include <QPageSize>
#include <QPageLayout>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include<QPdfWriter>
#include <QFileDialog>
#include "commandes.h"
#include "commandes.cpp"
#include <QBarSet>
#include <QBarSeries>
#include <QSqlTableModel>
//////////////////////////MARZOUK/////////////////////
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

//#include "sms.h"
#include "ImageDelegate.h"
QString destinationPath;
using namespace QtCharts;
//int i=0;
//int j = 0;

////////////////////////HADIL/////////////////////////
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "camera.h"
//#include "video.h"



#include "gestion_equipement.h"


#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>



#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



#include <QDesktopServices>
#include <QStandardPaths>

#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QPainter>

///////////////////////////////////////////////////
//////////////////////////////////semah //////////////////////////////
/// #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"
#include "animaux.cpp"
#include "arduino.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QPdfWriter>
#include<QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QTextStream>
#include <QSqlRecord>
#include <QtCharts>
#include <QChartView>
#include <QToolTip>
#include <QtWidgets>
////////////////////////////////
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
  ///////////////////////////////////
   //player(new QMediaPlayer(this))
  ///////////////////////////////
{
    ui->setupUi(this);
    ui->aff->setModel(EM.afficher());

    ui->ID1->setValidator(new QIntValidator(0,999999,this));
    ui->AGE->setValidator(new QIntValidator(0,999999,this));
     ui->TEL1->setValidator(new QIntValidator(0,99999999,this));
      ui->id->setValidator(new QIntValidator(0,999999,this));
       ui->CHERCHER->setValidator(new QIntValidator(0,999999,this));
        ui->NB_ANS1->setValidator(new QIntValidator(0,999999,this));
        ui->SAL1->setValidator(new QIntValidator(0,9999999999,this));
ageStatisticsChartView = nullptr;
  ui->stackedWidget->setCurrentIndex(0);
  ui->comboBox->setModel(EM.afficher());
 //////////////////////////ADEM/////////////////////////////
  QFileSystemWatcher fileWatcher;
      ui->reference->setValidator(new QIntValidator(0,999999999,this));
      ui->contact->setValidator(new QIntValidator(0,99999999,this) );
      //ui->date->setValidator(new QIntValidator(0,99999999,this));
      ui->ref->setValidator(new QIntValidator(0,99999999,this));
      ui->rechercher->setValidator(new QIntValidator(0,999999999,this));
      ui->tab_commandes->setModel(Etmp.afficher());
      connect(&fileWatcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::updateLogHistory);
      //connect(ui->displayhistory, &QPushButton::clicked, this, &MainWindow::on_displayhistory_clicked);
      displayLogHistory();
 /////////////////////////////MARZOUK///////////////////////////////
      ui->tableView_3->setModel(afficherAliments());
      ui->tableView_3->setItemDelegateForColumn(2, new ImageDelegate(this));

      ui->lineEdit->setValidator(new QIntValidator(0,999999,this));
      ui->lineEdit_3->setValidator(new QIntValidator(0,999999,this));
      ui->lineEdit_18->setValidator(new QIntValidator(0,999999,this));
      ui->lineEdit_20->setValidator(new QIntValidator(0,999,this));
      ui->lineEdit_21->setValidator(new QIntValidator(0,999,this));
       ui->lineEdit_23->setValidator(new QIntValidator(0,999999,this));
       ui->lineEdit_24->setValidator(new QIntValidator(0,999999,this));

      connect(ui->pushButton_32, &QPushButton::clicked, this, &MainWindow::showTypeStatistics);
 /* int  ret=A.connect_arduino();
  switch(ret){
  case(0):qDebug()<<"arduino is available and connected to :"<<A.getarduino_port_name();
  break;
  case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
  break;
  case(-1):qDebug()<<"arduino is not available";*/

  }
 // QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));






MainWindow::~MainWindow()
{
    clearAgeStatisticsChart();
    delete ui;
}


void MainWindow::handleDataFromArduino(const QByteArray &data)
{
    // Traitement des données reçues d'Arduino
    qDebug() << "Data from Arduino:" << data;
}


void MainWindow::on_AJOUTER1_clicked()
{

    QString Id= ui->ID1->text();
    QString Nom = ui->NOM1->text();
    QString Prenom = ui->PRENOM1->text();
    QString Email = ui->EMAIL1->text();
    int Age = ui->AGE->text().toInt();
    int Telephone = ui->TEL1->text().toInt();
    QString Etat = ui->ETAT1->text().toLower();
     QString Motpasse = ui->PASSE1->text();
    int  nbAnsFidelite = ui->NB_ANS1->text().toInt();
    int Salaire = ui->SAL1->text().toInt();


       QRegularExpression regexEmail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
       QRegularExpressionValidator emailValidator(regexEmail);

       if (Nom.isEmpty() || !Nom.contains(QRegularExpression("^[a-zA-Z]+$"))) {
           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un nom valide."), QMessageBox::Cancel);
           return;
       }

       if (Prenom.isEmpty() || !Prenom.contains(QRegularExpression("^[a-zA-Z]+$"))) {
           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un prénom valide."), QMessageBox::Cancel);
           return;
       }

       int pos = 0;
       QValidator::State emailValidationState = emailValidator.validate(Email, pos);



       if (emailValidationState != QValidator::Acceptable) {
           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une adresse e-mail valide."), QMessageBox::Cancel);
           return;
       }


    if (Etat.isEmpty() || (Etat != "présent" && Etat != "absent")) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un état valide (présent ou absent)."), QMessageBox::Cancel);
        return;
    }


    QSqlQueryModel *existingEmployeeModel = EM.rechercher(Id);
    if (existingEmployeeModel->rowCount() > 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'employé avec cet ID existe déjà."), QMessageBox::Cancel);
        delete existingEmployeeModel;
        return;
    }
    delete existingEmployeeModel;


    Employe EM(Nom, Prenom, Email, Etat,Motpasse, Id, Telephone, Age,Salaire , nbAnsFidelite);
    bool test = EM.ajouter();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Ajout effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de l'ajout.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
    ui->aff->setModel(EM.afficher());
}

void MainWindow::on_SUPPRIMER1_clicked()
{
    Employe EM;
    QString Id = ui->ID1->text();





    QSqlQueryModel *existingEmployeeModel = EM.rechercher(Id);
    if (existingEmployeeModel->rowCount() == 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'employé avec cet ID n'existe pas."), QMessageBox::Cancel);
        delete existingEmployeeModel;
        return;
    }
    delete existingEmployeeModel;

    bool test = EM.supprimer(Id);

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Suppression effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la suppression.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
     ui->aff->setModel(EM.afficher());
}





void MainWindow::updateAgeStatisticsChart()
{
    QMap<QString, int> statistics = EM.getAgeStatistics();
    int totalEmployees = 0;

    for (const QString &ageGroup : statistics.keys()) {
        totalEmployees += statistics[ageGroup];
    }

    QPieSeries *series = new QPieSeries();
    QStringList greenColors = {"#55AA00", "#458C68", "#005500"};

    int colorIndex = 0;

    for (const QString &ageGroup : statistics.keys()) {
        int count = statistics[ageGroup];
        QPieSlice *slice = series->append(ageGroup, count);

        slice->setLabel(ageGroup + ": " + QString::number(static_cast<double>(count) / totalEmployees * 100, 'f', 2) + "%");

        // Définir la couleur des tranches
        if (colorIndex < greenColors.size()) {
            slice->setBrush(QColor(greenColors[colorIndex]));
        } else {
            slice->setBrush(QColor(Qt::green));
        }

        // Passer à la prochaine nuance de vert
        colorIndex++;
    }

    // Supprimer le graphique précédent s'il existe
    clearAgeStatisticsChart();

    // Créer un graphique circulaire et le configurer
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par groupe d'âge");

    // Définir le fond du graphique comme beige
    chart->setBackgroundBrush(QBrush(QColor("#F5F5DC")));

    // Créer une vue de graphique et l'ajouter à votre interface utilisateur
    ageStatisticsChartView = new QChartView(chart);
    ageStatisticsChartView->setRenderHint(QPainter::Antialiasing);
    ageStatisticsChartView->setParent(ui->STATISTIQUE);
    ageStatisticsChartView->setGeometry(70, 50, 600, 400);
    ageStatisticsChartView->show();
}

void MainWindow::clearAgeStatisticsChart()
{
    if (ageStatisticsChartView)
    {
        delete ageStatisticsChartView;
        ageStatisticsChartView = nullptr;
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    updateAgeStatisticsChart();
}
void MainWindow::on_TRIER_clicked()
{
   ui->aff->setModel(EM.afficher(true));
}



void MainWindow::on_chercher_clicked()
{
    QString idRecherche = ui->CHERCHER->text();


       QSqlQueryModel *resultModel = EM.rechercher(idRecherche);


       if (resultModel && resultModel->rowCount() > 0) {

           ui->aff->setModel(resultModel);
       } else {

           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet ID.", QMessageBox::Cancel);
       }
}

void MainWindow::on_pb_pdf_clicked()
{


    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        if (QFileInfo(fileName).suffix().isEmpty()) {
            fileName.append(".pdf");
        }

        QPdfWriter writer(fileName);
        QPainter painter(&writer);

        int rowCount = ui->aff->model()->rowCount();
        int columnCount = ui->aff->model()->columnCount();

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
            "<h1 style='color:#341763; font-family:Montserrat SemiBold; font-size:25px; position:absolute; top:" + QString::number(verticalOffset) + "px; left:50%; transform: translateX(-50%);'>Liste des employés</h1>\n"

            "<table border=1 cellspacing=0 cellpadding=2 width='100%'>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->aff->isColumnHidden(column))
                out << QString("<th width='%1%'>%2</th>").arg(100/columnCount).arg(ui->aff->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->aff->isColumnHidden(column)) {
                    QString data = ui->aff->model()->data(ui->aff->model()->index(row, column)).toString().simplified();
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

        delete document;  }}

void MainWindow::on_confirmer_clicked()
{
    QString UserName = ui->id->text();
    QString Password = ui->passe->text();

    if (UserName.isEmpty() || Password.isEmpty()) {
        QMessageBox::warning(this, "INVALID", "Veuillez remplir tous les champs.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE ID_EM = :username AND PASSE = :password");
    query.bindValue(":username", UserName);
    query.bindValue(":password", Password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "CONNECTED", "Connecté");
        ui->stackedWidget->setCurrentIndex(1);

    } else {
        QMessageBox::warning(this, "INVALID", "Nom d'utilisateur ou mot de passe incorrect.");
    }
}

void MainWindow::on_verifier_clicked()
{
    EM.updateSalaries();
       ui->aff->setModel(EM.afficher());

        QMessageBox::information(nullptr, QObject::tr("Vérification effectuée"),
                                 QObject::tr("La vérification de fidélité pour tous les employés a été effectuée avec succès."),
                                 QMessageBox::Cancel);
}



void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QMessageBox msgBox;
        QString id_em= ui->comboBox->currentText();

        QSqlQuery qry;

              qry.prepare("SELECT * FROM EMPLOYES where ID_EM='"+id_em+"' ");
              if (qry.exec())
              {
                  while (qry.next())
                  {


                      ui->ID1->setText(qry.value(0).toString());
                        ui->NOM1->setText(qry.value(1).toString());

                        ui->PRENOM1->setText(qry.value(2).toString());
                        ui->EMAIL1->setText(qry.value(3).toString());
                          ui->AGE->setText(qry.value(4).toString());

                          ui->TEL1->setText(qry.value(5).toString());
                          ui->ETAT1->setText(qry.value(6).toString());
                          ui->PASSE1->setText(qry.value(7).toString());
                            ui->NB_ANS1->setText(qry.value(8).toString());

                            ui->SAL1->setText(qry.value(9).toString());
}}}
void MainWindow::on_miseajour1_clicked()
{

    QString id_em = ui->comboBox->currentText();

    if (id_em.isEmpty())
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez sélectionner un employé à mettre à jour."), QMessageBox::Cancel);
        return;
    }

    // Créez un objet Employe avec les nouvelles valeurs
    Employe updatedEmployee;
    // Récupérez les informations directement à partir de la base de données en utilisant l'ID
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE ID_EM=:id_em");
    query.bindValue(":id_em", id_em);
    if (query.exec() && query.next())
    {
        updatedEmployee.setId_EM(query.value(0).toString());
        updatedEmployee.setNom_EM(query.value(1).toString());
        updatedEmployee.setPrenom_EM(query.value(2).toString());
        updatedEmployee.setEmail_EM(query.value(3).toString());
        updatedEmployee.setAge_EM(query.value(4).toInt());
        updatedEmployee.setTelephone_EM(query.value(5).toInt());
        updatedEmployee.setEtat_EM(query.value(6).toString());
        updatedEmployee.setMotpasse_EM(query.value(7).toString());
        updatedEmployee.setNbAnsFidelite(query.value(8).toInt());
        updatedEmployee.setSalaire_EM(query.value(9).toInt());
    }

    // Appelez la méthode de mise à jour de la classe Employe
    bool updateResult = updatedEmployee.modifier();

    if (updateResult)
    {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Mise à jour effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->aff->setModel(EM.afficher()); // Rafraîchissez l'affichage après la mise à jour
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la mise à jour.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}


/*void MainWindow::verifyEmployeeIdInDatabase(const QString &employeeId) {

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE ID_EM = :employeeId");
    query.bindValue(":employeeId", employeeId);

    if (query.exec() && query.next()) {


        QString employeeName = query.value("NOM_EM").toString();


        QByteArray data;
        data.append("Access Granted! Employee: " + employeeName.toUtf8());


        if (A.connect_arduino()
                ) {
            A.write_to_arduino(data);


            QMessageBox::information(this, "Accès autorisé", "L'employé " + employeeName + " a accès autorisé.");
        } else {

            QMessageBox::warning(this, "Erreur Arduino", "Arduino n'est pas disponible. Vérifiez la connexion.");
        }
    } else {

        QByteArray data;
        data.append("Access Denied!");


        if (A.connect_arduino()) {
            A.write_to_arduino(data);
            QMessageBox::warning(this, "Accès refusé", "L'employé n'a pas accès autorisé.");
        } else {

            QMessageBox::warning(this, "Erreur Arduino", "Arduino n'est pas disponible. Vérifiez la connexion.");
        }
    }
}

void MainWindow::update_label()
{
    QByteArray data = A.read_from_arduino(); // Read data from Arduino
Employe e;
     qDebug() <<  A.read_from_arduino();
     data = data.trimmed();


          qDebug() << data;


verifyEmployeeIdInDatabase(data);


   QString hexString = QString::fromLatin1(data).trimmed(); // Convert QByteArray to QString
    bool conversionOk;



    if (!conversionOk) {
        qDebug() << "Invalid Hexadecimal Format";
        return;
        verifyEmployeeIdInDatabase(data);
    }



        qDebug() << hexString;

}*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_COMMANDES_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_EMP1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
     ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_COM1_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_EMPLOYES_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}
void MainWindow::on_ALIMENTATION_2_clicked()
{
   ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_ALM1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
  ui->stackedWidget_2->setCurrentIndex(3);
}


void MainWindow::on_EQUIPEMENTS_2_clicked()
{
 ui->stackedWidget_2->setCurrentIndex(4);
}

void MainWindow::on_EQ1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
  ui->stackedWidget_2->setCurrentIndex(4);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////ADEM////////////////////////////////////////////////
void MainWindow::on_ajouter_clicked()
{
    int reference=ui->reference->text().toInt();

    QString entreprise=ui->entreprise->text();
    QString objet=ui->objet->text();
    int type=ui->type->text().toInt();
    QString etat=ui->etat->text();
     QDate date=ui->date->date();
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
    int nbe=ui->ref->text().toInt();
    if(C1.reference_gcExists(nbe))
    {
        bool test =C1.supprimer(nbe);
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
     ui->tab_commandes->setModel(C1.afficher());

        }


    }

    else
    {
            QMessageBox::warning(nullptr, QObject::tr("Avertissement"),
                                        QObject::tr("La commande n'existe pas."), QMessageBox::Ok);
 ui->tab_commandes->setModel(C1.afficher());

    }



}
void MainWindow:: on_modifier_clicked()
{
    Commandes C;
    int reference=ui->reference->text().toInt();

    QSqlQueryModel *resultModel = C.rechercher(reference);


    if (resultModel && resultModel->rowCount() > 0) {

        QString entreprise=ui->entreprise->text();
        QString objet=ui->objet->text();
        int type=ui->type->text().toInt();
        QString etat=ui->etat->text();
         QDate date=ui->date->date();
        int contact=ui->contact->text().toInt();
        QString Email=ui->Email->text();
        Commandes C(reference,entreprise,objet,type,etat,date,contact,Email);
        bool test=C.modifier();

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
    } else {

        QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet reference.", QMessageBox::Cancel);
    }



}

void MainWindow::on_trie_clicked()
{

    //ui->tab_commandes->setModel(C.afficher());

    ui->tab_commandes->setModel(Etmp.afficher(true,true,true));
}


void MainWindow::on_rechercherb_clicked()
{
    Commandes C;
    int nbe = ui->rechercher->text().toInt();


       QSqlQueryModel *resultModel = C.rechercher(nbe);


       if (resultModel && resultModel->rowCount() > 0) {

           ui->tab_commandes->setModel(resultModel);
       } else {

           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet reference.", QMessageBox::Cancel);
       }
}
void MainWindow::on_PDF_clicked()
{
    {
        QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", QString(), "*.pdf");
        if (!fileName.isEmpty()) {
            if (QFileInfo(fileName).suffix().isEmpty()) {
                fileName.append(".pdf");
            }

            QPdfWriter writer(fileName);
            QPainter painter(&writer);

            int rowCount = ui->tab_commandes->model()->rowCount();
            int columnCount = ui->tab_commandes->model()->columnCount();

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
                "<h1 style='color:#341763; font-family:Montserrat SemiBold; font-size:25px; position:absolute; top:" + QString::number(verticalOffset) + "px; left:50%; transform: translateX(-50%);'>Liste des employés</h1>\n"

                "<table border=1 cellspacing=0 cellpadding=2 width='100%'>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tab_commandes->isColumnHidden(column))
                    out << QString("<th width='%1%'>%2</th>").arg(100/columnCount).arg(ui->tab_commandes->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_commandes->isColumnHidden(column)) {
                        QString data = ui->tab_commandes->model()->data(ui->tab_commandes->model()->index(row, column)).toString().simplified();
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
}

void MainWindow::on_details_clicked()
{
    Commandes C;
    int nbe = ui->reference->text().toInt();


       QSqlQueryModel *resultModel = C.rechercher(nbe);


       if (resultModel && resultModel->rowCount() > 0) {

           ui->tab_ref->setModel(resultModel);
       } else {

           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet Reference.", QMessageBox::Cancel);
       }
}

void MainWindow::updateLogHistory()
{
    qDebug() << "File changed. Updating log history...";
    displayLogHistory();
}

// Function to display log history
/*void MainWindow::displayLogHistory()
{
    // Create a new model
    QStandardItemModel *model = new QStandardItemModel(this);

    // Open the log file for reading
    QFile logFile("actions.log");
    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening the log file for reading:" << logFile.errorString();
        delete model;  // Clean up the model in case of an error
        return;
    }

    // Create headers for the model
    model->setHorizontalHeaderLabels(QStringList() << "Timestamp" << "ActionType" << "ActionDetails");

    // Create a QTextStream to read from the file
    QTextStream in(&logFile);

    // Read and display each line from the file
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');

        // Check if the line has enough parts (columns)
        if (parts.size() >= 4) {
            // Extract the date and time from the first two parts
            QDateTime dateTime = QDateTime::fromString(parts[0] + ' ' + parts[1], "yyyy-MM-dd hh:mm:ss");

            // ActionType is the third and fourth parts
            QString actionType = parts[2] + " " + parts[3];

            // ActionDetails is the concatenation of the remaining parts
            QString actionDetails = parts.mid(4).join(' ');

            // Add a new row to the model
            QList<QStandardItem*> rowItems;
            rowItems.append(new QStandardItem(dateTime.toString("yyyy-MM-dd hh:mm:ss")));
            rowItems.append(new QStandardItem(actionType));
            rowItems.append(new QStandardItem(actionDetails));
            model->appendRow(rowItems);
        }
    }

    // Close the file
    logFile.close();

    // Set the model for the QTableView
    ui->history->setModel(model);

    // Additional settings (optional)
    ui->history->resizeColumnsToContents();  // Adjust column widths
    ui->history->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch the last column

    // Additional debug output
    qDebug() << "Number of rows in the table view:" << model->rowCount();
    qDebug() << "Number of columns in the table view:" << model->columnCount();
    qDebug() << "Headers in the table view:" << model->headerData(0, Qt::Horizontal).toString();

    // Add the log file to the file watcher
    fileWatcher.addPath("actions.log");
}*/
void MainWindow::displayLogHistory()
{
    // Create a new model
    QStandardItemModel *model = new QStandardItemModel(this);

    // Open the log file for reading
    QFile logFile("actions.log");
    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening the log file for reading:" << logFile.errorString();
        delete model;  // Clean up the model in case of an error
        return;
    }

    // Create headers for the model
    model->setHorizontalHeaderLabels(QStringList() << "Timestamp" << "ActionType" << "ActionDetails");

    // Create a QTextStream to read from the file
    QTextStream in(&logFile);

    // Read and display each line from the file
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');

        // Check if the line has enough parts (columns)
        if (parts.size() >= 3) {
            // Extract the date and time from the first two parts
            QDateTime dateTime = QDateTime::fromString(parts[0] + ' ' + parts[1], "yyyy-MM-dd hh:mm:ss");

            // ActionType is the third part
            QString actionType = parts[2] +" "+ parts[3];

            // ActionDetails is the concatenation of the remaining parts
            QString actionDetails = parts.mid(4).join(' ');

            // Add a new row to the model
            QList<QStandardItem*> rowItems;
            rowItems.append(new QStandardItem(dateTime.toString("yyyy-MM-dd hh:mm:ss")));
            rowItems.append(new QStandardItem(actionType));
            rowItems.append(new QStandardItem(actionDetails));
            model->insertRow(0, rowItems);  // Insert at the beginning of the model
        }
    }

    // Close the file
    logFile.close();

    // Set the model for the QTableView
    ui->history->setModel(model);

    // Additional settings (optional)
    ui->history->resizeColumnsToContents();  // Adjust column widths
    ui->history->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch the last column

    // Additional debug output
    qDebug() << "Number of rows in the table view:" << ui->history->model()->rowCount();
}

/*void MainWindow::on_sendmail_clicked()
{

    Commandes C;
    mail* ssmtp = new mail("adem.marghli@esprit.tn", "221JMT4285", "smtp.gmail.com", 465);

              connect(ssmtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

              QString email=ui->mentreprise->text();

              QString b=ui->msujet->text();

              QString ob=ui->mmessage->toPlainText();

               if(email!="" && b!="" && ob!="" )
                  {
                                if(C.isValidEmail(email))
                                {
                                    ssmtp->sendMail("adem.marghli@esprit.tn", email , b,ob);
                                    QMessageBox::information(nullptr, QObject::tr("EMAIL"),
                                    QObject::tr("Email sent successfuly.\n"
                                    "click Cancel to exit"),QMessageBox::Cancel);
                                }
                                else
                                {
                                    QMessageBox::critical(nullptr, QObject::tr("EMAIL"),
                                    QObject::tr("Email failed to send.\n"
                                    "click Cancel to exit."),QMessageBox::Cancel);
                                }
                  }
               else
                  {
                          QMessageBox::critical(nullptr, QObject::tr("EMAIL"),
                          QObject::tr("something is empty.\n"
                          "click Cancel to exit."),QMessageBox::Cancel);
                  }
}

void MainWindow::updateStatistics() {
    // Assuming this function retrieves the count of type0 and type1 commands
    Commandes C;
    int counttype0 = C.comptertype0();
    int counttype1 = C.comptertype1();

    // Assuming set0 and set1 are member variables of MainWindow
    set0->replace(0, counttype1);
    set1->replace(0, counttype0);

    // Refresh the chart view

    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    ui->label_10->chartView()->update();
}*/

void MainWindow::on_refrech_clicked()
{
    QLayoutItem* item;
    while((item=ui->label_18->takeAt(0))!=nullptr)
       {
delete item->widget();
        delete item;
    }
    QBarSet *set0 = new QBarSet("Achat");
    QBarSet *set1 = new QBarSet("Vente ");
Commandes C;
    int counttype0 = C.comptertype_gc0();
                int counttype1 = C.comptertype_gc1();
                * set0 <<counttype1<<10 ;

                * set1 << counttype0<<10;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("COMMANDES");
        chart->setAnimationOptions(QChart:: SeriesAnimations);
        chart->resize(450,300);
        QStringList categories;
        categories << " TYPE" ;
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);
        QChartView *chartView = new QChartView(chart);
       ui->label_18->addWidget(chartView);

}

void MainWindow::on_displayhistory_clicked()
{
    displayLogHistory();
}

/*void MainWindow::on_deletehistory_clicked()
{
    Commandes C1;
        bool test = C1.deletehistory();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Suppression effectuée\n"
                                                 "Les actions ont été supprimées du fichier."),
                                     QMessageBox::Cancel);

            // Update the log history model after deletion
            //updateLogHistoryModel();
            displayLogHistory();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Suppression non effectuée;\n"
                                                                              "Cliquez sur Annuler pour sortir."),
                                  QMessageBox::Cancel);
        }
}*/
/*void MainWindow::on_sendmail_clicked() {
    QString to = ui->mentreprise->text();
    QString subject = ui->msujet->text();
    QString body = ui->mmessage->toPlainText();

    sendEmail(to, subject, body);
}*/

void MainWindow::on_affichercommande_clicked()
{
    Commandes C;
    ui->tab_commandes->setModel(C.afficher());
}
/*void MainWindow::on_sendMail_clicked()
{
    qDebug() << "Sending email...";

        // Get the user input from the line edits
        QString entrepriseEmail = ui->mentreprise->text();
        QString message = ui->mmessage->toPlainText();


        // Validate the email address
        if (!isValidEmail(entrepriseEmail)) {
            qDebug() << "Invalid email address";
            QMessageBox::critical(this, "Error", "Invalid email address");
            return;
        }

        // Create an instance of the smtp class with your email credentials
        Smtp *S = new Smtp("ademmarghli@gmail.com", "olpa ebss qxzq rmcj", "smtp.gmail.com", 465);

        qDebug() << "Email content:";
        qDebug() << "To: " << entrepriseEmail;
        qDebug() << "Subject: Subject";
        qDebug() << "Body: " << message;

        // Send the email
        S->sendMail("smtp@gmail.com", entrepriseEmail, "Subject", message);

        // Check for successful email sending
        if (S->getSocketState() == QAbstractSocket::ConnectedState) {
            qDebug() << "Email sent successfully!";

            // Additional debugging information
            qDebug() << "Socket state:" << S->getSocketState();
            qDebug() << "Socket error string:" << S->getSocketErrorString();
            qDebug() << "SMTP server response:" << S->getServerResponse();

            QMessageBox::information(this, "Email Sent", "The email has been sent successfully!");
        } else {
            qDebug() << "Error sending email:" << S->getSocketErrorString();

            // Additional debugging information
            qDebug() << "Socket state:" << S->getSocketState();
            qDebug() << "Socket error string:" << S->getSocketErrorString();
            qDebug() << "SMTP server response:" << S->getServerResponse();

            QMessageBox::warning(this, "Error", "Error sending email. Check the console for details.");
        }

        // Cleanup
        delete S;
}

bool MainWindow::isValidEmail(const QString &email)
{
    // Simple email validation using a regular expression
        QRegExp emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");
        return emailRegex.exactMatch(email);
}*/
/*void MainWindow::sendMail()
{
    smtp* smtp = new class smtp (ui->uname->text(), ui->paswd->text(), "smtp.gmail.com",465);//username=uname //
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            smtp->sendMaile(ui->uname->text(), ui->mentreprise->text() , ui->msujet->text(),ui->mmessage->toPlainText());
}
void MainWindow::on_sendMail_clicked()
{
    sendMail();
}
void MainWindow::handleSmtpStatus(const QString& status)
{
    qDebug() << "SMTP Status:" << status;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////MARZOUK///////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_clicked()
{

    QDate dateimp = ui->dateEdit_5->date();
    int ref = ui->lineEdit->text().toInt();
    int refc = ui->lineEdit_4->text().toInt();
    int temp=ui->lineEdit_17->text().toInt();
    QDate datexp = ui->dateEdit_6->date();
    int quantite = ui->lineEdit_3->text().toInt();
    QString type = ui->lineEdit_2->text();

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



           ui->tableView_3->setModel(afficherAliments());
           ui->tableView_3->setItemDelegateForColumn(2, new ImageDelegate(this));

}


void MainWindow::on_pushButton_24_clicked()
{
    Aliments Etmp; Etmp.setref(ui->lineEdit_23->text().toInt());
    //QSqlQuery query;
    //QString ref= QString::number(ui->lineEdit_7->text().toInt());
    //.prepare("DELETE from aliments where REF_AL= :ref");
    //query.bindValue(":REF_AL",ref);
    QSqlQueryModel *existingAliment = Etmp.rechercher(ui->lineEdit_23->text().toInt());
        if (existingAliment->rowCount() == 0) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'aliment avec cet ref n'existe pas."), QMessageBox::Cancel);
            delete existingAliment;
            return;
        }
    bool test=Etmp.supprimer(Etmp.getref());

    if (test) {
            QMessageBox::information(nullptr, QObject::tr("SUCCES"), QObject::tr("Operation Effectuée"),
                                     QMessageBox::Ok);
            ui->tableView_3->setModel(afficherAliments());
            ui->tableView_3->setItemDelegateForColumn(2, new ImageDelegate(this));
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("ERREUR"), QObject::tr("Operation ECHOUEE"),
                                 QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_13_clicked()
{
    int ref=ui->lineEdit_18->text().toInt();
    QDate dateimp=ui->dateEdit_7->date();
    QDate datexp=ui->dateEdit_8->date();
    int temp=ui->lineEdit_22->text().toInt();
    QString type=ui->lineEdit_19->text();
    int quantite=ui->lineEdit_20->text().toInt();
    int refc=ui->lineEdit_21->text().toInt();
    Aliments Etmp (ref,type,temp,quantite,refc,dateimp,datexp,destinationPath);
    //bool test=Etmp.modifier(ref);
    bool idIsValid = false;
               int idValue = ui->lineEdit_18->text().toInt(&idIsValid);

               if (!idIsValid || ui->lineEdit_18->text().length() < 6) {
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
    ui->tableView_4->setModel(c.trier_type());
    ui->tableView_4->setModel(afficherAliments());

    bool test=c.trier_type();
    if(test)
    {
        ui->tableView_4->setModel(c.trier_type());

                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("tri par type effectué \n"
                                                         "Click Cancel to exist ."),QMessageBox::Cancel);


                }
                else
                     { QMessageBox::critical(nullptr, QObject::tr("non"),
                                  QObject::tr("tri par typr failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);}
}
void MainWindow::on_pushButton_12_clicked()
{
    Aliments a;
    int refrech = ui->lineEdit_24->text().toInt();

       // Utilisez la méthode Employe::rechercher pour obtenir le modèle de données
       QSqlQueryModel *resultModel = a.rechercher(refrech);

       // Assurez-vous que le modèle de données n'est pas vide et qu'il contient des informations
       if (resultModel && resultModel->rowCount() > 0) {
           // Assurez-vous que votre QTableView "aff3" est correctement configuré dans votre interface graphique
           ui->tableView_4->setModel(resultModel);
       } else {
           // Si le modèle est vide, affichez un message d'erreur
           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet ref.", QMessageBox::Cancel);
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
void MainWindow::on_pb_pdf1_clicked()
{


    QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        if (QFileInfo(fileName).suffix().isEmpty()) {
            fileName.append(".pdf");
        }

        QPdfWriter writer(fileName);
        QPainter painter(&writer);

        int rowCount = ui->tableView_3->model()->rowCount();
        int columnCount = ui->tableView_3->model()->columnCount();

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
            if (!ui->tableView_3->isColumnHidden(column))
                out << QString("<th width='%1%'>%2</th>").arg(100/columnCount).arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_3->isColumnHidden(column)) {
                    QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
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
QLayoutItem* item;
while((item=ui->horizontalLayout_3->takeAt(0))!=0)
{

delete item->widget();
      delete item;
}
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
    ui->horizontalLayout_3->addWidget(chartView);
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



/*void MainWindow::on_pushButton_17_clicked()
{
    sms s;
    s.sendSMS("+21628793424","attention temperature est éleve");
}*/

void MainWindow::on_pushButton_30_clicked()
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

/*void MainWindow::on_feu_clicked()
{

    Aliments a;
    d = A.read_from_arduino();
    sms s;

   double value = d.toDouble(); // Assuming data is a QByteArray from A.read_from_arduino()

   qDebug() << a.gettemperature_gal_forLait();
     qDebug() << value;

   if (a.gettemperature_gal_forLait() < value && value < 45 && i == 0)
   {
       i = 1;
       A.write_to_arduino("1");

       s.sendSMS("+21628793424","attention temperature est éleve");
       QMessageBox::critical(nullptr, QObject::tr("Attention"),
               QObject::tr("La température a augmenté.\n"), QMessageBox::Cancel);
      }
   if( j == 0 ){
       j =  1;
       double temperatureValue = Etmp.gettemperature_gal_forLait();

          // Convert the temperature value to a string
          QString temperatureString = QString::number(temperatureValue);
          // Send the temperature value to Arduino
          // Send the temperature value to Arduino
           QByteArray dataToSend = temperatureString.toUtf8();
            qDebug() << dataToSend;
            qDebug() << temperatureString;
            qDebug() << temperatureValue;
            A.write_to_arduino(dataToSend);
}



}
*/
/////////////////////////////////////////////////////////HADIL/////////////////////////////////////////////////////////////////////
void MainWindow::on_ajouterr_clicked()
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

            QRegularExpression EtatRegex("^(bon | tres bon | mauvais)$");
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

void MainWindow::on_supprimer1_clicked()
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



void MainWindow::on_pb_pdf2_clicked()
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
     Camera *camera;
    camera =new Camera(this);
    camera->show();
}

/*
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
*/





void MainWindow::on_ANIMAUX_2_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_AN1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
     ui->stackedWidget_2->setCurrentIndex(2);
}
/////////////////////////////////////////////////////////// semah may /////////////////////////////////////////

void MainWindow::on_pushButton_14_clicked()
{
    int id_a=ui->le_id->text().toInt();
    QString type_a=ui->le_type->text();
    int age_a=ui->le_age->text().toInt();
    QString status_a=ui->le_status->text();
    int nombre_a=ui->le_nombre->text().toInt();


    animaux a(id_a,type_a,age_a,status_a,nombre_a);
    bool test=a.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
       { QMessageBox::critical(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
      ui->tab_19->setModel(Etmp.afficher());

}
void MainWindow::on_pushButton_3_clicked()
{
    animaux a;
    int id_a=ui->le_id_2->text().toInt();
    bool test=Etmp.supprimer(id_a);
             if(test)
             {
               QMessageBox::information(nullptr, QObject::tr("Supprimer"),
                             QObject::tr(" supprimé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

             }
             else
             {QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
             ui->tab_19->setModel(Etmp.afficher());
}

void MainWindow::on_pushButton_4_clicked()
{

    int id_a=ui->le_id_3->text().toInt();
    QString type_a=ui->le_type_2->text();
    int age_a=ui->le_age_2->text().toInt();
    QString status_a=ui->le_status_2->text();
    int nombre_a=ui->le_nombre_2->text().toInt();

    animaux a(id_a,type_a,age_a,status_a,nombre_a);
    bool test=a.modifier(id_a,type_a,age_a,status_a,nombre_a);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifier"),
                    QObject::tr("ajouter successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
       { QMessageBox::critical(nullptr, QObject::tr("modifier"),
                    QObject::tr("ajouter failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
    ui->tab_19->setModel(Etmp.afficher());
}

void MainWindow::on_pushButton_5_clicked()
{
    animaux a;
        ui->tab_23->setModel(a.aff_nombre());
}

void MainWindow::on_pushButton_6_clicked()
{
    animaux a;
        ui->tab_23->setModel(a.aff_age());
}

void MainWindow::on_pushButton_7_clicked()
{
    animaux a;
    ui->tab_23->setModel(a.recherche(ui->le_id_4->text(),ui->le_id_4->text()));
}

void MainWindow::on_pushButton_8_clicked()
{
    QPdfWriter pdf("C:\project_pdf");
        int i = 4000;
        QPainter painter(&pdf);
        QString strStream;

        QTextStream out(&strStream);
        painter.setPen(Qt::red);
        painter.setFont(QFont("Time New Roman", 25));
        painter.drawText(3000,1400,"Liste Des Animaux");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Time New Roman", 7));
        painter.setPen(Qt::darkCyan);
        painter.drawRect(100,100,9400,2500);
        painter.drawRect(100,3000,9400,500);
        painter.setPen(Qt::black);
        painter.drawText(300,3300," ID_A");
        painter.drawText(1300,3300,"TYPE_A");
        painter.drawText(2300,3300,"AGE_A");
        painter.drawText(3300,3300,"STATUS_A");
        painter.drawText(4300,3300,"NOMBRE_A");
        painter.setPen(Qt::darkCyan);
        painter.drawRect(100,3000,9400,9000);
        painter.setPen(Qt::black);
        QSqlQuery query;
        query.prepare("SELECT * FROM ANIMAUX");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2300,i,query.value(2).toString());
            painter.drawText(3300,i,query.value(3).toString());
            painter.drawText(4300,i,query.value(4).toString());
            i +=350;
        }
            QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
            QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_9_clicked()
{
    QSqlQueryModel*model=new QSqlQueryModel();
        model->setQuery("SELECT status_a FROM ANIMAUX ");

    int countmalade = 0;
    int countdecede = 0;
    int countsains  = 0;

    for (int i = 0; i < model->rowCount(); i++) {
        QString status_a = model->record(i).value("status_a").toString();

        if (status_a == "malade") {
            countmalade++;
        } else if (status_a == "sains") {
            countsains++;
        }
        else if (status_a == "decede") {
            countdecede++;
        }
}
    int total = countmalade + countdecede + countsains ;

       QPieSeries *series = new QPieSeries();
       series->append("malade", countmalade);
       series->append("decede", countdecede);
       series->append("sains", countsains);

       if (countmalade != 0) {
           QPieSlice *slice = series->slices().at(0);
           slice->setLabel("malade" + QString("%1%").arg(100*slice->percentage(),3,'f',1));
           slice->setLabelVisible();
           slice->setPen(QPen(Qt::cyan));
       }

       if (countdecede != 0) {
           QPieSlice *slice1 = series->slices().at(1);
           slice1->setLabel("decede" + QString("%1%").arg(100*slice1->percentage(),3,'f',1));
           slice1->setLabelVisible();
           slice1->setBrush(QColor(Qt::red));
       }
       if (countsains != 0) {
           QPieSlice *slice1 = series->slices().at(2);
           slice1->setLabel("sains" + QString("%1%").arg(100*slice1->percentage(),3,'f',1));
           slice1->setLabelVisible();
           slice1->setBrush(QColor(Qt::red));
       }



       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Total " + QString::number(total));

       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->resize(1000, 500);

       chart->legend()->hide();
       chartView->show();

       }

void MainWindow::on_pushButton_11_clicked()
{
    animaux a;
    ui->list1->setModel(a.nombre_totale());
}
