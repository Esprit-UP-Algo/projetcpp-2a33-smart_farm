#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "commandes.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Commandes Etmp;
private slots:

    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    //void on_Tri_clicked();



    //void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
