#include "dlg_addscore.h"
#include "ui_dlg_addscore.h"

dlg_addscore::dlg_addscore(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dlg_addscore)
{
    ui->setupUi(this);
}

dlg_addscore::~dlg_addscore()
{
    delete ui;
}

void dlg_addscore::updateScore(ScoreInfo info)
{
    if (!isAddOrUpdate) {
        ui->le_courseid->setEnabled(false);
        ui->le_stuid->setEnabled(false);
    }
    ui->le_stuid->setText(QString::number(info.studentid));
    ui->le_courseid->setText(QString::number(info.courseid));
    ui->le_score->setText(QString::number(info.score));
    UPINFO = info;
    this->exec();
}

void dlg_addscore::addScore()
{
    if (isAddOrUpdate) {
        ui->le_stuid->setEnabled(true);
        ui->le_courseid->setEnabled(true);
    }
    ui->le_stuid->clear();
    ui->le_courseid->clear();
    ui->le_score->clear();
    this->exec();
}

void dlg_addscore::setAOUType(bool AddOrUpdate)
{
    isAddOrUpdate = AddOrUpdate;
}

void dlg_addscore::on_btn_save_clicked()
{
    ScoreInfo info;
    auto ptr = stumgrSQL::getinstance();
    info = UPINFO;
    info.score = ui->le_score->text().toInt();
    info.courseid = ui->le_courseid->text().toInt();
    info.studentid = ui->le_stuid->text().toInt();
    info.coursename = ptr->getCourseName(info.courseid);
    bool isok;
    if (isAddOrUpdate) {
        isok = ptr->addScore(info);
    } else {
        isok = ptr->updateScore(info);
    }
    if (isok) {
        QMessageBox::information(this, "Success", "成功");
    } else {
        QMessageBox::information(this, "Failed", "失败");
    }
    this->close();
}

void dlg_addscore::on_btn_exit_clicked()
{
    this->close();
}
