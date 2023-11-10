#include "employe.h"
#include "QSqlQuery"
#include "QtDebug"
#include"QObject"
#include "connection.h"
#include <QSqlError>


Employe::Employe()
{
Id=0;
//Nom="";
//Prenom="";
//Age=0;
//Telephone=0;
//Email="";
//Etat="";
}

Employe::Employe(QString nom, QString prenom, QString email, QString etat,  int id,int telephone,int age)
{
    Id = id;
    Nom = nom;
    Prenom = prenom;
    Email = email;
    Age = age;
    Telephone = telephone;
    Etat = etat;
}

bool Employe::ajouter() {


    QSqlQuery query;
    QString id_string = QString::number(Id);
    QString tel_string = QString::number(Telephone);
    QString age_string = QString::number(Age);
    query.prepare("insert into EMPLOYES(ID_EM, NOM_EM, PRENOM_EM, EMAIL_EM, AGE_EM, TEL_EM, DISPO_EM) "
                  "VALUES (:ID_EM, :NOM_EM, :PRENOM_EM, :EMAIL_EM, :AGE_EM, :TEL_EM, :DISPO_EM)");
    query.bindValue(":ID_EM", id_string);
    query.bindValue(":NOM_EM", Nom);
    query.bindValue(":PRENOM_EM", Prenom);
    query.bindValue(":EMAIL_EM", Email);
    query.bindValue(":AGE_EM", age_string);
    query.bindValue(":TEL_EM", tel_string);
    query.bindValue(":DISPO_EM", Etat);

    return query.exec();
}

bool Employe::supprimer(int Id) {
    QSqlQuery query;
    QString id_string = QString::number(Id);
    query.prepare("DELETE FROM EMPLOYES WHERE ID_EM = :ID_EM");
    query.bindValue(":ID_EM", id_string);
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
return model;
}

bool Employe::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(Id);
    QString tel_string = QString::number(Telephone);
    QString age_string = QString::number(Age);

    query.prepare("UPDATE EMPLOYES SET ID_EM=:Id, NOM_EM=:Nom, PRENOM_EM=:Prenom, EMAIL_EM=:Email, AGE_EM=:Age,"
                  " TEL_EM=:Telephone, DISPO_EM=:Etat WHERE ID_EM=:Id");

    query.bindValue(":Id", id_string);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Email", Email);
    query.bindValue(":Age", age_string);
    query.bindValue(":Telephone", tel_string);
    query.bindValue(":Etat", Etat);

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

    return model;
}
QSqlQueryModel * Employe::rechercher(int idRecherche) {
    QSqlQueryModel *model = new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM EMPLOYES WHERE ID_EM = :idRecherche");
      query.bindValue(":idRecherche", idRecherche); // Ajout de la liaison

      if (query.exec()) {
          model->setQuery(query);
      }

      return model;
}
