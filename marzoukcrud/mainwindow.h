#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <aliments.h>
#include <QTextDocument>
#include <QMessageBox>
#include <QDate>
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
#include<QChart>
#include <QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

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
    void on_pushButton_clicked();

    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();
    void on_pushButton_15_clicked();
    void on_pb_pdf_clicked();
    void showTypeStatistics();
    int getTotalTypeCount(const QMap<QString, int> &statistics);



    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::MainWindow *ui;
    Aliments Etmp;

};
#endif // MAINWINDOW_H
