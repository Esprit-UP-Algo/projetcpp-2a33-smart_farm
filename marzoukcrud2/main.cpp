#include "mainwindow.h"
#include "connection.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

    //open qss file
    QFile file(":/qressource/stylesheet/Aqua.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QLatin1String(file.readAll()) };

    //setup stylesheet
    a.setStyleSheet(styleSheet);

    Connection c;
    c.testConnection();

    MainWindow w;

    w.show();
    return a.exec();
}
