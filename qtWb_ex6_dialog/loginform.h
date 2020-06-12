#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include <QString>


namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

    QString getUsername() const;

    QString getPassword() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::LoginForm *ui;

    QString username;
    QString password;
};

#endif // LOGINFORM_H
