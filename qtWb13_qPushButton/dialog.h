#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


#include <QMessageBox>
#include <QString>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnCheck_clicked();

    void on_btnAutoRepeat_clicked();

    void on_btnDefault_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_btnToggleDefault_clicked();

    void on_btnQuit_clicked();

    void on_btnISChecked_clicked();

    void on_tnToggleAutorepeat_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
