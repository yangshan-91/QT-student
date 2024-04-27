#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QStringConverter>
#include <QMainWindow>
#include "page_login.h"
#include <QKeyEvent>
#include <QFile>
#include <QCoreApplication>
#include "stumgrsql.h"
#include <QRandomGenerator>
#include "dlg_addstu.h"
#include "dlg_adduser.h"
#include "dlg_dbconnect.h"
#include "stu_mainpage.h"
#include "dlg_addtc.h"
#include "dlg_addscore.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void receiveLoginSuccess(); //登录成功的槽函数
    void receiveDBCSuccess();//数据库连接成功的槽函数
    void receiveStuPageExit();
    //virtual void keyPressEvent(QKeyEvent *event); //刷新皮肤
    //读取模拟数据的名字
    void nameFileRead();
    //更新学生表
    void updateStuTable();
    //更新用户表
    void updateUserTable();
    //更新教师表
    void updateTcTable();
    //更新成绩表
    void updateScoreTable();
private slots:
    //退出按钮按下的函数
    void on_btn_exit_clicked();
    //模拟数据按钮
    void on_btn_simdata_clicked();
    //添加按钮
    void on_bt_add_clicked();
    //刷新按钮
    void on_btn_refresh_clicked();
    //清空表按钮
    void on_btn_cleartable_clicked();
    //删除按钮
    void on_bt_delete_clicked();
    //修改按钮
    void on_bt_change_clicked();

    void on_btn_search_clicked();


    void on_btn_stuinfomgr_clicked();

    void on_btn_userinfomgr_clicked();

    void on_btn_teainfomgr_clicked();

    void on_btn_scoreinfomgr_clicked();

private:
    Ui::MainWindow *ui;
    Page_Login m_dlgLogin;
    stumgrSQL *m_ptrStuSql;
    QStringList m_lnames;
    Dlg_AddStu m_dlgAddStu;
    dlg_AddUser m_dlgAddUser;
    quint8 curTable;
    dlg_dbconnect m_dlgdbconnect;
    Stu_mainpage m_pagestu;
    Dlg_AddTc m_dlgAddTc;
    dlg_addscore m_dlgAddSc;
};
#endif // MAINWINDOW_H
