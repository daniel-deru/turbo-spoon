#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include <QString>

class Item
{
public:

    // constructors
    Item();
    Item(QString& ID, QString& name, float price);

    // methods
    void print();
    std::string toString();
    QString displayHeader();
    QString displayItem();
    static Item createItem();

    // setters
    void setID(QString&);
    void setName(QString&);
    void setPrice(float);

    // getters
    const QString getID();
    const QString getName();
    const float getPrice();

    // overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Item*);

private:
    QString ID;
    QString name;
    float price;
};

#endif // ITEM_H
