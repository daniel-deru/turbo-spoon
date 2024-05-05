#include "address.h"
#include "commandline.h"
#include <iostream>


Address::Address() :
    street(""),
    city(""),
    province(""),
    country("")
{}

Address::Address(
    QString& street,
    QString& city,
    QString& province,
    QString& country
) :
    street(street),
    city(city),
    province(province),
    country(country)
{}

void Address::print() {
    std::cout << toString().toStdString();
}

QString Address::toString() {
    return QString("%1 %2, %3, %4")
        .arg(
            getStreet(),
            getCity(),
            getProvince(),
            getCountry()
        );
}

QString Address::getAddress() {
    return QString("%1 %2, %3, %4")
        .arg(
            getStreet(),
            getCity(),
            getProvince(),
            getCountry()
        );
}


// Getter methods
const QString& Address::getStreet() const { return street; }
const QString& Address::getCity() const { return city; }
const QString& Address::getProvince() const { return province; }
const QString& Address::getCountry() const { return country; }

// Setter methods
void Address::setStreet(QString& num) { street = num; }
void Address::setCity(QString& c) { city = c; }
void Address::setProvince(QString& p) { province = p; }
void Address::setCountry(QString& c) { country = c; }

std::istream& operator>>(std::istream& is, Address& address) {

    QString street = QCommandLine::input("Street number and name: ");
    QString city = QCommandLine::input("City: ");
    QString province = QCommandLine::input("Province: ");
    QString country = QCommandLine::input("Country: ");

    address.setStreet(street);
    address.setCity(city);
    address.setProvince(province);
    address.setCountry(country);

    return is;
}
