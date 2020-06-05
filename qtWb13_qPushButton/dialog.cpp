#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->btnCheck->setChecked(true);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnCheck_clicked()
{
    qDebug() << "Checked: " << ui->btnCheck->isChecked();
}

void Dialog::on_btnAutoRepeat_clicked()
{
    qInfo() << "Clicked";
}

void Dialog::on_btnDefault_clicked()
{
    qInfo() << "Default button clicked";

}


void Dialog::on_btnQuit_clicked()
{
    accept();
}

void Dialog::on_btnISChecked_clicked()
{
    QString message;


    if(ui->btnCheck->isChecked())
    {
        //if btn chackable is checked the messages 'yes ' appears
        message="Yes it is checked ";

    } else{

        message= " No it is not checked";
    }

    QMessageBox::information(this, "Checked title", message);
}

void Dialog::on_tnToggleAutorepeat_clicked()
{
    bool value = ui->btnAutoRepeat->autoRepeat();

    ui->btnAutoRepeat->setAutoRepeat(value);

    qDebug() << "Repeat " <<ui->btnAutoRepeat->autoRepeat();
}

void Dialog::on_btnToggleDefault_clicked()
{
    bool value = ui->btnDefault->isDefault();

    ui->btnDefault->setDefault(value);
    qDebug() << "Repeat default>> " << ui->btnDefault->isDefault();

}

