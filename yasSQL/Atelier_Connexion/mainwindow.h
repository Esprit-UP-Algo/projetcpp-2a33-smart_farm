#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

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
void on_crud_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    Employe EM;
};

#endif // MAINWINDOW_H
