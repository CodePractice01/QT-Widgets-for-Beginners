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


void Dialog::on_btnOk_clicked()
{
    QString toppings;

    //this =Dialog
    QObjectList boxes = this->children();

    foreach (QObject* obj, boxes) {

        //if each child inheritance the Q checkbox
       if(obj->inherits("QCheckbox"))
       {
           // going to cast that and get the actual object so we can see if have the pointer
           QCheckBox* box = qobject_cast<QCheckBox*>(obj);

           if(box && box->isChecked())
           {
               toppings += box->text() + "\r\n";
          qInfo() <<toppings;
           }

       }
    }

    QMessageBox::information(this, "Toppings", "Toppings to include\r\n" + toppings);
    accept();
}
