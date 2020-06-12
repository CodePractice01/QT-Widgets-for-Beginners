#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    ui->txtPass->setEchoMode(QLineEdit::EchoMode::Password);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_buttonBox_accepted()
{
    username = ui->txtUsername->text();
    password = ui->txtPass->text();
    accept();
}

void LoginForm::on_buttonBox_rejected()
{
    reject();
}

QString LoginForm::getPassword() const
{
    return password;
}

QString LoginForm::getUsername() const
{
    return username;
}

