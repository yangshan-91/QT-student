#include "page_login.h"
#include "ui_page_login.h"

Page_Login::Page_Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page_Login)
{
    ui->setupUi(this);
}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_login_clicked()
{
    //数据库查找用户名和密码与输入是否匹配
    QString struser = ui->line_username->text();
    QString strpassword = ui->line_password->text();
    //失败提示
    auto dbptr = stumgrSQL::getinstance();
    QString  userauth = dbptr->loginCheck(struser, strpassword);
    if (userauth == "false") {
        QMessageBox::information(NULL, "info", "用户名或密码错误");
        return;
    } else {
        //成功则进入主界面
        //emit发射信号emit是Qt关键字，像其他关Qt扩展一样，它也会被C++预处理器转换成标准的C++代码。
        curUser.username = struser;
        curUser.password = strpassword;
        curUser.auth = userauth;
        emit sendLoginSuccess();
        this->close();
    }
}

void Page_Login::on_btn_exit_clicked()
{
    //退出程序
    exit(0);
}
