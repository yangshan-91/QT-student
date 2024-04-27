#include "dlg_dbconnect.h"
#include "ui_dlg_dbconnect.h"

dlg_dbconnect::dlg_dbconnect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlg_dbconnect)
{
    ui->setupUi(this);
    m_ptrdbcsql = stumgrSQL::getinstance();

}

dlg_dbconnect::~dlg_dbconnect()
{
    delete ui;
}

void dlg_dbconnect::on_btn_login_clicked()
{
    QString struser = ui->le_user->text();
    QString strpassword = ui->le_password->text();
    bool isok = m_ptrdbcsql->init(struser, strpassword);
    if (isok) {
        emit sendDBConnectSuccess();
        this->close();
    }
}


void dlg_dbconnect::on_btn_exit_clicked()
{
    exit(0);
}

