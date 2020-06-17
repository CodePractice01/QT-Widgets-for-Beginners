#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("Brasov Dreams");
    a.setOrganizationDomain("http://www.believeinyourdreams.com");
    a.setApplicationName("Qt App");
    a.setApplicationDisplayName("QtTutorial ApP");
    a.setApplicationVersion("0.1.1 Beta");

    MainWindow w;
    w.show();
    return a.exec();
}
