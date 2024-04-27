#include "stu_mainpage.h"
#include "ui_stu_mainpage.h"

void Stu_mainpage::updatePageInfo()
{
    ui->lb_stuname->setText("姓名:" + loginstu.sname);
    ui->lb_stuage->setText("年龄:" + QString::number(loginstu.age));
    ui->lb_stugrade->setText("年级:" + QString::number(loginstu.grade));
    ui->lb_stuclass->setText("班级:" + QString::number(loginstu.sclass));
    ui->lb_stuid->setText("学号:" + QString::number(loginstu.studentid));
    ui->lb_stuphone->setText("电话:" + loginstu.phonenumber);
    ui->lb_name->setText(loginstu.sname);
}

Stu_mainpage::Stu_mainpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Stu_mainpage)
{
    ui->setupUi(this);
}

Stu_mainpage::~Stu_mainpage()
{
    delete ui;
}

void Stu_mainpage::on_btn_exit_clicked()
{
    emit StuPageExit();
    this->close();
}

void Stu_mainpage::on_btn_classinfo_clicked()
{
    ui->tableWidget->clearContents();
    QStringList headTable = {
        "课程号",
        "课程名",
        "老师名",
    };
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headTable);
    //点击选中行且不可直接编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //自动拉伸列
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    auto dbptr = stumgrSQL::getinstance();
    QList<CourseInfo> lCourses = dbptr->getAllCourse();
    auto cnt = lCourses.length();
    ui->tableWidget->setRowCount(cnt);
    for (int i = 0; i < cnt; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(lCourses[i].courseid)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(lCourses[i].coursename));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(lCourses[i].teachername));
    }
}

void Stu_mainpage::on_btn_scoreinfo_clicked()
{
    ui->tableWidget->clearContents();
    QStringList headTable = {
        "课程号",
        "课程名",
        "分数",
    };
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headTable);
    //点击选中行且不可直接编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //自动拉伸列
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    auto dbptr = stumgrSQL::getinstance();
    QList<ScoreInfo> lScore = dbptr->getStuScore(loginstu.studentid);
    auto cnt = lScore.length();
    ui->tableWidget->setRowCount(cnt);
    for (int i = 0; i < cnt; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(lScore[i].courseid)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(lScore[i].coursename));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(lScore[i].score)));
    }
}

