#include "aliments.h"

#include "aliments.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QMessageBox>
#include <cstdlib>
#include <QObject>
#include <iostream>
#include <QString>
#include <QUrlQuery>
#include <QDebug>
#include <QDate>
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
#include <ui_mainwindow.h>
#include <QPushButton>
Aliments::Aliments()
{
    ref= 0;
    refc=0;
    temperature=0;
    dateimp =QDate();
    datexp=QDate();
    quantite= 0;
    type= "";
    image ="";
}

Aliments::Aliments(int ref,QString type,int temperature, int quantite, int refc,QDate dateimp,QDate datexp,QString image)
{
    this->ref= ref;
    this->refc= refc;
    this->temperature= temperature;
    this->dateimp = dateimp;
    this->quantite= quantite;
    this->datexp= datexp;
    this->type = type;
    this->image = image;

}

// GETTERS
int Aliments::getref()
{
    return ref;
}
QDate Aliments::getdateimp()
{
    return dateimp;
}
QDate Aliments::getdatexp()
{
    return datexp;
}
QString Aliments::gettype()
{
    return type;
}
int Aliments::getquantite()
{
    return quantite;
}

// SETTERS
void Aliments::setref(int newref)
{
    ref= newref;
}
void Aliments::setdateimp(QDate newdateimp)
 {   dateimp=newdateimp;
}
void Aliments::setquantite(int newquantite)
{
    quantite = newquantite;
}
void Aliments::setdateexp(QDate newdatexp)
{
    datexp=newdatexp;
}
void Aliments::settype(QString newtype)
{
   type=newtype;
}

bool Aliments::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO ALIMENTS"
                  " (REF_AL,TYPE_AL,QUANTITE_AL,REFCO,DATEIMP_AL,DATEEXP_AL,temperature,image)"
                  "VALUES (:ref,:type,:quantite,:refc,:dateimp,:datexp,:temperature,:image)");

    QString tmpref = QString::number(ref);
    QString tmptemperature = QString::number(temperature);
    QString tmprefco = QString::number(refc);
    QString tmpquantite = QString::number(quantite);
    QDate tmpdateexp = QDate(datexp);
    QDate tmpdateimp = QDate(dateimp);
    QString tmptype = QString(type);
    QString imagea = QString(image);


    query.bindValue(":ref", tmpref);
    query.bindValue(":temperature", tmptemperature);
    query.bindValue(":dateimp", tmpdateimp);
    query.bindValue(":datexp",tmpdateexp);
    query.bindValue(":type", tmptype);
    query.bindValue(":quantite", tmpquantite);
    query.bindValue(":refc", tmprefco);
    query.bindValue(":image", imagea);


    return (query.exec());
}

QSqlQueryModel* Aliments::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from aliments");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    return model;
}

QSqlQueryModel *afficherAliments()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT REF_AL,TYPE_AL,image,QUANTITE_AL,REFCO,DATEIMP_AL,DATEEXP_AL,TEMPERATURE FROM aliments ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF_AL"));


    return model;
}
bool Aliments::supprimer(int ref)
{
    QSqlQuery query;
    //QString tmpref = QString::number(ref);

    query.prepare("Delete from aliments where REF_AL=:ref");
    query.bindValue(0,ref);
    return query.exec();

}

bool Aliments::modifier(int ref)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM ALIMENTS WHERE REF_AL =:refrech");
     //QString ref_string=QString::number(ref);
     //QString quantite_string=QString::number(quantite);
      //QString refc_string=QString::number(refc);
          query.prepare("UPDATE ALIMENTS SET REF_AL=:ref,TYPE_AL=:type,QUANTITE_AL=:quantite,REFCO=:refc,DATEIMP_AL=:dateimp,DATEEXP_AL=:datexp where REF_AL=:ref");
          //uery.bindValue(":ref",ref_string);
          //query.bindValue(":quantite",quantite_string);
          //query.bindValue(":refc",refc_string);
          //query.bindValue(":dateimp",dateimp);
          //query.bindValue(":datexp",datexp);
          //query.bindValue(":type",type);

    QString tmpref = QString::number(ref);
    QString tmprefco = QString::number(refc);
    QString tmpquantite = QString::number(quantite);
    QDate tmpdateexp = QDate(datexp);
    QDate tmpdateimp = QDate(dateimp);
    QString tmptype = QString(type);


    query.bindValue(":ref", tmpref);
    query.bindValue(":dateimp", tmpdateimp);
    query.bindValue(":datexp",tmpdateexp);
    query.bindValue(":type", tmptype);
    query.bindValue(":quantite", tmpquantite);
    query.bindValue(":refc", tmprefco);



          return (query.exec());



}
QSqlQueryModel* Aliments:: trier_type()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from ALIMENTS order by TYPE_AL ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" REF_AL"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr(" TYPE_AL")); //donner nom au colonne
      model->setHeaderData(6, Qt::Horizontal, QObject::tr(" QUANTITE_AL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REFCO"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEIMP_AL"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATEXP_AL"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("IMAGE"));



    return model;
}

QSqlQueryModel * Aliments::rechercher(int refrech) {
    QSqlQueryModel *model = new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM ALIMENTS WHERE REF_AL =:refrech");
      query.bindValue(":refrech", refrech); // Ajout de la liaison

      if (query.exec()) {
          model->setQuery(query);
      }

      return model;
}
QSqlQueryModel *Aliments::rechercher1(int refrech)
{

    QSqlQueryModel *model = new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM ALIMENTS WHERE REF_AL =:refrech");
      query.bindValue(":refrech", refrech); // Ajout de la liaison

      if (query.exec()) {
          model->setQuery(query);
      }

      return model;

}
QMap<QString, int> Aliments::getquantiteStatistics()
{
    QMap<QString, int> statistics;

        QSqlQuery query;
        query.prepare("SELECT COUNT(*) AS count FROM ALIMENTS WHERE QUANTITE_AL < 30");
        if (query.exec() && query.next()) {
            statistics["Moins de 30 KG"] = query.value("count").toInt();
        }

        query.prepare("SELECT COUNT(*) AS count FROM ALIMENTS WHERE QUANTITE_AL >= 30 AND QUANTITE_AL <= 40");
        if (query.exec() && query.next()) {
            statistics["30-40 kg"] = query.value("count").toInt();
        }
        query.prepare("SELECT COUNT(*) AS count FROM EMPLOYES WHERE QUANTITE_AL > 40");
                if (query.exec() && query.next()) {
                    statistics["Plus de 40 kg"] = query.value("count").toInt();
                }

                return statistics;
        }
QMap<QString, int> Aliments::getTypeStatistics()
{
    QMap<QString, int> statistics;

    QSqlQuery query;
    query.prepare("SELECT TYPE_AL, COUNT(*) AS count FROM ALIMENTS GROUP BY TYPE_AL");
    if (query.exec()) {
        while (query.next()) {
            QString type = query.value("TYPE_AL").toString();
            int count = query.value("count").toInt();
            statistics[type] = count;
        }
    }

    return statistics;
}







