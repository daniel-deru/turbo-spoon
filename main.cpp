#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

#include <map>
#include <vector>
#include <set>

#include "storeitem.h"
#include "vendor.h"
#include "commandline.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    int itemCount;

    std::vector<StoreItem> storeItems;
    std::map<std::string, Vendor> vendors; // Keep track of vendors to avoid repetition
    std::set<std::string> itemIDs; // Keep track of items to avoid duplicates
    bool halt = false;

    QCommandLine::output("Welcome to the StoreItem Inventory Management System");

    // Start input loop
    do {
        QString enterItem = QCommandLine::input("\n[Y/N] Would you like to enter a new item? ");

        if(enterItem.startsWith("Y", Qt::CaseInsensitive)) {

            QString itemID = QCommandLine::input("Enter Item ID: ");
            QString itemName = QCommandLine::input("Enter Item Name: ");
            float itemPrice = QCommandLine::input("Enter Item Price: ").toFloat();

            StoreItem item(itemID, itemName, itemPrice);

            QString includeVendor = QCommandLine::input("[Y/N] Do you want to set the vendor as well? ");

            Vendor vendor;

            if(includeVendor.startsWith("Y", Qt::CaseInsensitive)) {

                if(!vendors.empty()) {
                    QString useExisting = QCommandLine::input("[Y/N] Do you want to use an existing vendor? ");

                    if(useExisting.startsWith("Y", Qt::CaseInsensitive)) {
                        QString vendorID = QCommandLine::input("[Y/N] Enter vendor ID: ");

                        std::map<std::string, Vendor>::iterator iterator = vendors.find(vendorID.toStdString());

                        vendor = iterator->second;
                    }
                }
                else {
                    std::cin >> vendor; // Input the vendor fields
                }

                item.setVendor(vendor);

                vendors[vendor.getID().toStdString()] = vendor;
            }

            storeItems.push_back(item);
            itemIDs.insert(itemID.toStdString());

        } else {
            halt = true;
        }

    } while (!halt);

    // display store items with vendor details
    std::cout << "\nAll Items including vendors\n" << std::endl;

    for(StoreItem item : storeItems) {
        std::cout << item.toString(true).toStdString() << "\n" << std::endl;
    }

    // display store items without vendor details
    std::cout << "\nAll Items excluding vendors\n" << std::endl;

    for(StoreItem item: storeItems) {
        std::cout << item.toString().toStdString() << "\n" << std::endl;
    }

    return app.exec();
}
