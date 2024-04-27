#include "dlg_addtc.h"
#include "ui_dlg_addtc.h"

Dlg_AddTc::Dlg_AddTc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddTc)
{
    ui->setupUi(this);
}

Dlg_AddTc::~Dlg_AddTc()
{
    delete ui;
}

void Dlg_AddTc::setAOUType(bool AddOrUpdate)
{
    isAddOrUpdate = AddOrUpdate;
}

void Dlg_AddTc::addTeacher()
{
    if (isAddOrUpdate)
        ui->le_tcid->setEnabled(true);
    ui->le_tcid->clear();
    ui->le_tcname->clear();
    ui->sb_age->clear();
    this->exec();
}

void Dlg_AddTc::updateTeacher(TeacherInfo info)
{
    if (!isAddOrUpdate)
        ui->le_tcid->setEnabled(false);
    ui->le_tcid->setText(QString::number(info.teacherid));
    ui->le_tcname->setText(info.name);
    ui->sb_age->setValue(info.age);
    this->exec();
}

void Dlg_AddTc::on_btn_cancel_clicked()
{
    this->close();
}


void Dlg_AddTc::on_btn_save_clicked()
{
    TeacherInfo info;

    auto ptr = stumgrSQL::getinstance();
    info.teacherid = ui->le_tcid->text().toInt();
    info.name = ui->le_tcname->text();
    info.age = ui->sb_age->value();
    bool isok;
    if (isAddOrUpdate) {
        isok = ptr->addTeacher(info);
    } else {
        isok = ptr->updateTeacher(info);
    }

    if (isok) {
        QMessageBox::information(this, "Success", "成功");
    } else {
        QMessageBox::information(this, "Failed", "失败");
    }
    this->close();
}

