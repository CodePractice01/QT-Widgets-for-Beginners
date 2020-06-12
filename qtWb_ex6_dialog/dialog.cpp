#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    LoginForm *loginCredentials = new LoginForm(this);
    loginCredentials->exec();

    if(loginCredentials->getUsername() == "user" && loginCredentials->getPassword() == "admin")
    {
        ui->label->setText("Hello youu" + loginCredentials->getUsername());
    }
    else{
        ui->label->setText("Not loggen in");
        QMessageBox::critical(this,"Invalid login", "Wrong username password");
    }

    loginCredentials->deleteLater();

}
