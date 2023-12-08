#ifndef SMS_H
#define SMS_H
#include "QString"




class Sms
{
public:
    Sms();
    void sendSMS(const QString &to, const QString &message);
};


#endif // SMS_H
