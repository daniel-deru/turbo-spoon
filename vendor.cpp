#include "vendor.h"
#include "address.h"
#include "commandline.h"

// Default constructor
Vendor::Vendor() : ID(""), name(""), address(Address()) {}

Vendor::Vendor(QString& ID, QString& name, Address& address) : ID(ID), name(name), address(address) {}

std::string Vendor::toString() {

    QString vendorDetails = QString("ID: %1\nName: %2\nAddress: \n%3");
    vendorDetails = vendorDetails.arg(ID, name, address.toString());
    return vendorDetails.toStdString();
}

QString Vendor::displayHeader() {
    QString nameHeader = QString("Vendor Name").leftJustified(getName().length());
    QString addressHeader = QString("Vender Address").leftJustified(getAddress().toString().length());

    return QString("%1\t|%2\t|").arg(nameHeader, addressHeader);
}

QString Vendor::displayVendor() {
    return getName() + "\t|" + getAddress().toString() + "\t|";
}

/* ---------- Setters ---------- */

void Vendor::setID(QString& id) {
    ID = id;
}

void Vendor::setName(QString& name) {
    this->name = name;
}

void Vendor::setAddress(Address& address) {
    this->address = address;
}

/* ---------- getters ---------- */

const QString Vendor::getID() {
    return ID;
}

const QString Vendor::getName() {
    return name;
}

Address Vendor::getAddress() {
    return address;
}

std::ostream& operator<<(std::ostream& os, const Vendor* vendor) {
    os << "ID: " << vendor->ID.toStdString() << "\n Name: " << vendor->name.toStdString() << "\n Address: ";
    os << &(vendor->address);
    return os;
}

std::istream& operator>>(std::istream& is, Vendor& vendor) {

    Address address;

    QString ID = QCommandLine::input("Vendor ID: ");
    QString name = QCommandLine::input("Vendor Name: ");
    std::cin >> address;

    vendor.setID(ID);
    vendor.setName(name);
    vendor.setAddress(address);

    return is;
}
