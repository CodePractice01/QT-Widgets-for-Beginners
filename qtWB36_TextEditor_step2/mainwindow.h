#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void selectNone();

    void on_actionToolbar_Top_triggered();

    void on_actionToolbar_Bottom_triggered();

    void on_actionToolbar_Left_triggered();

    void on_actionToolbar_Right_triggered();



    void on_actionToolbar_floatable_toggled(bool arg1);

    void on_actionToolbar_moveble_toggled(bool arg1);

private:
    Ui::MainWindow *ui;

    QString m_filename;
    bool m_saved;

};
#endif // MAINWINDOW_H
