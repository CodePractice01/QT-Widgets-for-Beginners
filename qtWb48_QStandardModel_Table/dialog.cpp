#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();

}

Dialog::~Dialog()
{
    delete ui;
}

//slot
void Dialog::itemSchanged(QStandardItem *item)
{
    qInfo() << "Index: " << item->index().row()<< ", " << item->index().column() << "=" << item->text();

}

void Dialog::init()
{
    //make a table with 4rows and 4 columns
    //insert rows: start with position 0, and insert 4 rows
    model.insertRows(0,4);
    model.insertColumns(0,4);

    for(int r=0;r<model.rowCount() ;++r)
    {
        for(int c=0; c<model.columnCount() ; ++c)
        {
            //filled with data
            QStandardItem *item = new QStandardItem(QString("row %0, col %1").arg(r).arg(c));

            model.setItem(r,c,item);
        }

    }
    //display the model in view
    ui->tableView->setModel(&model);
    connect(&model, &QStandardItemModel::itemChanged, this, &Dialog::itemSchanged);
}

