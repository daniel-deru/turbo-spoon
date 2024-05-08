#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

#include <map>
#include <vector>
#include <set>
#include <optional>

#include "storeitem.h"
#include "vendor.h"
#include "commandline.h"

bool setExistingVendor(std::map<std::string, Vendor>& existingVendors, Vendor& vendor);
std::optional<Vendor> findExistingVendor(std::map<std::string, Vendor>& existingVendors);


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    std::vector<StoreItem> storeItems;
    std::map<std::string, Vendor> vendors; // Keep track of vendors to avoid repetition
    std::set<std::string> itemIDs; // Keep track of items to avoid duplicates
    bool halt = false;

    QCommandLine::output("Welcome to the StoreItem Inventory Management System");

    // Start input loop
    do { // while(!halt)
        bool enterItem = QCommandLine::inputYesNo("\n[Y/N] Would you like to enter a new item? ");

        if(enterItem) {

            StoreItem item = StoreItem::createStoreItem(); // User input Change this name

            bool includeVendor = QCommandLine::inputYesNo("[Y/N] Do you want to set the vendor as well? ");

            if(includeVendor) {
                Vendor vendor;

                if(vendors.empty()) {
                    std::cin >> vendor; // Input the vendor fields
                }
                else {
                    bool useExisting = QCommandLine::inputYesNo("[Y/N] Do you want to use an existing vendor? ");

                    if(useExisting) {
                        bool vendorSet = setExistingVendor(vendors, vendor); // Set vendor if found

                        if(!vendorSet) {
                            bool createNewItem = QCommandLine::inputYesNo("[Y/N] Do you want to create a new vendor? ");

                            if(createNewItem) {
                                std::cin >> vendor; // Input the vendor fields
                            }
                        }
                    }
                }

                item.setVendor(vendor);

                vendors[vendor.getID().toStdString()] = vendor;
            }

            storeItems.push_back(item);
            itemIDs.insert(item.getID().toStdString());

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

bool setExistingVendor(std::map<std::string, Vendor>& existingVendors, Vendor& vendor) {
    bool vendorFound = false;
    int tries = 3;

    do {
        QString vendorID = QCommandLine::input("[Y/N] Enter vendor ID: ");

        std::map<std::string, Vendor>::iterator iterator = existingVendors.find(vendorID.toStdString());

        if(iterator != existingVendors.end()) {
            vendor = iterator->second;
            vendorFound = true;
        }
        else {
            QCommandLine::output("Vendor Not Found.");
            tries--;
        }

    } while(!vendorFound || tries > 0);

    if(!vendorFound) {
       QCommandLine::output("Too many tries! Exiting vendor search.");
    }

    return vendorFound;
}
