#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // all call the dialog  slots : void Dialog::append()

    //example, when click button 1 --> emit the click to signal and ( &Dialog::append) call this slot
    //the sender is always the one that emits the signal
    //the slot is the one that consumes that signal
    connect(ui->btnOne, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnTwo, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnThree, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnFour, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnFive, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnSix, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnSever, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnEight, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnNine, &QPushButton::clicked, this, &Dialog::append);
    connect(ui->btnZero, &QPushButton::clicked, this, &Dialog::append);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::append()
{
        QPushButton* btn = qobject_cast<QPushButton*>(sender()); //sender()) identify which button is clicked
        if(!btn) return;

        temp.append(btn->text());
        ui->lblNotify->setText("Typed " +temp);


        if(code.isEmpty())
        {
            ui->btnSave->setEnabled(true);
            ui->btnVerify->setEnabled(false);
        }
        else{
            ui->btnSave->setEnabled(false);
            ui->btnVerify->setEnabled(true);
        }
}

void Dialog::on_btnSave_clicked()
{
    code = temp;
    temp.clear();
    ui->btnSave->setEnabled(false);
    ui->btnVerify->setEnabled(true);

    ui->lblNotify->setText("Code saved, please re-enter the code and click verify");
    QMessageBox::information(this, "Saved" , ui->lblNotify->text() );
}


void Dialog::on_btnVerify_clicked()
{
    if(temp == code){
        QMessageBox::information(this, "code" , "The code match !" );

    }
    else{
         QMessageBox::critical(this, "code" , "The code don't match !" );
    }

    temp.clear();

    ui->lblNotify->setText("Enter the code and click verify");


}

