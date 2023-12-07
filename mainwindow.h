#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include <QtCharts>
#include <QDate>
#include "arduino.h"
#include "commandes.h"
/////////////////////////////

//#include "video.h"
//#include "camera.h"

/////////////////////////////
#include "animaux.h"
///////////////////////////
#include <aliments.h>
#include <QTextDocument>
#include <QMessageBox>

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
#include <QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "arduino.h"
#include <QPlainTextEdit>
#include <QVBoxLayout>
QT_BEGIN_NAMESPACE
/////////////////////////////////////////////////////

namespace Ui {
class MainWindow;
}
///////////////////
QT_END_NAMESPACE
////////////////////////
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_AJOUTER1_clicked();
    void on_SUPPRIMER1_clicked();

    void on_TRIER_clicked();
    void on_chercher_clicked();
    void on_pb_pdf_clicked();
   void updateAgeStatisticsChart();
void clearAgeStatisticsChart();

void on_confirmer_clicked();

void on_verifier_clicked();

//void on_Annuler_clicked();


//void on_CHERCHER_textEdited(const QString &arg1);

void on_comboBox_activated(const QString &arg1);

void on_tabWidget_currentChanged(int index);
void handleDataFromArduino(const QByteArray &data);

//void update_label();
//void verifyEmployeeIdInDatabase(const QString &employeeId);


void on_miseajour1_clicked();

void on_COMMANDES_2_clicked();

void on_EMP1_clicked();

void on_COM1_clicked();

void on_EMPLOYES_2_clicked();
////////////////////ADAM//////////////
void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void updateLogHistory();


        //void on_pushButton_clicked();
        void on_trie_clicked();
        void on_rechercherb_clicked();
        void on_PDF_clicked();
        void displayLogHistory();
        //void on_tab_ref_activated(const QModelIndex &index);
        void on_details_clicked();
        //void on_deletehistory_clicked();
        //void on_sendMail_clicked();
        //void updateStatistics();
        void on_refrech_clicked();
        //void displayLogHistoryModel();
        void on_displayhistory_clicked();
        //void on_deletehistory_clicked();
        void on_affichercommande_clicked();
        //bool isValidEmail(const QString &email);
       // void sendMail();
        //void handleSmtpStatus(const QString& status);
///////////////////////MARZOUK////////////////////////////
        void on_pushButton_clicked();

            void on_pushButton_24_clicked();
            void on_pushButton_13_clicked();

            /*void on_pushButton_31_clicked();*/
            void on_pushButton_15_clicked();
            void on_pb_pdf1_clicked();
            void showTypeStatistics();
            int getTotalTypeCount(const QMap<QString, int> &statistics);




            void on_pushButton_12_clicked();

            void on_pushButton_30_clicked();


          //  void on_feu_clicked();

         //   void getTemperatureForLait();
 void on_ALIMENTATION_2_clicked();
void on_ALM1_clicked();
///////////////////////////////HADIL///////////////////////
void on_ajouterr_clicked();
    void on_modidier_clicked();
    void on_supprimer1_clicked();

    void on_afficher_clicked();

    void on_affiche_tab_activated(const QModelIndex &index);

    void on_pb_recherche_clicked();

    void on_pb_pdf2_clicked();

    void on_pb_stat_clicked();

    void on_pdf_trier_clicked();

    void on_pb_camera_clicked();

   /* void on_pb_importervid_clicked();
    void on_pb_play_clicked() ;
    void on_pb_stop_clicked();
    void on_pb_pause_clicked();*/
    void on_EQUIPEMENTS_2_clicked();
    void on_EQ1_clicked();
////////////////////////////////////////////////////////////////
    void on_animaux_clicked();

    void on_ANIMAUX_2_clicked();

    void on_AN1_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    Employe EM;
    Commandes Etmp;
Arduino A;
QByteArray data;
    QChartView *ageStatisticsChartView;
    QByteArray d;
Aliments Etm;
animaux etmp;
Arduino a;
//QMediaPlayer *player;
   // Camera *camera;


};

#endif // MAINWINDOW_H
