#ifndef COMMANDES_H
#define COMMANDES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>
class Commandes
{
private:
    QString entreprise,objet,type,etat,Email;
    int reference,contact,date;
public:
    Commandes();
    Commandes(int,QString,QString,QString,QString,int,int,QString);
    //setters
    void setreference(int n);
    void setentreprise(QString n);
    void setobjet(QString n);
    void settype(QString n);
    void setetat(QString n);
    void setdate(int n);
    void setcontact(int n);
    void setemail(QString n);
    //getters
    int get_reference();
    QString get_entreprise();
    QString get_objet();
    QString get_type();
    QString get_etat();
    int get_date();
    int get_contact();
    QString get_email();
    //fonction x  commandes
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int );
    bool modifier();

};

#endif // COMMANDES_H
