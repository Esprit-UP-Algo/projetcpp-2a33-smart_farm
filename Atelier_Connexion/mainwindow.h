#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include <QtCharts>
#include <QDate>
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
    void on_miseajour_clicked();
    void on_TRIER_clicked();
    void on_chercher_clicked();
    void on_pb_pdf_clicked();
   void updateAgeStatisticsChart();
void clearAgeStatisticsChart();
void on_crud_currentChanged(int index);
void on_confirmer_clicked();

void on_verifier_clicked();

//void on_Annuler_clicked();


private:
    Ui::MainWindow *ui;
    Employe EM;

    QChartView *ageStatisticsChartView;


};

#endif // MAINWINDOW_H
