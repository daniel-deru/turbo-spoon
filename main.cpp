#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

#include "address.h"
#include "item.h"
#include "storeitem.h"
#include "vendor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream inputStream(stdin);
    QTextStream outputStream(stdout);

    int itemCount;

    bool ok = false;

    do {
        outputStream << "How many items do you want to add: ";
        outputStream.flush();

        itemCount = inputStream.readLine().toInt(&ok);

        if(!ok)
        {
            outputStream << "Please enter an integer\n";
            outputStream.flush();
        }

    } while (!ok);

    for(int i = 0; i < itemCount; i++)
    {
        outputStream << "Item " << i+1 << "\n";
        outputStream.flush();
    }



    return a.exec();
}
