#include "video.h"
#include "ui_mainwindow.h"
//#include "ui_video.h"

video::video(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

       player = new QMediaPlayer(ui->tableView);//`QMediaPlayer` est utilisé pour lire le fichier vidéo
        vw = new QVideoWidget(ui->tableView);// `QVideoWidget` est utilisé pour afficher la vidéo
        player->setVideoOutput(vw);//`player->setVideoOutput(vw)` indique que la sortie vidéo du lecteur doit être envoyée à l'objet `QVideoWidget`
        this->setCentralWidget(vw);
        vw->setGeometry(50, 50,350, 350);//`vw->setGeometry(50, 50,350, 350)` détermine la position et la taille de l'objet `QVideoWidget` sur la fenêtre principale.
        slider= new QSlider(this);//`QSlider` est utilisé pour permettre à l'utilisateur de faire défiler la vidéo
        bar =new QProgressBar(this);//`QProgressBar` affiche la progression de la lecture de la vidéo
        slider->setOrientation(Qt::Horizontal);//`slider->setOrientation(Qt::Horizontal)` détermine l'orientation du `QSlider`
        ui->statusbar->addPermanentWidget(slider);//Les deux widgets sont ajoutés à la barre d'état de la fenêtre principale
        ui->statusbar->addPermanentWidget(bar);

        connect (player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);//sont utilisés pour mettre à jour la progression de la lecture de la vidéo dans la barre de progression.
        connect (player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
        connect (slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);


        connect (player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
        connect (player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);
}

video::~video()
{
    delete ui;
}

/*void video::on_pb_importervid_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this,"open a File","","Video File (*.*)");
    on_pb_stop_clicked();

    player->setMedia(QUrl::fromLocalFile(filename));


    on_pb_play_clicked();
}

void video::on_pb_importervid_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"open a File","","Video File (*.*)");
    on_pb_stop_clicked();

    player->setMedia(QUrl::fromLocalFile(filename));


    on_pb_play_clicked();

}

/*void video::on_pb_play_clicked()
{

player->play();
ui->statusbar->showMessage("Playing");
}

void video::on_pb_stop_clicked()
{
    player->stop();
    ui->statusbar->showMessage("Stopped...");
}

void video::on_pb_pause_clicked()
{
player->pause();
ui->statusbar->showMessage("Paused...");
}*/


