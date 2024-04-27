#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_ptrStuSql(nullptr)
{
    ui->setupUi(this);
    QFile f;
    f.setFileName(":/resources/stuqss.css");
    f.open(QIODevice::ReadOnly);
    QString strqss = f.readAll();
    f.close();
    this->setStyleSheet(strqss);
    m_dlgLogin.setStyleSheet(strqss);
    m_dlgAddStu.setStyleSheet(strqss);
    m_dlgAddUser.setStyleSheet(strqss);
    m_dlgdbconnect.setStyleSheet(strqss);
    m_pagestu.setStyleSheet(strqss);
    m_dlgAddTc.setStyleSheet(strqss);
    m_dlgAddSc.setStyleSheet(strqss);
    m_dlgdbconnect.show();
    //m_dlgAddSc.show();
    //m_dlgLogin.show(); //显示login界面
    //信号与槽之间的关联：是用 QObject::connect() 函数实现的，其基本格式是：

    //QObject::connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));

    //信号发出者，处理的信号， 信号接收者，处理动作方法（槽函数）。
    connect(&m_dlgLogin, &Page_Login::sendLoginSuccess, this, &MainWindow::receiveLoginSuccess);
    connect(&m_dlgdbconnect,
            &dlg_dbconnect::sendDBConnectSuccess,
            this,
            &MainWindow::receiveDBCSuccess);
    connect(&m_pagestu, &Stu_mainpage::StuPageExit, this, &MainWindow::receiveStuPageExit);
    m_ptrStuSql = stumgrSQL::getinstance();
    //m_ptrStuSql->init();
    nameFileRead(); //读取模拟数据的文件

    //先显示所有的学生
    //updateTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveLoginSuccess()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    QStringList headTable = {};
    ui->tableWidget->setHorizontalHeaderLabels(headTable);
    ui->lb_name->setText(m_dlgLogin.curUser.username);
    if (m_dlgLogin.curUser.auth == "admin"
        || m_dlgLogin.curUser.auth == "teacher") //老师管理员打开信息管理界面
        this->show();
    else { //学生打开学生主页界面
        StuInfo info = m_ptrStuSql->searchStuId(m_dlgLogin.curUser.username.toInt());
        {
            if (info.studentid == -1) {
                QMessageBox::information(this, "info", "学生列表查无此人，请先添加该学生信息");
                return;
            }
        }
        m_pagestu.loginstu = info;
        m_pagestu.updatePageInfo();
        m_pagestu.show();
    }
}

void MainWindow::receiveDBCSuccess()
{
    m_dlgLogin.show();
}

void MainWindow::receiveStuPageExit()
{
    m_dlgLogin.show();
}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_F6) {
//        QFile f;
//        auto str = QCoreApplication::applicationDirPath();
//        f.setFileName(str + "//" + "stuqss.css");
//        f.open(QIODevice::ReadOnly);
//        QString strqss = f.readAll();
//        this->setStyleSheet(strqss);
//        m_dlgLogin.setStyleSheet(strqss);
//        m_dlgAddStu.setStyleSheet(strqss);
//    }
//}

void MainWindow::on_btn_exit_clicked()
{
    this->close();
    m_dlgLogin.show();
}

void MainWindow::nameFileRead()
{
    QFile namefile;
    namefile.setFileName(":/resources/name.txt");
    bool isok = namefile.open(QIODevice::ReadOnly);
    if (isok) {
        QTextStream filestream(&namefile);
        filestream.setEncoding(QStringConverter::Utf8);
        QString strread;
        while (filestream.atEnd() == false) {
            strread = filestream.readLine();
            m_lnames.push_back(strread);
        }
    } else {
        QMessageBox::warning(this, "提示", "文件路径为空 ！");
    }
}

void MainWindow::updateStuTable()
{
    ui->tableWidget->clearContents();
    QStringList headTable = {"学号", "姓名", "年龄", "年级", "班级", "电话"};
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(headTable);
    //点击选中行且不可直接编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //自动拉伸列
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    auto cnt = m_ptrStuSql->getStuCnt();
    ui->lb_stucnt->setText("学生数量为:" + QString::number(cnt));
    QList<StuInfo> lStudents = m_ptrStuSql->getPageStu(0, cnt);
    ui->tableWidget->setRowCount(cnt);
    for (quint32 i = 0; i < cnt; i++) {
        ui->tableWidget->setItem(i,
                                 0,
                                 new QTableWidgetItem(QString::number(lStudents[i].studentid)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(lStudents[i].sname));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(lStudents[i].sclass)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(lStudents[i].phonenumber));
    }
}

void MainWindow::updateUserTable()
{
    ui->tableWidget->clearContents();
    QStringList headTable = {"用户名", "密码", "权限"};
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headTable);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QList<UserInfo> lUsers = m_ptrStuSql->getAllUser();
    auto cnt = lUsers.length();
    ui->lb_stucnt->setText("用户数量为:" + QString::number(cnt));
    ui->tableWidget->setRowCount(cnt);
    for (int i = 0; i < cnt; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(lUsers[i].username));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(lUsers[i].password));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(lUsers[i].auth));
    }
}

