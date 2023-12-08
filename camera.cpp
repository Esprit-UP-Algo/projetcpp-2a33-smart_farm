#include "camera.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>


Camera::Camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  // Use the forward declaration
{
    ui->setupUi(this);
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOptionMenu = new QMenu("options", this);
    mStartAction = new QAction("Start", this);
    mEndAction = new QAction("End", this);
    mCapturAction = new QAction("captur", this);

    mOptionMenu->addActions({mStartAction, mEndAction, mCapturAction});
    ui->pb_camera->setMenu(mOptionMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mStartAction, &QAction::triggered, [&]() { mCamera->start(); });
    connect(mEndAction, &QAction::triggered, [&]() { mCamera->stop(); });
    connect(mCapturAction, &QAction::triggered, [&]()
    {
        auto filename = QFileDialog::getSaveFileName(this, "capture", "/", "Image (*.jpg ; *.jpeg)");
        if (filename.isEmpty())
        {
            return;
        }
        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600, 1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });
}

Camera::~Camera()
{
    delete ui;
}



