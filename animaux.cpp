#include "animaux.h"
#include "QSqlQuery"
#include "QtDebug"
#include "QObject"
animaux::animaux()
{
    id_a=0;
    type_a="";
    age_a=0;
    status_a="";
    nombre_a=0;
}
animaux::animaux(int id_a,QString type_a,int age_a,QString status_a,int nombre_a)
{
    this->id_a=id_a;
    this->age_a=age_a;
    this->type_a=type_a;
    this->status_a=status_a;
    this->nombre_a=nombre_a;

}
bool animaux::ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id_a);
    QString age_string=QString::number(age_a);
    QString nombre_string=QString::number(nombre_a);
     query.prepare("INSERT INTO ANIMAUX(id_a,type_a,age_a,status_a,nombre_a) VALUES(:id_a,:type_a,:age_a,:status_a,:nombre_a)");
     query.bindValue(":id_a",id_string);
     query.bindValue(":type_a",type_a);
     query.bindValue(":age_a",age_string);
     query.bindValue(":status_a",status_a);
     query.bindValue(":nombre_a",nombre_string);

    return query.exec();
}
QSqlQueryModel* animaux::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM ANIMAUX");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_A"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_A"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("AGE_A"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("STATUS_A"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOMBRE_A"));

    return model;
}

bool animaux::supprimer(int id_a)
{
    QSqlQuery query;
    QString id_string=QString::number(id_a);

    query.prepare("DELETE FROM ANIMAUX WHERE id_a= :id_a");
    query.bindValue(":id_a",id_string);
    return query.exec();
}
bool animaux::modifier(int id_a,QString type_a,int age_a,QString status_a,int nombre_a)
{
        QSqlQuery query;

        query.prepare("UPDATE ANIMAUX SET id_a= :id_a,type_a= :type_a,age_a= :age_a,status_a= :status_a,nombre_a= :nombre_a WHERE id_a= :id_a");
        QString id_string=QString::number(id_a);
        QString age_string=QString::number(age_a);
        QString nombre_string=QString::number(nombre_a);
        query.bindValue(":id_a",id_string);
        query.bindValue(":type_a",type_a);
        query.bindValue(":age_a",age_string);
        query.bindValue(":status_a",status_a);
        query.bindValue(":nombre_a",nombre_string);

        return query.exec();
}
QSqlQueryModel* animaux::aff_nombre()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM ANIMAUX ORDER BY nombre_a asc ");

    return model;
}
QSqlQueryModel* animaux::aff_age()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM ANIMAUX ORDER BY age_a asc ");

    return model;
}
QSqlQueryModel* animaux::recherche(QString mouton,QString vache)
{
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM ANIMAUX WHERE type_a LIKE '%" + mouton + "%'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_A"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_A"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("AGE_A"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("STATUS_A"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOMBRE_A"));
        model->setQuery("SELECT * FROM ANIMAUX WHERE type_a LIKE '%" + vache + "%'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_A"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYPE_A"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("AGE_A"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("STATUS_A"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("NOMBRE_A"));
        return model;
    }
}
QSqlQueryModel* animaux::nombre_totale(){

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT SUM(nombre_a) FROM ANIMAUX ");
     return model;
}
