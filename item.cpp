#include "item.h"
#include "commandline.h"

#include <iostream>

// Default constructor
Item::Item() {}

Item::Item(QString& ID, QString& name, float price) : ID(ID), name(name), price(price) {}

// Method to print item details
void Item::print() {
    std::cout << toString() << std::endl;
}

std::string Item::toString() {
    QString itemDetails = QString("ID: %1\nName: %2\nPrice: %3").arg(ID, name, QString::number(price));
    return itemDetails.toStdString();
}

QString Item::displayHeader() {
    QString IDHeader = QString("ID").leftJustified(ID.length());
    QString nameHeader = QString("Name").leftJustified(name.length());
    QString priceHeader = QString("Price").leftJustified(QString::number(price).length());

    return QString("%1\t|%2\t|%3\t|").arg(IDHeader, nameHeader, priceHeader);
}

QString Item::displayItem() {
    return (getID() + "\t|" + getName() + "\t|" + QString::number(getPrice()) + "\t|");
}

Item Item::createItem(){
    QString itemID = QCommandLine::input("Enter Item ID: ");
    QString itemName = QCommandLine::input("Enter Item Name: ");
    float itemPrice = QCommandLine::input("Enter Item Price: ").toFloat();

    Item item(itemID, itemName, itemPrice);

    return item;
}

/* ---------- Setters ---------- */

void Item::setID(QString& id) {
    ID = id;
}

void Item::setName(QString& nm) {
    name = nm;
}

void Item::setPrice(float pr) {
    price = pr;
}

/* ---------- Getters ---------- */

const QString Item::getID() {
    return ID;
}

const QString Item::getName() {
    return name;
}

const float Item::getPrice() {
    return price;
}


std::ostream& operator<<(std::ostream& os, const Item* item) {
    os << "ID: " << item->ID.toStdString() << "\n Name: " << item->name.toStdString() << "\n Price: " << item->price;
    return os;
}
