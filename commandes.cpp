#include "commandes.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include "connection.h"
#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
//#include <QPrinter>
#include <QPdfWriter> // Ajoutez cette ligne pour inclure QPdfWriter
#include <QPainter>
#include <QFont>
#include <QPageSize>
#include <QPageLayout>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include<QPdfWriter>
#include <QTextCursor>
#include <QRegularExpression>
#include <fstream>
#include <QDateTime>
#include <QFile>
#include <QDebug>
/*#include <QtMail>
#include <quickmail.h>
#include <QtWidgets>
#include <QSmtp>
#include <QMimeMessage>
#include <QMimeEmail_gcAddress>*/
Commandes::Commandes()
{
reference_gc=0;
entreprise_gc="";
objet_gc="";
type_gc=0;
etat_gc="";
contact_gc=0;
Email_gc="";

}
Commandes::Commandes(int reference_gc,QString entreprise_gc,QString objet_gc,int type_gc,QString etat_gc,QDate date_gc,int contact_gc,QString Email_gc)
{
   this->reference_gc=reference_gc;
    this->entreprise_gc=entreprise_gc;
    this->objet_gc=objet_gc;
    this->type_gc=type_gc;
    this->etat_gc=etat_gc;
    this->date_gc=date_gc;
    this->contact_gc=contact_gc;
    this->Email_gc=Email_gc;
}
//setters
void Commandes::setreference_gc(int n){reference_gc =n;}
void Commandes::setentreprise_gc(QString n){entreprise_gc=n;}
void Commandes::setobjet_gc(QString n){objet_gc=n;}
void Commandes::settype_gc(int n){type_gc=n;}
void Commandes::setetat_gc(QString n){etat_gc=n;}
void Commandes::setdate_gc(QDate n){date_gc=n;}
void Commandes::setcontact_gc(int n){contact_gc=n;}
void Commandes::setEmail_gc(QString n){Email_gc=n;}
//getters
int Commandes::get_reference_gc(){return reference_gc;}
QString Commandes::get_entreprise_gc(){return entreprise_gc;}
QString Commandes::get_objet_gc(){return objet_gc;}
int Commandes::get_type_gc(){return type_gc;}
QString Commandes::get_etat_gc(){return etat_gc;}
QDate Commandes::get_date_gc(){return date_gc;}
int Commandes::get_contact_gc(){return contact_gc;}
QString Commandes::get_Email_gc(){return Email_gc;}

//ajouter
bool Commandes::ajouter(){

    QSqlQuery query;
    QString res = QString::number(reference_gc);
    QString nb= QString::number(contact_gc);
    QString t= QString::number(type_gc);

    query.prepare("INSERT INTO COMMANDES (REF, ENTREPRISE, OBJET, TYPE, CONTACT, EMAIL, DATES, ETAT)"
                  "VALUES(:REF, :ENTREPRISE, :OBJET, :TYPE, :CONTACT, :EMAIL, :DATES, :ETAT)");

    query.bindValue(":REF", res);
    query.bindValue(":ENTREPRISE", entreprise_gc);
    query.bindValue(":OBJET", objet_gc);
    query.bindValue(":TYPE", t);
    query.bindValue(":CONTACT", nb);
    query.bindValue(":EMAIL", Email_gc);
    query.bindValue(":DATES", date_gc);  // Corrected bind value
    query.bindValue(":ETAT", etat_gc);
    QString actionDetails = "reference: " + QString::number(reference_gc) ;


        // Log the action
        logAction("commande ajoutée", actionDetails);
  //emit dataChanged();
    return query.exec();
}
QSqlQueryModel *Commandes::afficher()
{
     QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Commandes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REF"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("entreprise"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("objet"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("contact"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("date"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("etat"));
    return model;

}
bool Commandes::reference_gcExists(int nbe)
{
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM COMMANDES WHERE REF = :REF");
    query.bindValue(":REF", nbe);

    if (query.exec() && query.next()) {
        // If the count is greater than 0, the reference_gc exists
        return query.value(0).toInt() > 0;
    }


    return false;


}
bool Commandes::supprimer(int nbe)
{
    QSqlQuery query;
    QString res=QString::number(nbe);
    query.prepare("Delete from Commandes where REF= :nbe");
    query.bindValue(0,nbe);
    QString actionDetails = "reference: " + QString::number(reference_gc) ;
                                ", entreprise: " + entreprise_gc +
                                ", objet: " + objet_gc +
                                ", type: " + type_gc +
                                ", contact: " + QString::number(contact_gc) +
                                ", Email: " + Email_gc +
                                ", date: " + date_gc.toString("yyyy-MM-dd")  +
                                ", etat: " + etat_gc;

        // Log the action
        logAction("commande supprimée", actionDetails);

    return query.exec();

}
bool Commandes::modifier()
{
    QSqlQuery query;
    //QString res = QString::number(reference_gc);
    QString nb= QString::number(contact_gc);
QString t= QString::number(type_gc);
      query.prepare("SELECT COUNT(*) FROM COMMANDES WHERE REF = :REF");
        query.bindValue(":REF", reference_gc);
        query.exec();
        query.next();
        int count = query.value(0).toInt();
        if (count == 0)
        {
            // REF does not exist in the database, return false
            return false;
        }

        // REF exists, execute the update query
        QString res = QString::number(reference_gc);

    query.prepare("UPDATE COMMANDES SET REF= :REF ,ENTREPRISE= :ENTREPRISE, OBJET= :OBJET, TYPE= :TYPE, CONTACT= :CONTACT, EMAIL= :EMAIL, DATES :DATES , ETAT= :ETAT WHERE REF= :REF");
    query.bindValue(":REF",res);
    query.bindValue(":ENTREPRISE",entreprise_gc);
    query.bindValue(":OBJET",objet_gc);
    query.bindValue(": TYPE",t);
    query.bindValue(":CONTACT",nb);
    query.bindValue(":EMAIL",Email_gc);
    query.bindValue(":DATES",date_gc);
    query.bindValue(":ETAT ",etat_gc);
    QString actionDetails = "reference: " + QString::number(reference_gc) ;

        // Log the action
        logAction("commande modifiée", actionDetails);
          //emit dataChanged();
    bool success=query.exec();
    return success;
}

