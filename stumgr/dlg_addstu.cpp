#include "dlg_addstu.h"
#include "ui_dlg_addstu.h"

Dlg_AddStu::Dlg_AddStu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dlg_AddStu)
{
    ui->setupUi(this);
}

Dlg_AddStu::~Dlg_AddStu()
{
    delete ui;
}

void Dlg_AddStu::updateStu(StuInfo info)
{
    if (!isAddOrUpdate)
        ui->le_stuid->setEnabled(false);
    ui->le_stuid->setText(QString::number(info.studentid));
    ui->le_stugrade->setText(QString::number(info.grade));
    ui->le_stuclass->setText(QString::number(info.sclass));
    ui->sb_age->setValue(info.age);
    ui->le_stuname->setText(info.sname);
    ui->le_stuphone->setText(info.phonenumber);
    this->exec();
}

void Dlg_AddStu::addStu()
{
    if (isAddOrUpdate)
        ui->le_stuid->setEnabled(true);
    ui->le_stuid->clear();
    ui->le_stuclass->clear();
    ui->le_stugrade->clear();
    ui->le_stuname->clear();
    ui->le_stuphone->clear();
    ui->sb_age->clear();
    this->exec();
}

void Dlg_AddStu::setAOUType(bool AddOrUpdate)
{
    isAddOrUpdate = AddOrUpdate;
}

void Dlg_AddStu::on_btn_cancel_clicked()
{
    this->close();
}

void Dlg_AddStu::on_btn_save_clicked()
{
    StuInfo info;

    auto ptr = stumgrSQL::getinstance();
    info.studentid = ui->le_stuid->text().toInt();
    info.sname = ui->le_stuname->text();
    info.age = ui->sb_age->text().toInt();
    info.grade = ui->le_stugrade->text().toInt();
    info.sclass = ui->le_stuclass->text().toInt();
    info.phonenumber = ui->le_stuphone->text();
    bool isok;
    if (isAddOrUpdate) {
        isok = ptr->addStu(info);
    } else {
        isok = ptr->updateStu(info);
    }

    if (isok) {
        QMessageBox::information(this, "Success", "成功");
    } else {
        QMessageBox::information(this, "Failed", "失败");
    }
    this->close();
}
