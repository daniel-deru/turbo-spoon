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
    void toString();

    // setters
    void setID(QString& id);
    void setName(QString& name);
    void setAddress(Address& address);

    // getters
    const QString getID();
    const QString getName();
    const Address getAddress();

    // overloaded operators
    friend std::ostream& operator<<(std::ostream&, const Vendor*);

private:
    QString ID;
    QString name;
    Address address;
};

#endif // VENDOR_H
