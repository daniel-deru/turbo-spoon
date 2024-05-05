#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
public:
    QString street;
    QString city;
    QString province;
    QString country;

    Address();

    Address(
        QString& street,
        QString& city,
        QString& province,
        QString& country);

    void print();
    QString toString();
    QString getAddress();

    // Getter methods
    const QString& getStreet() const;
    const QString& getCity() const;
    const QString& getProvince() const;
    const QString& getPostCode() const;
    const QString& getCountry() const;

    // Setter methods
    void setStreet(QString& street);
    void setCity(QString& city);
    void setProvince(QString& province);
    void setPostCode(QString& postCode);
    void setCountry(QString& country);


    friend std::istream& operator>>(std::istream& is, Address& address);
};

#endif // ADDRESS_H
