#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
public:
    QString streetNumber;
    QString streetName;
    QString city;
    QString province;
    QString postCode;
    QString country;

    Address();

    Address(
        QString& streetNumber,
        QString& streetName,
        QString& city,
        QString& province,
        QString& postCode,
        QString& country);

    void print();
};

#endif // ADDRESS_H
