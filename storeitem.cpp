#include "storeItem.h"

#include <QTextStream>

// Constructors
StoreItem::StoreItem() {}

StoreItem::StoreItem(QString& ID, QString& name, float price) : Item(ID, name, price) {}


QString StoreItem::toString() {
    return "ID: " + getID() + "\n Name: " + getName() + "\n Price: " + QString::number(getPrice());
}

QString StoreItem::toString(bool includeVendor) {
    QString result = toString();
    if (includeVendor) {
        result += "\n Vendor: " + getVendorName();
    }
    return result;
}

void StoreItem::print() {
    std::cout << toString(true).toStdString() << std::endl;
}

void StoreItem::setVendor(Vendor& v) {
    vendor = v;
}

const QString StoreItem::getVendorName() {
    return vendor.getName();
}

std::istream& operator<<(std::istream& is, const StoreItem* storeItem)
{
    QTextStream cin(stdin);
    QTextStream cout(stdout);

    cout << "Item ID: ";
    cout.flush();
    QString itemID = cin.readLine();

    cout << "Item Name: ";
    cout.flush();
    QString itemName = cin.readLine();

    cout << "Item Price: ";
    cout.flush();
    QString itemPriceStr = cin.readLine();
    float itemPrice = itemPriceStr.toFloat();

    cout << "Vendor ID: ";
    cout.flush();
    QString vendorID = cin.readLine();

    cout << "Vendor Name: ";
    cout.flush();
    QString vendorName = cin.readLine();

    cout << "Vendor Street Number: ";
    cout.flush();
    QString vendorStreetNumber = cin.readLine();

    cout << "Vendor Street Name: ";
    cout.flush();
    QString vendorStreetName = cin.readLine();

    cout << "Vendor City: ";
    cout.flush();
    QString vendorCity = cin.readLine();

    cout << "Vendor Province: ";
    cout.flush();
    QString vendorProvince = cin.readLine();

    cout << "Vendor Post Code: ";
    cout.flush();
    QString vendorPostCode = cin.readLine();

    cout << "Vendor Country: ";
    cout.flush();
    QString vendorCountry = cin.readLine();

    StoreItem item(itemID, itemName, itemPrice);

    Address address(
        vendorStreetNumber,
        vendorStreetName,
        vendorCity,
        vendorProvince,
        vendorPostCode,
        vendorCountry
        );

    Vendor vendor(vendorID, vendorName, address);

    item.setVendor(vendor);

    return is;
}
