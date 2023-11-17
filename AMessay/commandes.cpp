#include "commandes.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include "connection.h"
#include <QObject>
Commandes::Commandes()
{
reference=0;
entreprise="";
objet="";
type="";
etat="";
date=0;
contact=0;
Email="";

}
Commandes::Commandes(int reference,QString entreprise,QString objet,QString type,QString etat,int date,int contact,QString Email)
{
   this->reference=reference;
    this->entreprise=entreprise;
    this->objet=objet;
    this->type=type;
    this->etat=etat;
    this->date=date;
    this->contact=contact;
    this->Email=Email;
}
//setters
void Commandes::setreference(int n){reference =n;}
void Commandes::setentreprise(QString n){entreprise=n;}
void Commandes::setobjet(QString n){objet=n;}
void Commandes::settype(QString n){type=n;}
void Commandes::setetat(QString n){etat=n;}
void Commandes::setdate(int n){date=n;}
void Commandes::setcontact(int n){contact=n;}
void Commandes::setemail(QString n){Email=n;}
//getters
int Commandes::get_reference(){return reference;}
QString Commandes::get_entreprise(){return entreprise;}
QString Commandes::get_objet(){return objet;}
QString Commandes::get_type(){return type;}
QString Commandes::get_etat(){return etat;}
int Commandes::get_date(){return date;}
int Commandes::get_contact(){return contact;}
QString Commandes::get_email(){return Email;}

//ajouter
bool Commandes::ajouter(){

    QSqlQuery query;
    QString res = QString::number(reference);
    QString nb= QString::number(contact);
    QString d=QString::number(date);
    query.prepare("INSERT INTO COMMANDES (REF, ENTREPRISE, OBJET, TYPE, CONTACT, EMAIL, DATES, ETAT)"
                  "VALUES(:REF, :ENTREPRISE, :OBJET, :TYPE, :CONTACT, :EMAIL, :DATES, :ETAT)");

    query.bindValue(":REF", res);
    query.bindValue(":ENTREPRISE", entreprise);
    query.bindValue(":OBJET", objet);
    query.bindValue(":TYPE", type);
    query.bindValue(":CONTACT", nb);
    query.bindValue(":EMAIL", Email);
    query.bindValue(":DATES", d);
    query.bindValue(":ETAT", etat);

    return query.exec();
}
QSqlQueryModel *Commandes::afficher()
{
     QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Commandes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REF"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ENTREPRISE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("OBJET"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TYPE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("CONTACT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("DATES"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("ETAT"));
    return model;

}
bool Commandes::supprimer(int nbe)
{
    QSqlQuery query;
    QString res=QString::number(nbe);
    query.prepare("Delete from Commandes where REF= :nbe");
    query.bindValue(0,nbe);
    return query.exec();

}
bool Commandes::modifier()
{
    QSqlQuery query;
    /*QString res = QString::number(reference);
    QString nb= QString::number(contact);
    QString d=QString::number(date);*/
      /*query.prepare("SELECT COUNT(*) FROM COMMANDES WHERE REF = :REF");
        query.bindValue(":REF", reference);
        query.exec();
        query.next();
        int count = query.value(0).toInt();
        if (count == 0)
        {
            // REF does not exist in the database, return false
            return false;
        }

        // REF exists, execute the update query*/
        QString res = QString::number(reference);

    query.prepare("UPDATE COMMANDES SET ENTREPRISE= :ENTREPRISE, OBJET= :OBJET, TYPE= :TYPE, CONTACT= :CONTACT, EMAIL= :EMAIL, DATES= :DATES, ETAT= :ETAT WHERE REF= :REF");
    query.bindValue(":REF",res);
    query.bindValue(":ENTREPRISE",entreprise);
    query.bindValue(":OBJET",objet);
    query.bindValue(":TYPE",type);
    query.bindValue("CONTACT",contact);
    query.bindValue(":EMAIL",Email);
    query.bindValue(":DATES",date);
    query.bindValue(":ETAT",etat);
    bool success=query.exec();
    return success;
}
