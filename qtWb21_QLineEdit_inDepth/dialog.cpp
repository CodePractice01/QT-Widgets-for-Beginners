#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->chkEnabled->setChecked(ui->txt_test->isEnabled());
    ui->chkReadOnly->setChecked(ui->txt_test->isReadOnly());
    ui->chkClearButton->setChecked(ui->txt_test->isClearButtonEnabled());

    // get metanum
    QMetaEnum metanum = QMetaEnum::fromType<QLineEdit::EchoMode>();


    //how many keys do we gave ?
    for(int i =0; i< metanum.keyCount();i++)
    {
        //for each key -get the value of the key
        ui->cnbEcho->addItem(metanum.valueToKey(i),metanum.value(i) );
    }
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_cnbEcho_currentIndexChanged(int index)
{
    QMetaEnum metanum = QMetaEnum::fromType<QLineEdit::EchoMode>();

    //take the key -  that is a string representation in the combo box
    //convert it to the actual value
    int value = metanum.keyToValue(ui->cnbEcho->currentText().toLocal8Bit().data());

    QLineEdit::EchoMode mode = static_cast<QLineEdit::EchoMode>(value);

    ui->txt_test->setEchoMode(mode);
}


void Dialog::on_txt_default_textChanged(const QString &arg1)
{
    //set he text insert in line edit 1
    ui->txt_test->setText(arg1);
}

void Dialog::on_chkEnabled_toggled(bool checked)
{
    ui->txt_test->setEnabled(checked);
}

void Dialog::on_chkReadOnly_toggled(bool checked)
{
    ui->txt_test->setReadOnly(checked);
}

void Dialog::on_chkClearButton_toggled(bool checked)
{
    ui->txt_test->setClearButtonEnabled(checked);
}

void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this, "Entered","You entered " + ui->txt_test->text());
    accept();
}

