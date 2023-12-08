#include "Mainwindow_gc.h"
#include "ui_Mainwindow_gc.h"
#include "commandes.h"
#include "connection.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QObject>
#include <QDate>
#include <QPdfWriter> // Ajoutez cette ligne pour inclure QPdfWriter
#include <QPainter>
#include <QFont>
#include <QPageSize>
#include <QPageLayout>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include<QPdfWriter>
#include <QFileDialog>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QSqlTableModel>
#include "stmp.h"
#include <QtNetwork/QSslSocket>
#include <QDesktopServices>
#include <QUrl>
#include <QTextLength>
#include <QVBoxLayout>
#include <QPushButton>
//#include <takeAt>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QStandardItemModel>
#include <QDebug>
#include <QFileSystemWatcher>
MainWindow_gc::MainWindow_gc(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow_gc)
{
    ui->setupUi(this);
     //displayLogHistory();
QFileSystemWatcher fileWatcher;
    ui->reference->setValidator(new QIntValidator(0,999999999,this));
    ui->contact->setValidator(new QIntValidator(0,99999999,this) );
    //ui->date->setValidator(new QIntValidator(0,99999999,this));
    ui->ref->setValidator(new QIntValidator(0,99999999,this));
    ui->rechercher->setValidator(new QIntValidator(0,999999999,this));
    ui->tab_commandes->setModel(Etmp.afficher());
    connect(&fileWatcher, &QFileSystemWatcher::fileChanged, this, &MainWindow_gc::updateLogHistory);
    //connect(ui->displayhistory, &QPushButton::clicked, this, &MainWindow::on_displayhistory_clicked);
    displayLogHistory();
}

MainWindow_gc::~MainWindow_gc()
{
    delete ui;
}



void MainWindow_gc::on_ajouter_clicked()
{
    int reference=ui->reference->text().toInt();

    QString entreprise=ui->entreprise->text();
    QString objet=ui->objet->text();
    int type=ui->type->text().toInt();
    QString etat=ui->etat->text();
     QDate date=ui->date->date();
    int contact=ui->contact->text().toInt();
    QString Email=ui->Email->text();
    Commandes C(reference,entreprise,objet,type,etat,date,contact,Email);
    bool test=C.ajouter();

    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("ajout effectué.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
         ui->tab_commandes->setModel(C.afficher());
         /*QChart *chart = new QChart();
         QChartView *chartView = new QChartView(chart);
         chartView->setParent(ui->label_10);*/

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("ajout non effectué;\n"
                                                                                       "Click Cancel to exit."),QMessageBox::Cancel);

    }
    }


void MainWindow_gc::on_supprimer_clicked()
{
    Commandes C1;
    int nbe=ui->ref->text().toInt();
    if(C1.reference_gcExists(nbe))
    {
        bool test =C1.supprimer(nbe);
        if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Suppression affectuée \n"
                                                 "click exist to cancel"),QMessageBox::Cancel);
            ui->tab_commandes->setModel(C1.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectué;\n"
                                                                                           "Click Cancel to exit."),QMessageBox::Cancel);
     ui->tab_commandes->setModel(C1.afficher());

        }


    }

    else
    {
            QMessageBox::warning(nullptr, QObject::tr("Avertissement"),
                                        QObject::tr("La commande n'existe pas."), QMessageBox::Ok);
 ui->tab_commandes->setModel(C1.afficher());

    }



}
void MainWindow_gc:: on_modifier_clicked()
{
    Commandes C;
    int reference=ui->reference->text().toInt();

    QSqlQueryModel *resultModel = C.rechercher(reference);


    if (resultModel && resultModel->rowCount() > 0) {

        QString entreprise=ui->entreprise->text();
        QString objet=ui->objet->text();
        int type=ui->type->text().toInt();
        QString etat=ui->etat->text();
         QDate date=ui->date->date();
        int contact=ui->contact->text().toInt();
        QString Email=ui->Email->text();
        Commandes C(reference,entreprise,objet,type,etat,date,contact,Email);
        bool test=C.modifier();

        if(test)
        {

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification effectué.\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);

  ui->tab_commandes->setModel(C.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("modification non effectué;\n"
                                                                                           "Click Cancel to exit."),QMessageBox::Cancel);
  ui->tab_commandes->setModel(C.afficher());
        }
    } else {

        QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet reference.", QMessageBox::Cancel);
    }



}

