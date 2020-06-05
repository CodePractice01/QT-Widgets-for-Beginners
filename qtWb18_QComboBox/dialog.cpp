#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
    load();

}

Dialog::~Dialog()
{
    delete ui;
}





void Dialog::on_comboBox_currentIndexChanged(int index)
{
    ui->labelSelected->setText(QString::number(index) + " = " + ui->comboBox->currentText());

}

void Dialog::on_btnSave_clicked()
{
    QSettings settings;
    //current index of the combobox
    settings.setValue("Settings ", ui->comboBox->currentIndex());

    QMessageBox::information(this, "saved", "Selection saved, please close and re-open the appplication");
}

void Dialog::init()
{
    //clear combobox
        ui->comboBox->clear();

        for(int i =0; i<10;i++)
        {
            //add value to combobox
            ui->comboBox->addItem("item number" + QString::number(i));
        }
}

void Dialog::load()
{
    QSettings settings;

    QVariant value =settings.value("settings",0);

    //convert variant into the value
    bool ok;
    int index = value.toInt(&ok);

    if(!ok)
    {
        QMessageBox::critical(this,"Not ok man" , "loading error");
        return;
    }
    if(index < ui->comboBox->count())
    {
        ui->comboBox->setCurrentIndex(index);
    }
    else{
        ui->comboBox->setCurrentText(0);
    }

}



















