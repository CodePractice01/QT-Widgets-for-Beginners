#include "dialog.h"

#include <QApplication>


//exercices --use gri layout
//spacers
//horizontal layout

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
