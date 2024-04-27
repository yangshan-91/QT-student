#include "dlg_adduser.h"
#include "ui_dlg_adduser.h"

dlg_AddUser::dlg_AddUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dlg_AddUser)
{
    ui->setupUi(this);
}

dlg_AddUser::~dlg_AddUser()
{
    delete ui;
}

void dlg_AddUser::setAOUType(bool AddOrUpdate)
{
    isAddOrUpdate = AddOrUpdate;
}

void dlg_AddUser::addUser()
{
    if (isAddOrUpdate)
        ui->le_username->setEnabled(true);
    ui->le_username->clear();
    ui->le_password->clear();
    ui->cb_auth->setCurrentIndex(0);
    this->exec();
}

void dlg_AddUser::updateUser(UserInfo info)
{
    if (!isAddOrUpdate)
        ui->le_username->setEnabled(false);
    ui->le_username->setText(info.username);
    ui->le_password->setText(info.password);
    ui->cb_auth->setCurrentText(info.auth);
    this->exec();
}

void dlg_AddUser::on_btn_save_clicked()
{
    UserInfo info;

    auto ptr = stumgrSQL::getinstance();
    info.username = ui->le_username->text();
    info.password = ui->le_password->text();
    info.auth = ui->cb_auth->currentText();
    bool isok;
    if (isAddOrUpdate) {
        isok = ptr->addUser(info);
    } else {
        isok = ptr->updateUser(info);
    }

    if (isok) {
        QMessageBox::information(this, "Success", "成功");
    } else {
        QMessageBox::information(this, "Failed", "失败");
    }
    this->close();
}

void dlg_AddUser::on_btn_cancel_clicked()
{
    this->close();
}
