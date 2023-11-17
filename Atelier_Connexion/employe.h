#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>

class Employe
{

    QString Nom,Prenom,Email,Etat,Motpasse;
   int Id, Telephone, Age, Salaire, nbAnsFidelite;
  // QList<QDate> planningDates;
    //QString Disponibilite;


public:
    Employe();
    Employe(QString nom, QString prenom, QString email, QString etat,QString motpasse, int id, int telephone, int age, int salaire, int nbAnsFidelite);


    QString getNom(){return Nom;}
    QString getPrenom(){return Prenom;}
    QString getEmail(){return Email;}
    QString getEtat(){return Etat;}
    int getAge(){return Age;}
    int getId(){return Id;}
    int getTelephone(){return Telephone;}
    int getnbAnsFidelite() const { return nbAnsFidelite; }
        int getSalaire() const { return Salaire; }
        QString getMotpasse(){return Motpasse;}



    void setNom(QString nom){Nom=nom;}
    void setPrenom(QString prenom){Prenom=prenom;}
    void setEmail(QString email){Email=email;}
    void setEtat(QString etat){Etat=etat;}
    void setAge(int age){Age=age;}
    void setId(int id){Id=id;}
    void setTelephone(int telephone){Telephone=telephone;}
    void setnbAnsFidelite(int NbAnsFidelite) { nbAnsFidelite = NbAnsFidelite; }
      void setSalaire(int salaire) { Salaire = salaire; }
 void setMotpasse(QString passe){Motpasse=passe;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QMap<QString, int> getAgeStatistics();
    QSqlQueryModel *afficher(bool sortByNom);
    QSqlQueryModel * rechercher(int idRecherche);

    static void updateSalaries();
    //void verifierFidelite();
/*void addPlanningDate(const QDate &date);
const QVector<QDate>& getPlanningDates() const;
*/


    /*QString getDisponibilite() const { return Disponibilite; }
        void setDisponibilite(const QString &disponibilite) { Disponibilite = disponibilite; }
        QMap<QString, int>getEmployeeAvailabilityData();*/


};

#endif // EMPLOYE_H
