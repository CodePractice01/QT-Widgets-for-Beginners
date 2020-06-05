#include "dialog.h"

#include <QApplication>

/*
Absolute layouts are an absolute mistake to use
Ther are the exact position on the container and not scale



*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
