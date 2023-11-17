#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "QString"
#include "QtDebug"
#include <QMessageBox>
#include "connection.h"
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
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts>
#include <QPieSlice>
#include <QDate>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->aff->setModel(EM.afficher());

    ui->ID1->setValidator(new QIntValidator(0,999999,this));
    ui->AGE->setValidator(new QIntValidator(0,999999,this));
     ui->TEL1->setValidator(new QIntValidator(0,999999,this));
ageStatisticsChartView = nullptr;
  ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    clearAgeStatisticsChart();
    delete ui;
}

void MainWindow::on_AJOUTER1_clicked()
{

    int Id = ui->ID1->text().toInt();
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
    int Id = ui->ID1->text().toInt();





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

void MainWindow::on_miseajour_clicked()
{
    int Id = ui->ID1->text().toInt();
    QString Nom = ui->NOM1->text();
    QString Prenom = ui->PRENOM1->text();
    QString Email = ui->EMAIL1->text();
    int Age = ui->AGE->text().toInt();
    int Telephone = ui->TEL1->text().toInt();
    QString Etat = ui->ETAT1->text();
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
    if (existingEmployeeModel->rowCount() == 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'employé avec cet ID n'existe pas."), QMessageBox::Cancel);
        delete existingEmployeeModel;
        return;
    }
    delete existingEmployeeModel;


    Employe updatedEmployee(Nom, Prenom, Email, Etat, Motpasse, Id, Telephone, Age,Salaire,nbAnsFidelite);
    bool test = updatedEmployee.modifier();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Mise à jour effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->aff->setModel(EM.afficher());  // Rafraîchir l'affichage après la modification
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la mise à jour.\nClick Cancel to exit."), QMessageBox::Cancel);
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

void MainWindow::on_crud_currentChanged(int index)
{
    updateAgeStatisticsChart();
}
void MainWindow::on_TRIER_clicked()
{
   ui->aff->setModel(EM.afficher(true));
}



void MainWindow::on_chercher_clicked()
{
    int idRecherche = ui->CHERCHER->text().toInt();


       QSqlQueryModel *resultModel = EM.rechercher(idRecherche);


       if (resultModel && resultModel->rowCount() > 0) {

           ui->aff3->setModel(resultModel);
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
    Employe::updateSalaries();

        // Refresh the displayed employee list
        ui->aff->setModel(EM.afficher());  // Retirez cette ligne

        QMessageBox::information(nullptr, QObject::tr("Vérification effectuée"),
                                 QObject::tr("La vérification de fidélité pour tous les employés a été effectuée avec succès."),
                                 QMessageBox::Cancel);
}
