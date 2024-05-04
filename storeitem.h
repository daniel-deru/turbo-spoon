#ifndef STOREITEM_H
#define STOREITEM_H

#include <iostream>

#include "item.h"
#include "vendor.h"

#include <QString>


class StoreItem : public Item
{
public:

    // constructors
    StoreItem();
    StoreItem(QString& ID, QString& name, float price);


    // methods
    QString toString();
    QString toString(bool includeVendor);

    // overloaded methods
    void print();

    // setters
    void setVendor(Vendor& vendor);

    // getters
    const QString getVendorName();

    // Overloaded operators
    friend std::istream& operator>>(std::istream& is, const StoreItem* storeItem);

private:
    Vendor vendor;
};

#endif // STOREITEM_H
