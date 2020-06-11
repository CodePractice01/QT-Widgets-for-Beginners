#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_accepted()
{
    accept();
}

void Dialog::on_listWidget_itemSelectionChanged()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    ui->lblName->setText(item->text());
    ui->lblImage->setPixmap(item->icon().pixmap(32,32));
}

void Dialog::load()
{

    //scan directori
    QDir dir(":/");
    scan(dir.entryInfoList());

}

void Dialog::scan(QFileInfoList list)
{
    foreach (QFileInfo info, list) {
        qInfo() << info.absoluteFilePath();

        //if entity is directory
        if(info.isDir())
        {
            //the recall the scan
            QDir dir(info.absoluteFilePath());
            scan(dir.entryInfoList());
        }
        else {
            QListWidgetItem *itm = new QListWidgetItem(ui->listWidget);
            itm->setText(info.absoluteFilePath());
            itm->setIcon(QIcon(info.absoluteFilePath()));

            ui->listWidget->addItem(itm);
        }
    }

}
