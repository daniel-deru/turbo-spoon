#ifndef QCOMMANDLINE_H
#define QCOMMANDLINE_H

#include <string>

#include <QString>

class QCommandLine
{
public:
    QCommandLine();

    static QString input(std::string message);
    static void output(std::string message);
};

#endif // COMMANDLINE_H
