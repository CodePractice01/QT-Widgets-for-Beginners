#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->scrollArea);

    //set style

    //http://doc.qt.io/archieves/qt-4-6/qstyle.html
    ui->actionOpen->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionZoom_In->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowUp));
    ui->actionZom_Out->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowDown));


    m_lblImage = new QLabel(this);
    ui->scrollArea->setWidget(m_lblImage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{

    m_path = QFileDialog::getOpenFileName(this, "Open", QString(), "All files(*.*);;JPG(*.jpg);;PNG(*.png)");

    if(m_path.isEmpty()) return;


    if(!m_img.load(m_path))
    {
        QMessageBox::critical(this, "Error", "Could not load the image");
        return;
    }


    m_lblImage->setPixmap(m_img);


}

void MainWindow::on_actionZoom_In_triggered()
{

    int w = m_lblImage->width();
    int h =  m_lblImage->height();

    w += 10;
    h += 10;

    //when resize the label
    m_lblImage->resize(w,h);
    //resize the pix map that goes into that label
    m_lblImage->setPixmap(m_img.scaled(w,h));


}

void MainWindow::on_actionZom_Out_triggered()
{


    int w = m_lblImage->width();
    int h =  m_lblImage->height();

    w -= 10;
    h -= 10;

        if(w<10) w=10;
        if( h <10 ) h=10;
    //when resize the label
    m_lblImage->resize(w,h);
    //resize the pix map that goes into that label
    m_lblImage->setPixmap(m_img.scaled(w,h));

}















