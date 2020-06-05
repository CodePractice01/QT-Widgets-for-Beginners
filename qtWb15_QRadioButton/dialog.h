#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

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
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::Dialog *ui;

    //get QBject which will be the parent and go through find the radio buttons and figure out which are selected
    QString getOption(QObject *obj);
};
#endif // DIALOG_H