void MainWindow::updateTcTable()
{
    ui->tableWidget->clearContents();
    QStringList headTable = {"教师号", "姓名", "年龄"};
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(headTable);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QList<TeacherInfo> lTeachers = m_ptrStuSql->getAllTeacher();
    auto cnt = lTeachers.length();
    ui->lb_stucnt->setText("教师数量为:" + QString::number(cnt));
    ui->tableWidget->setRowCount(cnt);
    for (int i = 0; i < cnt; i++) {
        ui->tableWidget->setItem(i,
                                 0,
                                 new QTableWidgetItem(QString::number(lTeachers[i].teacherid)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(lTeachers[i].name));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(lTeachers[i].age)));
    }
}

void MainWindow::updateScoreTable()
{
    ui->tableWidget->clearContents();
    QStringList headTable = {"编号","课程号", "课程名", "分数", "学号"};
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(headTable);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QList<ScoreInfo> lScores = m_ptrStuSql->getAllScore();
    auto cnt = lScores.length();
    ui->lb_stucnt->setText("记录数量为:" + QString::number(cnt));
    ui->tableWidget->setRowCount(cnt);
    for (int i = 0; i < cnt; i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(lScores[i].id)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(lScores[i].courseid)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(lScores[i].coursename));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(lScores[i].score)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(lScores[i].studentid)));
    }
}

void MainWindow::on_btn_simdata_clicked()
{
    //模拟数据
    if (curTable == 0) {
        QRandomGenerator randominput;
        randominput.seed(0);
        QList<StuInfo> l;
        int llength = m_lnames.size();
        for (int i = 0; i < llength; i++) {
            auto grade = randominput.bounded(1, 5);
            auto sclass = randominput.bounded(1, 10);
            auto age = randominput.bounded(18, 23);
            StuInfo info;
            info.sname = m_lnames[i];
            info.age = age;
            info.grade = grade;
            info.sclass = sclass;
            info.studentid = i + 1;
            info.phonenumber = "17755908510";
            l.append(info);
        }
        m_ptrStuSql->addStu(l);
        QMessageBox::information(this, "INFOR", "模拟完毕");
    }
}

void MainWindow::on_bt_add_clicked()
{
    if (curTable == 0) {
        m_dlgAddStu.setAOUType(true);
        m_dlgAddStu.addStu(); //模态对话，必须先执行完这个窗口。
        //show是可以不先弄完打开的窗口
    } else if (curTable == 1) {
        m_dlgAddUser.setAOUType(true);
        m_dlgAddUser.addUser();
    } else if (curTable == 2) {
        m_dlgAddTc.setAOUType(true);
        m_dlgAddTc.addTeacher();
    } else if (curTable == 3) {
        m_dlgAddSc.setAOUType(true);
        m_dlgAddSc.addScore();
    }
}

void MainWindow::on_btn_refresh_clicked()
{
    if (curTable == 0)
        updateStuTable();
    else if (curTable == 1)
        updateUserTable();
    else if (curTable == 2)
        updateTcTable();
    else if (curTable == 3)
        updateScoreTable();
}

