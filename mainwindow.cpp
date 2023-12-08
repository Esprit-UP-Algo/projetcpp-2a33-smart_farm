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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
 ////////////////////////////////////////////////////////////

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






