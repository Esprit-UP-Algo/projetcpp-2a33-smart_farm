
#include "gestion_equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QSqlError>

// constructeur par defaut
gestion_equipement::gestion_equipement()
{
       id_e=0;
       nom_e="";
       etat_e="";
       dispo_e="";
       qt_e="";

}
//constructeur paramétré
gestion_equipement::gestion_equipement(int id_e,QString nom_e,QString etat_e,QString dispo_e,QString qt_e)
{this->id_e=id_e;this->nom_e=nom_e;this->etat_e=etat_e;this->dispo_e=dispo_e;this->qt_e=qt_e;}
int gestion_equipement::getid_e(){return id_e;}
QString gestion_equipement::getnom_e(){return nom_e;}
QString gestion_equipement::getetat_e(){return etat_e;}
QString gestion_equipement::getDispo_e(){return dispo_e;}
QString gestion_equipement::getQt_e(){return qt_e;}



void gestion_equipement::setid_e(int id_e){this->id_e=id_e;}
void gestion_equipement::setnom_e(QString nom_e){this->nom_e=nom_e;}
void gestion_equipement::setetat_e(QString etat_e){this->etat_e=etat_e;}
void gestion_equipement::setDispo_e(QString dispo_e){this->dispo_e=dispo_e;}
void gestion_equipement::setQt_e(QString qt_e){this->qt_e=qt_e;}

bool gestion_equipement::ajouter()
{
    QSqlQuery query;
    QString id_e_string=QString::number(id_e);


         query.prepare("INSERT INTO EQUIPEMENT (ID_E, NOM_E, ETAT_E,DISPO_E,QUANTITE_E) "
                       "VALUES (:ID_E,:NOM_E,:ETAT_E,:DISPO_E ,:QUANTITE_E)");
         query.bindValue(":ID_E",id_e_string);
         query.bindValue(":NOM_E",nom_e);
         query.bindValue(":ETAT_E",etat_e);
         query.bindValue(":DISPO_E",dispo_e);
         query.bindValue(":QUANTITE_E",qt_e);

         return query.exec();

}


QSqlQueryModel* gestion_equipement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT* FROM EQUIPEMENT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_E"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT_E"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPO_E"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("QUANTITE_E"));

    return model;

}
bool gestion_equipement::supprimer(int id_e){
    QSqlQuery query;
    QString res = QString::number(id_e);
    query.prepare("DELETE FROM EQUIPEMENT WHERE ID_E=:ID_E");
    query.bindValue(":ID_E", res);
    if (!query.exec()) {
        return false;    // Failed to execute the query
    }
    if (query.numRowsAffected() == 0) {
        return false;  // No rows were affected
    }
    return true;
}
bool gestion_equipement::modifier(int id_e,QString nom_e,QString etat_e,QString dispo_e,QString qt_e){

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EQUIPEMENT WHERE ID_E = :ID_E");
      query.bindValue(":ID_E", id_e);
      query.exec();
      query.next();
      int count = query.value(0).toInt();
      if (count == 0) {
          // ID_E does not exist in the database, return false
          return false;
      }

      // ID_E exists, execute the update query
      QString id_e_string = QString::number(id_e);
      query.prepare("UPDATE EQUIPEMENT SET NOM_E = COALESCE(:NOM_E, NOM_E), ETAT_E = COALESCE(:ETAT_E, ETAT_E), DISPO_E = COALESCE(:DISPO_E, DISPO_E), QUANTITE_E = COALESCE(:QUANTITE_E, QUANTITE_E) WHERE ID_E = :ID_E");
      query.bindValue(":ID_E", id_e_string);
      query.bindValue(":NOM_E", nom_e.isEmpty() ? QVariant(QVariant::String) : nom_e);
      query.bindValue(":ETAT_E", etat_e.isEmpty() ? QVariant(QVariant::String) : etat_e);
      query.bindValue(":DISPO_E", dispo_e.isEmpty() ? QVariant(QVariant::String) : dispo_e);
      query.bindValue(":QUANTITE_E", qt_e.isEmpty() ? QVariant(QVariant::String) : qt_e);


      return query.exec();
  }
QSqlQueryModel * gestion_equipement::rechercher(int nbe) {
    QSqlQueryModel *model = new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM EQUIPEMENT WHERE ID_E = :ID_E");
      query.bindValue(":ID_E", nbe); // Ajout de la liaison

      if (query.exec()) {
          model->setQuery(query);
      }

      return model;
}

QStringList gestion_equipement::liste_Sum()
{
    QSqlQuery query;
    query.prepare("SELECT DISTINCT(NOM_E) FROM EQUIPEMENT");
    query.exec();

    QStringList list;
    while (query.next())
    {
        list.append(query.value(0).toString());
    }

    return list;
}
int gestion_equipement::sumQuantityByNoun(const QString &equipmentName)
{
    QSqlQuery query;
    query.prepare("SELECT SUM(QUANTITE_E) FROM EQUIPEMENT WHERE NOM_E = :equipmentName");
    query.bindValue(":equipmentName", equipmentName);
    query.exec();

    if (query.next())
    {
        return query.value(0).toInt();
    }

    return 0; // Retourne 0 si aucun résultat ou s'il y a une erreur
}
QSqlQueryModel *gestion_equipement::tri_id()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPEMENT ORDER BY ID_E ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_E"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_E"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT_E"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DISPO_E"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("QUANTITE_E"));
    return model;
}
