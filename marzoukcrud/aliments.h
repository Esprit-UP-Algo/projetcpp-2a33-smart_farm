#ifndef ALIMENTS_H
#define ALIMENTS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTextDocument>
#include <QMessageBox>
#include <QDate>
#include <QStandardItem>
#include <QStandardPaths>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include <QtCharts/QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include<QChartView>
#include<QChart>
#include <QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>



class Aliments
{
    int ref;
    QDate dateimp;
    QDate datexp;
    int quantite;
    int temperature;
    QString type;
    int refc;
    QString image;
public:

    Aliments();
    Aliments(int,QString,int, int, int,QDate,QDate,QString);
    // GETTERS
    int getref();
    QDate getdateimp();
    QDate getdatexp();
    int getquantite();
    QString gettype();
    QString getimage();

    //SETTERS
    void setref(int newref);
    void setdateimp(QDate newdateimp);
    void setdateexp(QDate newdatexp);
    void setquantite(int newquantite);
    void settype(QString newtype);
    void setimage(QString image);

    void showTypeStatistics();

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int ref);
    QSqlQueryModel *trier_type();
    QSqlQueryModel *afficherAliments();
    QSqlQueryModel * rechercher(int refrech);
    QSqlQueryModel * rechercher1(int refrech);
    QMap<QString, int> getquantiteStatistics();
    QMap<QString, int> getTypeStatistics();

};



#endif // ALIMENTS_H
