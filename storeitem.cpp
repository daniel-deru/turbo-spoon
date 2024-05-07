#include "storeItem.h"

#include <QTextStream>

// Constructors
StoreItem::StoreItem() {}

StoreItem::StoreItem(QString& ID, QString& name, float price) : Item(ID, name, price) {}


QString StoreItem::toString() {
    return displayHeader() + "\n" + displayItem();
}

QString StoreItem::toString(bool includeVendor) {
    QString result = toString();

    if(!includeVendor) return result;

    if (vendor.getName() != "") {
        QString header = displayHeader() + vendor.displayHeader() + "\n";
        QString item = displayItem() + vendor.displayVendor();
        result = header + item;
    }

    return result;
}

void StoreItem::print() {
    bool hasVendor = vendor.getName() == "";
    std::cout << toString(hasVendor).toStdString() << std::endl;
}

StoreItem StoreItem::createStoreItem() {
    Item item = Item::createItem();

    QString ID = item.getID();
    QString name = item.getName();
    float price = item.getPrice();

    return StoreItem(ID, name, price);
}

void StoreItem::setVendor(Vendor& v) {
    vendor = v;
}

const QString StoreItem::getVendorName() {
    QString vendorName = vendor.getName() != "" ? vendor.getName() : "Unknown";
    return vendorName;
}
