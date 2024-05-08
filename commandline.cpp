#include "commandline.h"

#include <string>
#include <iostream>

#include <QTextStream>

QCommandLine::QCommandLine() {}

QString QCommandLine::input(std::string message) {

    std::string tempStr;

    std::cout << message;
    std::getline(std::cin, tempStr);

    return QString::fromStdString(tempStr);
}

void QCommandLine::output(std::string message) {
    std::cout << message << std::endl;
}

bool QCommandLine::inputYesNo(std::string message) {
    QString result = QCommandLine::input(message);
    return result.startsWith("Y", Qt::CaseInsensitive);
}
