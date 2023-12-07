#include "employe.h"
#include "QSqlQuery"
#include "QtDebug"
#include"QObject"
#include "connection.h"
#include <QSqlError>
#include <QDate>
#include "mainwindow.h"



Employe::Employe()
{
Id_EM="";
//Nom="";
//Prenom="";
//Age=0;
//Telephone=0;
//Email="";
//Etat="";

}

Employe::Employe(QString id,QString nom, QString prenom, QString email, QString etat,QString motpasse, int telephone, int age, int salaire_EM, int nbAnsFidelite)
{
    Id_EM = id;
        Nom_EM = nom;
        Prenom_EM = prenom;
        Email_EM = email;
        Age_EM = age;
        Telephone_EM = telephone;
        Etat_EM = etat;
        Motpasse_EM = motpasse;
        NbAnsFidelite = nbAnsFidelite;
        Salaire_EM = salaire_EM;

}

bool Employe::ajouter() {


    QSqlQuery query;

    QString tel_string = QString::number(Telephone_EM);
    QString age_string = QString::number(Age_EM);
    QString sal_string = QString::number(Salaire_EM);
    QString nb_string = QString::number(NbAnsFidelite);
    query.prepare("INSERT INTO EMPLOYES(NOM_EM, PRENOM_EM,  EMAIL_EM  ,DISPO_EM, AGE_EM, TEL_EM,PASSE ,ID_EM,NB_ANS, SALAIRE_EM) "
                  "VALUES (:ID_EM, :NOM_EM, :PRENOM_EM, :EMAIL_EM, :AGE_EM, :TEL_EM, :DISPO_EM, :PASSE, :NB_ANS,:SALAIRE_EM)");
    query.bindValue(":ID_EM",Id_EM);
    query.bindValue(":NOM_EM", Nom_EM);
    query.bindValue(":PRENOM_EM", Prenom_EM);
    query.bindValue(":EMAIL_EM", Email_EM);
    query.bindValue(":AGE_EM", age_string);
    query.bindValue(":TEL_EM", tel_string);
    query.bindValue(":DISPO_EM", Etat_EM);
    query.bindValue(":PASSE", Motpasse_EM);
    query.bindValue(":NB_ANS", nb_string);
    query.bindValue(":SALAIRE_EM", sal_string );

    return query.exec();
}

bool Employe::supprimer(QString Id) {
    QSqlQuery query;

    query.prepare("DELETE FROM EMPLOYES WHERE ID_EM = :ID_EM");
    query.bindValue(":ID_EM", Id);
    return query.exec();
}


