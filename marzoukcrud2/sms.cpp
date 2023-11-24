#include <QtNetwork>
#include "sms.h"




QString twilio_phone_number = "+12565791080";




sms::sms(){


}
void sms::sendSMS(const QString &to, const QString &message) {
    QNetworkAccessManager *manager = new QNetworkAccessManager();


    QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC3c643b0e43c9213da6cf0df8c66f20d1/Messages.json");
    QNetworkRequest request(url);




    QString credentials = "AC3c643b0e43c9213da6cf0df8c66f20d1:d3ce5558180b61cfb7496d604578d439";
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + base64Credentials);




    QByteArray postData;
    postData.append("From="+twilio_phone_number);
    postData.append("&To=" + to);
    postData.append("&Body=" + message);




    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");



  ;
    QNetworkReply *reply = manager->post(request, postData);




    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS sent successfully";
        } else {
            qDebug() << "Failed to send SMS:" << reply->errorString();
        }




        reply->deleteLater();
        manager->deleteLater();
    });
}
