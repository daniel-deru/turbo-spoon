#include "address.h"
#include <iostream>


Address::Address() :
    streetName(""),
    streetNumber(""),
    city(""),
    province(""),
    postCode(""),
    country("")
{}

Address::Address(
    QString& streetName,
    QString& streetNumber,
    QString& city,
    QString& province,
    QString& postCode,
    QString& country
) :
    streetName(streetName),
    streetNumber(streetNumber),
    city(city),
    province(province),
    postCode(postCode),
    country(country)
{}

void Address::print() {
    std::cout << "Street Number: " << streetNumber.toStdString() << std::endl;
    std::cout << "Street Name: " << streetName.toStdString() << std::endl;
    std::cout << "City: " << city.toStdString() << std::endl;
    std::cout << "Province: " << province.toStdString() << std::endl;
    std::cout << "Post Code: " << postCode.toStdString() << std::endl;
    std::cout << "Country: " << country.toStdString() << std::endl;
}
