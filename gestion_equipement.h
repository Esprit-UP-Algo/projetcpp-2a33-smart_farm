#ifndef GESTION_EQUIPEMENT_H
#define GESTION_EQUIPEMENT_H
#include <QSqlQueryModel>
#include <QTableView>
#include <QString>
#include <cstring>
#include <iostream>
#include <string>

class gestion_equipement
{
public:
    gestion_equipement();
    gestion_equipement(int,QString,QString,QString,QString);

        int getid_e();

        QString getnom_e();

        QString getetat_e();

        QString getDispo_e();

        QString getQt_e();


         void setid_e(int);

         void setnom_e(QString);

        void setetat_e(QString);

        void setDispo_e(QString);

        void setQt_e(QString);

        bool ajouter();
        QSqlQueryModel* afficher();

        bool supprimer(int);

       bool modifier(int,QString,QString,QString,QString);
      QSqlQueryModel * rechercher(int nbe) ;

      QStringList liste_Sum() ;
      int sumQuantityByNoun(const QString &equipmentName) ;
        QSqlQueryModel * tri_id() ;

    private:
     int id_e;
    QString nom_e,etat_e,dispo_e,qt_e;

    };

#endif // GESTION_EQUIPEMENT_H
