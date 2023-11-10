#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "QString"
#include "QtDebug"
#include <QMessageBox>
#include "connection.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->aff->setModel(EM.afficher());
      connect(ui->metiers, &QTabWidget::currentChanged, this, &MainWindow::on_crud_currentChanged);}



MainWindow::~MainWindow()
{
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
       bool idIsValid = false;
           int idValue = ui->ID1->text().toInt(&idIsValid);

           if (!idIsValid || ui->ID1->text().length() < 6) {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un ID valide (au moins 6 chiffres)."), QMessageBox::Cancel);
               return;
           }
       int pos = 0;
       QValidator::State emailValidationState = emailValidator.validate(Email, pos);



       if (emailValidationState != QValidator::Acceptable) {
           QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une adresse e-mail valide."), QMessageBox::Cancel);
           return;
       }


    if (Age <= 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un âge valide."), QMessageBox::Cancel);
        return;
    }

    if (QString::number(Telephone).length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un numéro de téléphone valide (8 chiffres)."), QMessageBox::Cancel);
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


    Employe EM(Nom, Prenom, Email, Etat, Id, Telephone, Age);
    bool test = EM.ajouter();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Ajout effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de l'ajout.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_SUPPRIMER1_clicked()
{
    Employe EM;
    int Id = ui->ID1->text().toInt();



    bool idIsValid = false;
    int idValue = ui->ID1->text().toInt(&idIsValid);

    if (!idIsValid || ui->ID1->text().length() < 6) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un ID valide (au moins 6 chiffres)."), QMessageBox::Cancel);
        return;
    }

    //
    QSqlQueryModel *existingEmployeeModel = EM.rechercher(Id);
    if (existingEmployeeModel->rowCount() == 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'employé avec cet ID n'existe pas."), QMessageBox::Cancel);
        delete existingEmployeeModel;
        return;
    }
    delete existingEmployeeModel;

    // Supprimer l'employé
    bool test = EM.supprimer(Id);

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Suppression effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la suppression.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
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

    // Input validation
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

    bool idIsValid = false;
    int idValue = ui->ID1->text().toInt(&idIsValid);

    if (!idIsValid || ui->ID1->text().length() < 6) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un ID valide (au moins 6 chiffres)."), QMessageBox::Cancel);
        return;
    }

    int pos = 0;
    QValidator::State emailValidationState = emailValidator.validate(Email, pos);

    if (emailValidationState != QValidator::Acceptable) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer une adresse e-mail valide."), QMessageBox::Cancel);
        return;
    }

    if (Age <= 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un âge valide."), QMessageBox::Cancel);
        return;
    }

    if (QString::number(Telephone).length() != 8) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un numéro de téléphone valide (8 chiffres)."), QMessageBox::Cancel);
        return;
    }

    if (Etat.isEmpty() || (Etat != "présent" && Etat != "absent")) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un état valide (présent ou absent)."), QMessageBox::Cancel);
        return;
    }

    // Validation de l'existence de l'employé
    QSqlQueryModel *existingEmployeeModel = EM.rechercher(Id);
    if (existingEmployeeModel->rowCount() == 0) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("L'employé avec cet ID n'existe pas."), QMessageBox::Cancel);
        delete existingEmployeeModel;
        return;
    }
    delete existingEmployeeModel;

    // Si toutes les validations passent, procédez à la modification
    Employe updatedEmployee(Nom, Prenom, Email, Etat, Id, Telephone, Age);
    bool test = updatedEmployee.modifier();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("Succès"),
                                 QObject::tr("Mise à jour effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->aff->setModel(EM.afficher());  // Rafraîchir l'affichage après la modification
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Erreur lors de la mise à jour.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_crud_currentChanged(int index)
{
    if (index == 1) {
        // L'onglet "Statistique" est sélectionné
        QMap<QString, int> statistics = EM.getAgeStatistics();
        int totalEmployees = 0;

        // Calculer le nombre total d'employés
        for (const QString &ageGroup : statistics.keys()) {
            totalEmployees += statistics[ageGroup];
        }

        QString message = "\n";

        for (const QString &ageGroup : statistics.keys()) {
            int count = statistics[ageGroup];
            double percentage = (static_cast<double>(count) / totalEmployees) * 100.0;
            message += ageGroup + ": " + QString::number(count) + " employés (" + QString::number(percentage, 'f', 2) + "%)\n";
        }

        ui->STAT->setText(message); // Afficher les statistiques dans le QLabel
    }
    }
void MainWindow::on_TRIER_clicked()
{
   ui->aff->setModel(EM.afficher(true));
}



void MainWindow::on_chercher_clicked()
{
    int idRecherche = ui->CHERCHER->text().toInt();

       // Utilisez la méthode Employe::rechercher pour obtenir le modèle de données
       QSqlQueryModel *resultModel = EM.rechercher(idRecherche);

       // Assurez-vous que le modèle de données n'est pas vide et qu'il contient des informations
       if (resultModel && resultModel->rowCount() > 0) {
           // Assurez-vous que votre QTableView "aff3" est correctement configuré dans votre interface graphique
           ui->aff3->setModel(resultModel);
       } else {
           // Si le modèle est vide, affichez un message d'erreur
           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet ID.", QMessageBox::Cancel);
       }
}


