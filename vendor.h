#ifndef VENDOR_H
#define VENDOR_H

#include <iostream>

#include "address.h"

#include <QString>

class Vendor
{
public:
    // constructors
    Vendor();
    Vendor(QString& ID, QString& name, Address& address);

    // methods
    std::string toString();
    void print();
    QString displayHeader();
    QString displayVendor();

    // setters
    void setID(QString& id);
    void setName(QString& name);
    void setAddress(Address& address);

    // getters
    const QString getID();
    const QString getName();
    Address getAddress();

    // overloaded operators
    friend std::ostream& operator<<(std::ostream&, const Vendor*);
    friend std::istream& operator>>(std::istream& is, Vendor& vendor);

private:
    QString ID;
    QString name;
    Address address;
};

#endif // VENDOR_H
