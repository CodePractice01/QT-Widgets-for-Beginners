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

    QString iceCream = getOption(ui->grpIcecream);
    QString toppings = getOption(ui->grpToppings);
    QString syrup = getOption(ui->grpSyrup);
    QString size = getOption(ui->grpSize);

    QString order;
    order +="Order: \r\n";
    order +="Size: " +size+ "\r\n";
    order +="Flavor: " +iceCream+ "\r\n";
    order +="Toppings: " +toppings+ "\r\n";
    order +="Syrup: " +syrup+ "\r\n";

    QMessageBox::information(this,"Order ", order);

    accept();
}

void Dialog::on_btnCancel_clicked()
{
    QMessageBox::critical(this, "What!!", " You do not iceCream ?");
    reject();
}

QString Dialog::getOption(QObject *obj)
{
    QString value = "None";

    //get a list of pointers
    //findChildren --automatically cast
    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);

    foreach (QRadioButton* rdo, lst) {
       if(rdo->isChecked())
       {
           value = rdo->text();
           break;
       }
    }

    return value;
}
