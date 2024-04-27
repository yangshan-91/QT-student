#ifndef PAGE_LOGIN_H
#define PAGE_LOGIN_H

#include <QWidget>
#include "stumgrsql.h"
#include <QMessageBox>
namespace Ui {
class Page_Login;
}

class Page_Login : public QWidget
{
    Q_OBJECT

public:
    UserInfo curUser;
    explicit Page_Login(QWidget *parent = nullptr);
    ~Page_Login();
//槽（Slot）就是对信号响应的函数。槽就是一个函数
private slots:
    void on_btn_login_clicked();

    void on_btn_exit_clicked();
//信号（Signal）就是在特定情况下被发射的事件
signals:
    void sendLoginSuccess();
private:
    Ui::Page_Login *ui;

};

#endif // PAGE_LOGIN_H
