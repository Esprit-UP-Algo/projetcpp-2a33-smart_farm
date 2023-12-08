#ifndef CAMERA_H
#define CAMERA_H
#include <QDialog>

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
#include <QMainWindow>

namespace Ui {
    class MainWindow;  // Forward declaration
}

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();

//private slots:


private slots:


private:
    Ui::MainWindow *ui;  // Use the UI class from mainwindow
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOptionMenu;
    QAction *mStartAction;
    QAction *mEndAction;
    QAction *mCapturAction;
};
#endif // CAMERA_H