void MainWindow::on_btn_cleartable_clicked()
{
    if (curTable == 0) {
        QMessageBox msgbox;
        msgbox.setText("确定清空表吗?");
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Yes:
            m_ptrStuSql->clearStuTable();
            break;
        case QMessageBox::No:
            break;
        default:
            break;
        }
        updateStuTable();
    }
}

void MainWindow::on_bt_delete_clicked()
{
    if (curTable == 0) {
        QMessageBox msgbox;
        msgbox.setText("确定删除?");
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Yes:
            goto okdelstu;
            break;
        case QMessageBox::No:
            return;
            break;
        default:
            return;
            break;
        }
    okdelstu:
        int i = ui->tableWidget->currentRow();
        if (i >= 0) {
            int id = ui->tableWidget->item(i, 0)->text().toInt();
            bool isok = m_ptrStuSql->delStu(id);
            if (isok) {
                QMessageBox::information(this, "info", "删除成功");
            } else {
                QMessageBox::information(this, "info", "删除失败");
            }
        }
        updateStuTable();
    } else if (curTable == 1) {
        QMessageBox msgbox;
        msgbox.setText("确定删除?");
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Yes:
            goto okdeluser;
            break;
        case QMessageBox::No:
            return;
            break;
        default:
            return;
            break;
        }
    okdeluser:
        int i = ui->tableWidget->currentRow();
        if (i >= 0) {
            QString username = ui->tableWidget->item(i, 0)->text();
            if (username == ui->lb_name->text()) {
                QMessageBox::information(this, "info", "你不能删除自己！");
                return;
            }
            bool isok = m_ptrStuSql->delUser(username);
            if (isok) {
                QMessageBox::information(this, "info", "删除成功");
            } else {
                QMessageBox::information(this, "info", "删除失败");
            }
        }
        updateUserTable();
    } else if (curTable == 2) {
        QMessageBox msgbox;
        msgbox.setText("确定删除?");
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Yes:
            goto okdeltc;
            break;
        case QMessageBox::No:
            return;
            break;
        default:
            return;
            break;
        }
    okdeltc:
        int i = ui->tableWidget->currentRow();
        if (i >= 0) {
            int tcid = ui->tableWidget->item(i, 0)->text().toInt();
            bool isok = m_ptrStuSql->delTeacher(tcid);
            if (isok) {
                QMessageBox::information(this, "info", "删除成功");
            } else {
                QMessageBox::information(this, "info", "删除失败");
            }
        }
        updateTcTable();
    } else if (curTable == 3) {
        QMessageBox msgbox;
        msgbox.setText("确定删除?");
        msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int ret = msgbox.exec();
        switch (ret) {
        case QMessageBox::Yes:
            goto okdelsc;
            break;
        case QMessageBox::No:
            return;
            break;
        default:
            return;
            break;
        }
    okdelsc:
        int i = ui->tableWidget->currentRow();
        if (i >= 0) {
            int scid = ui->tableWidget->item(i, 0)->text().toInt();
            bool isok = m_ptrStuSql->delScore(scid);
            if (isok) {
                QMessageBox::information(this, "info", "删除成功");
            } else {
                QMessageBox::information(this, "info", "删除失败");
            }
        }
    }
}