QSqlQueryModel * Commandes::afficher(bool sortBydate_gc,bool sortBytype_gc,bool sortByetat_gc)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    if (sortBydate_gc) {
        query.prepare("SELECT * FROM COMMANDES ORDER BY dates ASC");
    } else if (sortBytype_gc) {
                 query.prepare("SELECT * FROM COMMANDES ORDER BY type ASC");
             } else if (sortByetat_gc) {
                 query.prepare("SELECT * FROM COMMANDES ORDER BY etat ASC");
             }
else {
        query.prepare("SELECT * FROM COMMANDES");
    }

    if (query.exec()) {
        model->setQuery(query);
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("entreprise"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("objet"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("dates"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("etat"));

    return model;
}
QSqlQueryModel * Commandes::rechercher(int nbe) {
    QSqlQueryModel *model = new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM COMMANDES WHERE REF = :REF");
      query.bindValue(":REF", nbe); // Ajout de la liaison

      if (query.exec()) {
          model->setQuery(query);
      }

      return model;
}


void Commandes::logAction(const QString& actiontype_gc, const QString& actionDetails)
{

    QFile logFile("actions.log");
    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&logFile);

               out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ";
               out << actiontype_gc << " ";
               out << actionDetails.left(25) << "\n";
               out.flush();

        logFile.close();
     qDebug() << "Action logged:" << actionDetails;  // Add this line for debug output
    }
 else {
    qDebug() << "Error opening the log file for writing:" << logFile.errorString();
}

}
int Commandes::comptertype_gc1()
{
    int etat1;
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM COMMANDES WHERE type = 1");
       query.next();
      etat1 = query.value(0).toInt();
        return etat1;
}
int Commandes::comptertype_gc0()
{
    int etat0;
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM COMMANDES WHERE type = 0");
     query.next();
     etat0 = query.value(0).toInt();
        return etat0;
       //  emit dataChanged();

}
/*bool Commandes::deletehistory()
{



    // Delete entries from the file
    QFile logFile("actions.log");
    if (logFile.remove()) {
        qDebug() << "Log file successfully deleted";
    } else {
        qDebug() << "Error deleting log file:" << logFile.errorString();
    }


}*/

/*bool Commandes::isValidEmail_gc(QString Email_gc) {
    QRegularExpression regex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");

       // We use QRegularExpressionMatch to test if the Email_gc matches the regex pattern
       QRegularExpressionMatch match = regex.match(Email_gc);

       // If the match is valid, return true. Otherwise, return false.
       return match.hasMatch();
}

void Commandes::sendEmail_gc(const QString &to, const QString &subject, const QString &body) {
    QuickMail quickmail = quickmail_create("your.smtp.server.com", 587, QuickMail::USE_TLS);

       quickmail_add_header(quickmail, "From", "your_Email_gc@example.com");
       quickmail_add_header(quickmail, "To", to.toStdString().c_str());
       quickmail_add_header(quickmail, "Subject", subject.toStdString().c_str());

       quickmail_add_body(quickmail, body.toStdString().c_str());

       if (!quickmail_send(quickmail)) {
           qDebug() << "Error sending Email_gc";
       }

       quickmail_destroy(quickmail);
}*/