void MainWindow_gc::on_trie_clicked()
{

    //ui->tab_commandes->setModel(C.afficher());

    ui->tab_commandes->setModel(Etmp.afficher(true,true,true));
}


void MainWindow_gc::on_rechercherb_clicked()
{
    Commandes C;
    int nbe = ui->rechercher->text().toInt();


       QSqlQueryModel *resultModel = C.rechercher(nbe);


       if (resultModel && resultModel->rowCount() > 0) {

           ui->tab_commandes->setModel(resultModel);
       } else {

           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet reference.", QMessageBox::Cancel);
       }
}
void MainWindow_gc::on_PDF_clicked()
{
    {
        QString fileName = QFileDialog::getSaveFileName(this, "Export PDF", QString(), "*.pdf");
        if (!fileName.isEmpty()) {
            if (QFileInfo(fileName).suffix().isEmpty()) {
                fileName.append(".pdf");
            }

            QPdfWriter writer(fileName);
            QPainter painter(&writer);

            int rowCount = ui->tab_commandes->model()->rowCount();
            int columnCount = ui->tab_commandes->model()->columnCount();

            // Décalage vers le bas
            int verticalOffset = 200;

            QString strStream;
            QTextStream out(&strStream);

            out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("TITLE")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                // Décalage du titre
                "<h1 style='color:#341763; font-family:Montserrat SemiBold; font-size:25px; position:absolute; top:" + QString::number(verticalOffset) + "px; left:50%; transform: translateX(-50%);'>Liste des employés</h1>\n"

                "<table border=1 cellspacing=0 cellpadding=2 width='100%'>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tab_commandes->isColumnHidden(column))
                    out << QString("<th width='%1%'>%2</th>").arg(100/columnCount).arg(ui->tab_commandes->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_commandes->isColumnHidden(column)) {
                        QString data = ui->tab_commandes->model()->data(ui->tab_commandes->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0 width='%1%'>%2</td>").arg(100/columnCount).arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            // Scale the painter
            double scale = 15.0;  // Adjust the scale factor here
            painter.scale(scale, scale);

            document->drawContents(&painter);

            delete document;
        }


    }
}

void MainWindow_gc::on_details_clicked()
{
    Commandes C;
    int nbe = ui->reference->text().toInt();


       QSqlQueryModel *resultModel = C.rechercher(nbe);


       if (resultModel && resultModel->rowCount() > 0) {

           ui->tab_ref->setModel(resultModel);
       } else {

           QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée pour cet Reference.", QMessageBox::Cancel);
       }
}

void MainWindow_gc::updateLogHistory()
{
    qDebug() << "File changed. Updating log history...";
    displayLogHistory();
}

// Function to display log history
/*void MainWindow::displayLogHistory()
{
    // Create a new model
    QStandardItemModel *model = new QStandardItemModel(this);

    // Open the log file for reading
    QFile logFile("actions.log");
    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening the log file for reading:" << logFile.errorString();
        delete model;  // Clean up the model in case of an error
        return;
    }

    // Create headers for the model
    model->setHorizontalHeaderLabels(QStringList() << "Timestamp" << "ActionType" << "ActionDetails");

    // Create a QTextStream to read from the file
    QTextStream in(&logFile);

    // Read and display each line from the file
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');

        // Check if the line has enough parts (columns)
        if (parts.size() >= 4) {
            // Extract the date and time from the first two parts
            QDateTime dateTime = QDateTime::fromString(parts[0] + ' ' + parts[1], "yyyy-MM-dd hh:mm:ss");

            // ActionType is the third and fourth parts
            QString actionType = parts[2] + " " + parts[3];

            // ActionDetails is the concatenation of the remaining parts
            QString actionDetails = parts.mid(4).join(' ');

            // Add a new row to the model
            QList<QStandardItem*> rowItems;
            rowItems.append(new QStandardItem(dateTime.toString("yyyy-MM-dd hh:mm:ss")));
            rowItems.append(new QStandardItem(actionType));
            rowItems.append(new QStandardItem(actionDetails));
            model->appendRow(rowItems);
        }
    }

    // Close the file
    logFile.close();

    // Set the model for the QTableView
    ui->history->setModel(model);

    // Additional settings (optional)
    ui->history->resizeColumnsToContents();  // Adjust column widths
    ui->history->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch the last column

    // Additional debug output
    qDebug() << "Number of rows in the table view:" << model->rowCount();
    qDebug() << "Number of columns in the table view:" << model->columnCount();
    qDebug() << "Headers in the table view:" << model->headerData(0, Qt::Horizontal).toString();

    // Add the log file to the file watcher
    fileWatcher.addPath("actions.log");
}*/
void MainWindow_gc::displayLogHistory()
{
    // Create a new model
    QStandardItemModel *model = new QStandardItemModel(this);

    // Open the log file for reading
    QFile logFile("actions.log");
    if (!logFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening the log file for reading:" << logFile.errorString();
        delete model;  // Clean up the model in case of an error
        return;
    }

    // Create headers for the model
    model->setHorizontalHeaderLabels(QStringList() << "Timestamp" << "ActionType" << "ActionDetails");

    // Create a QTextStream to read from the file
    QTextStream in(&logFile);

    // Read and display each line from the file
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(' ');

        // Check if the line has enough parts (columns)
        if (parts.size() >= 3) {
            // Extract the date and time from the first two parts
            QDateTime dateTime = QDateTime::fromString(parts[0] + ' ' + parts[1], "yyyy-MM-dd hh:mm:ss");

            // ActionType is the third part
            QString actionType = parts[2] +" "+ parts[3];

            // ActionDetails is the concatenation of the remaining parts
            QString actionDetails = parts.mid(4).join(' ');

            // Add a new row to the model
            QList<QStandardItem*> rowItems;
            rowItems.append(new QStandardItem(dateTime.toString("yyyy-MM-dd hh:mm:ss")));
            rowItems.append(new QStandardItem(actionType));
            rowItems.append(new QStandardItem(actionDetails));
            model->insertRow(0, rowItems);  // Insert at the beginning of the model
        }
    }

    // Close the file
    logFile.close();

    // Set the model for the QTableView
    ui->history->setModel(model);

    // Additional settings (optional)
    ui->history->resizeColumnsToContents();  // Adjust column widths
    ui->history->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch the last column

    // Additional debug output
    qDebug() << "Number of rows in the table view:" << ui->history->model()->rowCount();
}

/*void MainWindow::on_sendmail_clicked()
{

    Commandes C;
    mail* ssmtp = new mail("adem.marghli@esprit.tn", "221JMT4285", "smtp.gmail.com", 465);

              connect(ssmtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

              QString email=ui->mentreprise->text();

              QString b=ui->msujet->text();

              QString ob=ui->mmessage->toPlainText();

               if(email!="" && b!="" && ob!="" )
                  {
                                if(C.isValidEmail(email))
                                {
                                    ssmtp->sendMail("adem.marghli@esprit.tn", email , b,ob);
                                    QMessageBox::information(nullptr, QObject::tr("EMAIL"),
                                    QObject::tr("Email sent successfuly.\n"
                                    "click Cancel to exit"),QMessageBox::Cancel);
                                }
                                else
                                {
                                    QMessageBox::critical(nullptr, QObject::tr("EMAIL"),
                                    QObject::tr("Email failed to send.\n"
                                    "click Cancel to exit."),QMessageBox::Cancel);
                                }
                  }
               else
                  {
                          QMessageBox::critical(nullptr, QObject::tr("EMAIL"),
                          QObject::tr("something is empty.\n"
                          "click Cancel to exit."),QMessageBox::Cancel);
                  }
}

void MainWindow::updateStatistics() {
    // Assuming this function retrieves the count of type0 and type1 commands
    Commandes C;
    int counttype0 = C.comptertype0();
    int counttype1 = C.comptertype1();

    // Assuming set0 and set1 are member variables of MainWindow
    set0->replace(0, counttype1);
    set1->replace(0, counttype0);

    // Refresh the chart view

    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    ui->label_10->chartView()->update();
}*/

void MainWindow_gc::on_refrech_clicked()
{
    QLayoutItem* item;
    while((item=ui->label_10->takeAt(0))!=nullptr)
       {
delete item->widget();
        delete item;
    }
    QBarSet *set0 = new QBarSet("Achat");
    QBarSet *set1 = new QBarSet("Vente ");
Commandes C;
    int counttype0 = C.comptertype_gc0();
                int counttype1 = C.comptertype_gc1();
                * set0 <<counttype1<<10 ;

                * set1 << counttype0<<10;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("COMMANDES");
        chart->setAnimationOptions(QChart:: SeriesAnimations);
        chart->resize(450,300);
        QStringList categories;
        categories << " TYPE" ;
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);
        QChartView *chartView = new QChartView(chart);
       ui->label_10->addWidget(chartView);

}

