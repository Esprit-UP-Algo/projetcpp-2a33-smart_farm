#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Employe
{

    QString Nom,Prenom,Email,Etat;
    int Id,Telephone,Age;


public:
    Employe();
    Employe(QString,QString,QString,QString,int,int,int);

    QString getNom(){return Nom;}
    QString getPrenom(){return Prenom;}
    QString getEmail(){return Email;}
    QString getEtat(){return Etat;}
    int getAge(){return Age;}
    int getId(){return Id;}
    int getTelephone(){return Telephone;}

    void setNom(QString nom){Nom=nom;}
    void setPrenom(QString prenom){Prenom=prenom;}
    void setEmail(QString email){Email=email;}
    void setEtat(QString etat){Etat=etat;}
    void setAge(int age){Age=age;}
    void setId(int id){Id=id;}
    void setTelephone(int telephone){Telephone=telephone;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QMap<QString, int> getAgeStatistics();
    QSqlQueryModel *afficher(bool sortByNom);
    QSqlQueryModel * rechercher(int idRecherche);

};

#endif // EMPLOYE_H
