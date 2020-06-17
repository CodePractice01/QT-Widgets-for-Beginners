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

void Dialog::on_buttonBox_accepted()
{

}

void Dialog::hrClicked()
{
    QMessageBox::information(this, "HR", "You sent the info to HR");
}

void Dialog::legalClicked()
{
     QMessageBox::information(this, "HR", "You sent the info to legal");
}

void Dialog::nextClicked()
{
    int tab = ui->tabWidget->currentIndex();

    //count() gives total number of tabs = 3
    int max = ui->tabWidget->count() - 1;

    tab++;

    if(tab > max) tab = max;
    ui->tabWidget->setCurrentIndex(tab);
}

void Dialog::backClicked()
{

    int tab = ui->tabWidget->currentIndex();

    int min=0;

    tab--;

    if(tab<min) tab = min;
    ui->tabWidget->setCurrentIndex(tab);

}


void Dialog::init()
{
    QPushButton *btnBack = new QPushButton("Back" ,this);
    QPushButton *btnNext = new QPushButton("Next" ,this);


    connect(btnBack, &QPushButton::clicked, this, &Dialog::backClicked);
    connect(btnNext, &QPushButton::clicked, this, &Dialog::nextClicked);

    ui->buttonBox->addButton(btnBack,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);


    //update the tabs
    ui->tabWidget->setTabText(0, "Profile");
    ui->tabWidget->setTabText(1, "Notes");

    //Add tab

    QWidget *widget = new QWidget(this);
    //add new tab
    ui->tabWidget->addTab(widget, "Send");
    //create new QPushButtons
    QPushButton *btnHr = new QPushButton("Send to Human Resources" , this);
    QPushButton *btnLegal = new QPushButton("send to LEgal", this);


    //connect buttons
    connect(btnHr, &QPushButton::clicked,this, &Dialog::hrClicked);
    connect(btnLegal, &QPushButton::clicked,this, &Dialog::legalClicked);

    //create layout for btns hr and legal
    QVBoxLayout *layout = new QVBoxLayout(widget);
     //put btn HR and btn legal in tab named "Send"
    layout->addWidget(btnHr);
    layout->addWidget(btnLegal);

    widget->setLayout(layout);



}