void MainWindow_gc::on_displayhistory_clicked()
{
    displayLogHistory();
}

/*void MainWindow::on_deletehistory_clicked()
{
    Commandes C1;
        bool test = C1.deletehistory();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Suppression effectuée\n"
                                                 "Les actions ont été supprimées du fichier."),
                                     QMessageBox::Cancel);

            // Update the log history model after deletion
            //updateLogHistoryModel();
            displayLogHistory();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"), QObject::tr("Suppression non effectuée;\n"
                                                                              "Cliquez sur Annuler pour sortir."),
                                  QMessageBox::Cancel);
        }
}*/
/*void MainWindow::on_sendmail_clicked() {
    QString to = ui->mentreprise->text();
    QString subject = ui->msujet->text();
    QString body = ui->mmessage->toPlainText();

    sendEmail(to, subject, body);
}*/

void MainWindow_gc::on_affichercommande_clicked()
{
    Commandes C;
    ui->tab_commandes->setModel(C.afficher());
}
/*void MainWindow::on_sendMail_clicked()
{
    qDebug() << "Sending email...";

        // Get the user input from the line edits
        QString entrepriseEmail = ui->mentreprise->text();
        QString message = ui->mmessage->toPlainText();


        // Validate the email address
        if (!isValidEmail(entrepriseEmail)) {
            qDebug() << "Invalid email address";
            QMessageBox::critical(this, "Error", "Invalid email address");
            return;
        }

        // Create an instance of the smtp class with your email credentials
        Smtp *S = new Smtp("ademmarghli@gmail.com", "olpa ebss qxzq rmcj", "smtp.gmail.com", 465);

        qDebug() << "Email content:";
        qDebug() << "To: " << entrepriseEmail;
        qDebug() << "Subject: Subject";
        qDebug() << "Body: " << message;

        // Send the email
        S->sendMail("smtp@gmail.com", entrepriseEmail, "Subject", message);

        // Check for successful email sending
        if (S->getSocketState() == QAbstractSocket::ConnectedState) {
            qDebug() << "Email sent successfully!";

            // Additional debugging information
            qDebug() << "Socket state:" << S->getSocketState();
            qDebug() << "Socket error string:" << S->getSocketErrorString();
            qDebug() << "SMTP server response:" << S->getServerResponse();

            QMessageBox::information(this, "Email Sent", "The email has been sent successfully!");
        } else {
            qDebug() << "Error sending email:" << S->getSocketErrorString();

            // Additional debugging information
            qDebug() << "Socket state:" << S->getSocketState();
            qDebug() << "Socket error string:" << S->getSocketErrorString();
            qDebug() << "SMTP server response:" << S->getServerResponse();

            QMessageBox::warning(this, "Error", "Error sending email. Check the console for details.");
        }

        // Cleanup
        delete S;
}

bool MainWindow::isValidEmail(const QString &email)
{
    // Simple email validation using a regular expression
        QRegExp emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");
        return emailRegex.exactMatch(email);
}*/
void MainWindow_gc::sendMail()
{
    smtp* smtp = new class smtp (ui->uname->text(), ui->paswd->text(), "smtp.gmail.com",465);//username=uname //
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            smtp->sendMaile(ui->uname->text(), ui->mentreprise->text() , ui->msujet->text(),ui->mmessage->toPlainText());
}
void MainWindow_gc::on_sendMail_clicked()
{
    sendMail();
}
void MainWindow_gc::handleSmtpStatus(const QString& status)
{
    qDebug() << "SMTP Status:" << status;
}
