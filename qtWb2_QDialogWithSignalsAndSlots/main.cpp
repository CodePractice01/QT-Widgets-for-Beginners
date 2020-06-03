#include "dialog.h"

#include <QApplication>

//Forms-->dialog -- add button and edit signal and slots
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
