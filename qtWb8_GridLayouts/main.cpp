#include "dialog.h"

#include <QApplication>

//Grid layouts
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
