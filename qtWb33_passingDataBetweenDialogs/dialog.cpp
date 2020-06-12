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


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this, "Selected","You have selected: \r\n" + ui->lineEdit->text());
    accept();
}

void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::on_pushButton_clicked()
{
    Selections *dialog = new Selections(this);

    //set the default
    dialog->setSelected(ui->lineEdit->text());

    //exec(show on screen) the dialog
    dialog->exec();

    //Read back the new selections
    ui->lineEdit->setText(dialog->selected());


}