QSqlQueryModel * Employe::afficher(){
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("SELECT * FROM EMPLOYES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EM"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL_EM"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("AGE_EM"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("TEL_EM"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("DISPO_EM"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("PASSE"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("NB_ANS"));
model->setHeaderData(9,Qt::Horizontal,QObject::tr("SALAIRE_EM"));

return model;
}


bool Employe::modifier() {
    QSqlQuery query;


     QString tel_string = QString::number(Telephone_EM);
     QString age_string = QString::number(Age_EM);
     QString nb_string = QString::number(NbAnsFidelite);
     QString sal_string = QString::number(Salaire_EM);

     query.prepare("UPDATE EMPLOYES SET ID_EM=:Id, NOM_EM=:Nom, PRENOM_EM=:Prenom, EMAIL_EM=:Email, AGE_EM=:Age,"
                   " TEL_EM=:Telephone_EM, DISPO_EM=:Etat_EM, PASSE=:Motpasse_EM , NB_ANS=:nbAnsFidelite,SALAIRE_EM=:Salaire_EM WHERE ID_EM=:Id");

    query.bindValue(":Id_EM",Id_EM);
    query.bindValue(":Nom_EM", Nom_EM);
    query.bindValue(":Prenom_EM", Prenom_EM);
    query.bindValue(":Email_EM", Email_EM);
    query.bindValue(":Age_EM", age_string);
    query.bindValue(":Telephone_Em", tel_string);
    query.bindValue(":Etat_EM", Etat_EM);
    query.bindValue(":Motpasse_EM", Motpasse_EM);
    query.bindValue(":nbAnsFidelite",  nb_string);
    query.bindValue(":Salaire_EM",sal_string );

    return query.exec();

}

QMap<QString, int> Employe::getAgeStatistics() {
    QMap<QString, int> statistics;

        QSqlQuery query;
        query.prepare("SELECT COUNT(*) AS count FROM EMPLOYES WHERE AGE_EM < 30");
        if (query.exec() && query.next()) {
            statistics["Moins de 30 ans"] = query.value("count").toInt();
        }

        query.prepare("SELECT COUNT(*) AS count FROM EMPLOYES WHERE AGE_EM >= 30 AND AGE_EM <= 40");
        if (query.exec() && query.next()) {
            statistics["30-40 ans"] = query.value("count").toInt();
        }

        query.prepare("SELECT COUNT(*) AS count FROM EMPLOYES WHERE AGE_EM > 40");
        if (query.exec() && query.next()) {
            statistics["Plus de 40 ans"] = query.value("count").toInt();
        }

        return statistics;
}


QSqlQueryModel * Employe::afficher(bool sortByNom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    if (sortByNom) {
        query.prepare("SELECT * FROM EMPLOYES ORDER BY NOM_EM ASC");
    } else {
        query.prepare("SELECT * FROM EMPLOYES");
    }

    if (query.exec()) {
        model->setQuery(query);
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_EM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_EM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL_EM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE_EM"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEL_EM"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DISPO_EM"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("PASSE"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("SALAIRE_EM"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("NB_ANS"));
    return model;
}
QSqlQueryModel * Employe::rechercher(QString idRecherche) {
    QSqlQueryModel *model = new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM EMPLOYES WHERE ID_EM = :idRecherche");
      query.bindValue(":idRecherche", idRecherche); // Ajout de la liaison

      if (query.exec()) {
          model->setQuery(query);
      }

      return model;
}
void Employe::updateSalaries() {
    QSqlQuery query("SELECT ID_EM, SALAIRE_EM, NB_ANS FROM EMPLOYES");

       while (query.next()) {
           QString id = query.value(0).toString(); // Utilisez toString() pour obtenir une QString
           int nbAnsTravail = query.value(2).toInt();
           int salaire_EM = query.value(1).toInt();

           // Ajoutez vos conditions pour ajuster les salaires en fonction de nbAnsFidelite
           if (salaire_EM == 1500) {
               if (nbAnsTravail > 20)
                   salaire_EM = 2700;
               else if (nbAnsTravail >= 10 && nbAnsTravail <= 20)
                   salaire_EM = 2200;
               else if (nbAnsTravail >= 5 && nbAnsTravail < 10)
                   salaire_EM = 1700;
           }
           else if (salaire_EM == 1900) {
               if (nbAnsTravail > 20)
                   salaire_EM = 2900;
               else if (nbAnsTravail >= 10 && nbAnsTravail <= 20)
                   salaire_EM= 2400;
               else if (nbAnsTravail >= 5 && nbAnsTravail < 10)
                   salaire_EM = 2100;
           }
           // Ajoutez d'autres conditions au besoin pour d'autres valeurs de salaire

           // Mettez à jour la base de données avec les nouveaux salaires
           QSqlQuery updateQuery;
           updateQuery.prepare("UPDATE EMPLOYES SET SALAIRE_EM = :SALAIRE_EM WHERE ID_EM = :ID_EM");
           updateQuery.bindValue(":SALAIRE_EM", salaire_EM);
           updateQuery.bindValue(":ID_EM", id);

           if (updateQuery.exec()) {
               qDebug() << "Mise à jour du salaire de l'employé avec l'ID" << id << "réussie";
           } else {
               qDebug() << "Erreur lors de la mise à jour du salaire de l'employé avec l'ID" << id;
           }
       }
}
