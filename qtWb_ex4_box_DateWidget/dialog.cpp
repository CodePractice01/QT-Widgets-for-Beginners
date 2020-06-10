#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    QString message ;
    message.append("Employee info:");
    message.append("Name: " + ui->lineEdit_name->text() + "\r\n");
    message.append("title " + ui->lineEdit_title->text() + "\r\n");
    message.append("Date " + ui->dateEdit->text() +"\r\n");
    QMessageBox::information(this, "info", message);

}
