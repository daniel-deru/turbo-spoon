#include "item.h"

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
    return "ID\t|Name\t|Price\t|";
}

QString Item::displayItem() {
    return (getID() + "\t|" + getName() + "\t|" + QString::number(getPrice()) + "\t|");
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
