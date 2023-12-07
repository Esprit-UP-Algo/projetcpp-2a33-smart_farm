#ifndef MAINWINDOW_gc_H
#define MAINWINDOW_gc_H

#include <QMainWindow>
#include <QObject>
#include "commandes.h"
#include <QFileSystemWatcher>
#include "stmp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_gc; }
QT_END_NAMESPACE

class MainWindow_gc : public QMainWindow
{
    Q_OBJECT
    QFileSystemWatcher fileWatcher;
 signals :
    void dataChanged();
public:
    MainWindow_gc(QWidget *parent = nullptr);
    ~MainWindow_gc();
private:
    Ui::MainWindow_gc *ui;
    Commandes Etmp;

private slots:

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
    void on_sendMail_clicked();
    //void updateStatistics();
    void on_refrech_clicked();
    //void displayLogHistoryModel();
    void on_displayhistory_clicked();
    //void on_deletehistory_clicked();
    void on_affichercommande_clicked();
    //bool isValidEmail(const QString &email);
    void sendMail();
    void handleSmtpStatus(const QString& status);
};
#endif // MAINWINDOW_GC_H
