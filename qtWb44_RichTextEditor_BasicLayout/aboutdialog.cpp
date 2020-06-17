#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{

    //This always goes first !!
    ui->setupUi(this);

    ui->lblName->setText(QApplication::applicationName());
    ui->lblVersion->setText(QApplication::applicationVersion());
    ui->lblCompany->setText(QApplication::organizationName());
    ui->lburl-> setText(QApplication::organizationDomain());


}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    accept();
}
