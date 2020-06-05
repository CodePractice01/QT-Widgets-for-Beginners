#include "dialog.h"

#include <QApplication>

//Form LAyouts ---  used "Lay Out in a Form Layout" -- check on design form--dialoh.ui
//Form layout can have some unpredictable results based off what you're expected to see on the screen
//for simple form it can be easy to build but...maybe it's ok to avoid

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
