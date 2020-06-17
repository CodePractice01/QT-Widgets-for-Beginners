#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    //call function newDocument

    QMdiSubWindow *editor = newDocument();
    //set the title for 'new window'
    editor->setWindowTitle("New File");
}

void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,"Open File");
    if(path.isEmpty()) return;

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);

    QMdiSubWindow *window = newDocument();
    window->setWindowTitle(path);

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    editor->setPlainText(stream.readAll());

    file.close();

}

void MainWindow::on_actionSave_triggered()
{
    //get the current window
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QString path = window->windowTitle();
    QFile file(path);

    if(!file.exists())
    {
        on_actionSave_As_triggered();
        return;
    }

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    stream << editor->toPlainText();

    file.close();

    window->setWindowTitle(path);
    //show message on saved
    ui->statusbar->showMessage("Saved", 1000);
}

void MainWindow::on_actionSave_As_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QString path = QFileDialog::getSaveFileName(this,"Save File");
    if(path.isEmpty()) return;

    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    stream << editor->toPlainText();

    file.close();

    window->setWindowTitle(path);
    ui->statusbar->showMessage("Saved", 1000);

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionCopy_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->copy();
}

void MainWindow::on_actionCut_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
    if(!window) return;

    QPlainTextEdit *editor = qobject_cast<QPlainTextEdit*>(window->widget());
    if(!editor) return;

    editor->selectAll();
}

void MainWindow::on_actionNext_triggered()
{
    //activateNextSubWindow -- move to next windows
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_actionPrevious_triggered()
{

    //activatePreviousSubWindow -- move to previous windows
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::on_actionCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}


void MainWindow::on_actionTitle_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_actionClose_All_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}


//make a new window
QMdiSubWindow *MainWindow::newDocument()
{
    //add a new subwindow and set the child relashionship
    //when window will be closed- will be destroy the editor
    QMdiSubWindow *window = new QMdiSubWindow(this);
    //set the child of the window
    QPlainTextEdit *editor = new QPlainTextEdit(window);

    //set the widget
    window->setWidget(editor);

    //when user close a specific window ^, it's going automatically delete its own pointer
    window->setAttribute(Qt::WA_DeleteOnClose);


    ui->mdiArea->addSubWindow(window);
    window->show();

    return window;
}






