#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "video.h"
#include "camera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
   void on_ajouter_clicked();
    void on_modidier_clicked();
    void on_supprimer_clicked();

    void on_afficher_clicked();

    void on_affiche_tab_activated(const QModelIndex &index);

    void on_pb_recherche_clicked();

    void on_pb_pdf_clicked();

    void on_pb_stat_clicked();

    void on_pdf_trier_clicked();

    void on_pb_camera_clicked();

   void on_pb_importervid_clicked();
    void on_pb_play_clicked() ;
    void on_pb_stop_clicked();
    void on_pb_pause_clicked();

private:
    Ui::MainWindow *ui;

      QMediaPlayer *player;
       Camera *camera;
};
#endif // MAINWINDOW_H
