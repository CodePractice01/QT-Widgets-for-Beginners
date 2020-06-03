#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //when click--> do stuff
    connect(ui->btnConnect, &QPushButton::clicked, this, &Dialog::doStuff);
    //(this object, this signal, connect to this, object slot)

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::doStuff()
{
    qInfo() << "Clicked " << QDateTime::currentDateTime().toString();
    accept(); // will close the form !

}


void Dialog::on_btnEditor_clicked()
{
    qDebug() << "EXTRA STUFF !!" ;
    doStuff();
}
