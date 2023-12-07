#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>
#include <arduino.h>
class Employe
{

    QString Id_EM ,Nom_EM,Prenom_EM,Email_EM,Etat_EM,Motpasse_EM;
   int  Telephone_EM, Age_EM, Salaire_EM, NbAnsFidelite;
  // QList<QDate> planningDates;
    //QString Disponibilite;


public:
    Employe();
    Employe(QString Id_EM,QString Nom_EM, QString preNom_EM, QString Email_EM, QString Etat_EM,QString Motpasse_EM, int Telephone_EM, int Age_EM, int Salaire_EM, int nbAnsFId_EMelite);


    QString getNom_EM(){return Nom_EM;}
    QString getPreNom_EM(){return Prenom_EM;}
    QString getEmail_EM(){return Email_EM;}
    QString getEtat_EM(){return Etat_EM;}
    int getAge_EM(){return Age_EM;}
    QString getId_EM(){return Id_EM;}
    int getTelephone_EM(){return Telephone_EM;}
    int getnbAnsFId_EMelite() const { return NbAnsFidelite; }
        int getSalaire_EM() const { return Salaire_EM; }
        QString getMotpasse_EM(){return Motpasse_EM;}



    void setNom_EM(QString Nom_EM){Nom_EM=Nom_EM;}
    void setPrenom_EM(QString preNom_EM){Prenom_EM=preNom_EM;}
    void setEmail_EM(QString Email_EM){Email_EM=Email_EM;}
    void setEtat_EM(QString Etat_EM){Etat_EM=Etat_EM;}
    void setAge_EM(int Age_EM){Age_EM=Age_EM;}
    void setId_EM(QString Id_EM){Id_EM=Id_EM;}
    void setTelephone_EM(int Telephone_EM){Telephone_EM=Telephone_EM;}
    void setNbAnsFidelite(int NbAnsFId_EMelite) { NbAnsFidelite = NbAnsFId_EMelite; }
      void setSalaire_EM(int Salaire_EM) { Salaire_EM = Salaire_EM; }
 void setMotpasse_EM(QString passe){Motpasse_EM=passe;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier();
   QMap<QString, int>getAgeStatistics();
    QSqlQueryModel *afficher(bool sortByNom_EM);
    QSqlQueryModel * rechercher(QString Id_EMRecherche);

    static void updateSalaries();
     bool checkEmployee(const QString& employeeId_EM);
bool employeeExists(const QString &employeeId_EM);
void verifyEmployeeId_EMInDatabase(const QString &employeeId_EM);
};

#endif // EMPLOYE_H
