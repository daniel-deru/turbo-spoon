#include "item.h"

#include <iostream>

// Default constructor
Item::Item() {}

Item::Item(QString& ID, QString& name, float price) : ID(ID), name(name), price(price) {}

// Method to print item details
void Item::print() {
    std::cout << "ID: " << ID.toStdString() << "\n Name: " << name.toStdString() << "\n Price: " << price << std::endl;
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
