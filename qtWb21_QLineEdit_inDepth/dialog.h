#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QMetaEnum>

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
    void on_cnbEcho_currentIndexChanged(int index);

    void on_chkEnabled_toggled(bool checked);

    void on_chkReadOnly_toggled(bool checked);

    void on_chkClearButton_toggled(bool checked);

    void on_buttonBox_accepted();


    void on_txt_default_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
