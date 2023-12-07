#ifndef ANIMAUX_H
#define ANIMAUX_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class animaux
{
private:
    int id_a;
    QString type_a;
    int age_a;
    QString status_a;
    int nombre_a;
public:
    animaux();
    animaux(int,QString,int,QString,int);

    int getid(){return id_a;}
    int getage(){return age_a;}
    int getnombre(){return nombre_a;}
    QString gettype(){return type_a;}
    QString getstatus(){return status_a;}

    void setid(int id_a){this->id_a=id_a;}
    void setage(int age_a){this->age_a=age_a;}
    void setnombre(int nombre_a){this->nombre_a=nombre_a;}
    void settype(QString type_a){this->type_a=type_a;}
    void setstatus(QString status_a){this->status_a=status_a;}

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* recherche(QString,QString);
    bool supprimer(int);
    bool modifier(int,QString,int,QString,int);
    QSqlQueryModel* nombre_totale();
    QSqlQueryModel* aff_nombre();
    QSqlQueryModel* aff_age();
};

#endif // ANIMAUX_H
