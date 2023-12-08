#ifndef COMMANDES_H
#define COMMANDES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>
#include <QDate>
class Commandes
{
private:
    QString entreprise_gc,objet_gc,etat_gc,Email_gc;
    int reference_gc,contact_gc,type_gc;
    QDate date_gc;
public:
    Commandes();
    Commandes(int,QString,QString,int,QString,QDate,int,QString);
    //setters
    void setreference_gc(int n);
    void setentreprise_gc(QString n);
    void setobjet_gc(QString n);
    void settype_gc(int n);
    void setetat_gc(QString n);
    void setdate_gc(QDate n);
    void setcontact_gc(int n);
    void setEmail_gc(QString n);
    //getters
    int get_reference_gc();
    QString get_entreprise_gc();
    QString get_objet_gc();
    int get_type_gc();
    QString get_etat_gc();
    QDate get_date_gc();
    int get_contact_gc();
    QString get_Email_gc();
    //fonction x  commandes
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int );
    bool modifier();
    QSqlQueryModel * afficher(bool sortBydate ,bool sortBytype_gc,bool sortByetat);
    //QSqlQueryModel * rechercher(int refrech);
    bool reference_gcExists(int nbe);
    //QSqlQueryModel * commandedetails();
QSqlQueryModel * rechercher(int nbe);
void logAction(const QString& actiontype_gc, const QString& actionDetails);
QSqlQueryModel *afficherhisory();
void displayLogHistory();
bool deletehistory();
void fichierPDF();
int comptertype_gc1();
int comptertype_gc0();
//bool isValidEmail_gc(QString Email_gc);
//void sendEmail_gc(const QString &to, const QString &subject, const QString &body);
};

#endif // COMMANDES_H
