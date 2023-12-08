#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include <QtCharts>
#include <QDate>
#include "arduino.h"
#include "commandes.h"


namespace Ui {
class MainWindow;
}

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
//////////////////////////////////////

private:
    Ui::MainWindow *ui;
    Employe EM;
    Commandes Etmp;
Arduino A;
QByteArray data;
    QChartView *ageStatisticsChartView;


};

#endif // MAINWINDOW_H
