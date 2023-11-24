#ifndef ALIMENTS_H
#define ALIMENTS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class Aliments
{
    int ref;
    QString dateimp;
    QString datexp;
    int quantite;
    QString type;
    int refc;
public:
    Aliments();
    Aliments(int,QString, int, int,QString ,QString );
    // GETTERS
    int getref();
    QString getdateimp();
    QString getdatexp();
    int getquantite();
    QString gettype();
    //SETTERS
    void setref(int newref);
    void setdateimp(QString newdateimp);
    void setdateexp(QString newdatexp);
    void setquantite(int newquantite);
    void settype(QString newtype);

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int ref);
    QSqlQueryModel *trier_type();
    QSqlQueryModel *afficherAliments();
    QSqlQueryModel * rechercher(int refrech);
     QMap<QString, int> getquantiteStatistics();

};



#endif // ALIMENTS_H