void MainWindow::on_bt_change_clicked()
{
    if (curTable == 0) {
        m_dlgAddStu.setAOUType(false);
        int i = ui->tableWidget->currentRow();
        StuInfo info;
        if (i >= 0) {
            info.studentid = ui->tableWidget->item(i, 0)->text().toInt();
            info.sname = ui->tableWidget->item(i, 1)->text();
            info.age = ui->tableWidget->item(i, 2)->text().toInt();
            info.grade = ui->tableWidget->item(i, 3)->text().toInt();
            info.sclass = ui->tableWidget->item(i, 4)->text().toInt();
            info.phonenumber = ui->tableWidget->item(i, 5)->text();
            m_dlgAddStu.updateStu(info);
        }
        updateStuTable();
    } else if (curTable == 1) {
        m_dlgAddUser.setAOUType(false);
        int i = ui->tableWidget->currentRow();
        UserInfo info;
        if (i >= 0) {
            info.username = ui->tableWidget->item(i, 0)->text();
            info.password = ui->tableWidget->item(i, 1)->text();
            info.auth = ui->tableWidget->item(i, 2)->text();
            m_dlgAddUser.updateUser(info);
        }
        updateUserTable();
    } else if (curTable == 2) {
        m_dlgAddTc.setAOUType(false);
        int i = ui->tableWidget->currentRow();
        TeacherInfo info;
        if (i >= 0) {
            info.teacherid = ui->tableWidget->item(i, 0)->text().toInt();
            info.name = ui->tableWidget->item(i, 1)->text();
            info.age = ui->tableWidget->item(i, 2)->text().toInt();
            m_dlgAddTc.updateTeacher(info);
        }
    } else if (curTable == 3) {
        m_dlgAddSc.setAOUType(false);
        int i = ui->tableWidget->currentRow();
        ScoreInfo info;
        if (i >= 0) {
            info.id = ui->tableWidget->item(i, 0)->text().toInt();
            info.courseid = ui->tableWidget->item(i, 1)->text().toInt();
            info.coursename = ui->tableWidget->item(i, 2)->text();
            info.score = ui->tableWidget->item(i, 3)->text().toInt();
            info.studentid = ui->tableWidget->item(i, 4)->text().toInt();
            m_dlgAddSc.updateScore(info);
        }
    }
}

void MainWindow::on_btn_search_clicked()
{
    if (curTable == 0) {
        //先清空表格
        ui->tableWidget->clearContents();
        QString strname = ui->le_searchname->text();
        QList<StuInfo> searchoutput = m_ptrStuSql->searchStuName(strname);
        auto cnt = searchoutput.length();
        ui->tableWidget->setRowCount(cnt);
        for (quint32 i = 0; i < cnt; i++) {
            ui->tableWidget
                ->setItem(i, 0, new QTableWidgetItem(QString::number(searchoutput[i].studentid)));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(searchoutput[i].sname));
            ui->tableWidget->setItem(i,
                                     2,
                                     new QTableWidgetItem(QString::number(searchoutput[i].age)));
            ui->tableWidget->setItem(i,
                                     3,
                                     new QTableWidgetItem(QString::number(searchoutput[i].grade)));
            ui->tableWidget->setItem(i,
                                     4,
                                     new QTableWidgetItem(QString::number(searchoutput[i].sclass)));
            ui->tableWidget->setItem(i, 5, new QTableWidgetItem(searchoutput[i].phonenumber));
        }
    } else if (curTable == 1) {
        //先清空表格
        ui->tableWidget->clearContents();
        QString strname = ui->le_searchname->text();
        QList<UserInfo> searchoutput = m_ptrStuSql->searchUserName(strname);
        auto cnt = searchoutput.length();
        ui->tableWidget->setRowCount(cnt);
        for (int i = 0; i < cnt; i++) {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(searchoutput[i].username));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(searchoutput[i].password));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(searchoutput[i].auth));
        }
    } else if (curTable == 2) {
        ui->tableWidget->clearContents();
        QString strname = ui->le_searchname->text();
        QList<TeacherInfo> searchoutput = m_ptrStuSql->searchTcName(strname);
        auto cnt = searchoutput.length();
        ui->tableWidget->setRowCount(cnt);
        for (int i = 0; i < cnt; i++) {
            ui->tableWidget
                ->setItem(i, 0, new QTableWidgetItem(QString::number(searchoutput[i].teacherid)));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(searchoutput[i].name));
            ui->tableWidget->setItem(i,
                                     2,
                                     new QTableWidgetItem(QString::number(searchoutput[i].age)));
        }
    }
}

void MainWindow::on_btn_stuinfomgr_clicked()
{
    curTable = 0;
    updateStuTable();
}

void MainWindow::on_btn_userinfomgr_clicked()
{
    if (m_dlgLogin.curUser.auth != "admin") {
        QMessageBox::information(this, "info", "权限不足！");
        return;
    }
    curTable = 1;
    updateUserTable();
}

void MainWindow::on_btn_teainfomgr_clicked()
{
    if (m_dlgLogin.curUser.auth != "admin") {
        QMessageBox::information(this, "info", "权限不足！");
        return;
    }
    curTable = 2;
    updateTcTable();
}

void MainWindow::on_btn_scoreinfomgr_clicked()
{
    curTable = 3;
    updateScoreTable();
}
