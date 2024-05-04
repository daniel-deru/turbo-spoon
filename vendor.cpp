#include "vendor.h"
#include "address.h"

// Default constructor
Vendor::Vendor() : ID(""), name(""), address(Address()) {}

Vendor::Vendor(QString& ID, QString& name, Address& address) : ID(ID), name(name), address(address) {}

void Vendor::toString() {
    std::cout << "ID: " << ID.toStdString() << "\n Name: " << name.toStdString() << "\n Address: \n";
    address.print();
}

/* ---------- Setters ---------- */

void Vendor::setID(QString& id) {
    ID = id;
}

void Vendor::setName(QString& name) {
    name = name;
}

void Vendor::setAddress(Address& address) {
    address = address;
}

/* ---------- getters ---------- */

const QString Vendor::getID() {
    return ID;
}

const QString Vendor::getName() {
    return name;
}

const Address Vendor::getAddress() {
    return address;
}

std::ostream& operator<<(std::ostream& os, const Vendor* vendor) {
    os << "ID: " << vendor->ID.toStdString() << "\n Name: " << vendor->name.toStdString() << "\n Address: ";
    os << &(vendor->address);
    return os;
}
