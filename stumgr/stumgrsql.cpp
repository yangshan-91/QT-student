#include "stumgrsql.h"
#include <QMessageBox>
#include <QSqlQuery>

stumgrSQL *stumgrSQL::ptrstuSql = nullptr;

stumgrSQL::stumgrSQL(QObject *parent)
    : QObject{parent}
{
    //q.exec("INSERT INTO STUDENT VALUES (1,'yjp',18,2,3,'17755908510')");
}

bool stumgrSQL::init(QString username, QString password)
{
    mydb = QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName("127.0.0.1");
    mydb.setPort(3306);
    mydb.setDatabaseName("stumanagedb");
    mydb.setUserName(username);
    mydb.setPassword(password);
    bool ok = mydb.open();
    if (ok) {
        QMessageBox::information(NULL, "success", "database connect successfully");
        return true;
    } else {
        QString fault = mydb.lastError().text();
        QMessageBox::information(NULL, "error", "database connect failed\n" + fault);
        return false;
    }
}

quint32 stumgrSQL::getStuCnt()
{
    QSqlQuery sql(mydb);
    sql.exec("SELECT COUNT(STUDENTID) FROM STUDENT");
    //QSqlQuery提供了一个访问一条查询结果记录的方法。在调用了exec()方法之后，QSqlQuery的内部指针定位到了第一条记录之前的位置。
    //我们必须调用一次QSqlQuery::next()内部指针就移动到第一条记录上，然后重复调用next()方法就可以移动到其他记录上，
    //直到该函数返回false为止。value返回的是该记录的第几个值。
    quint32 stunum = 0;
    while (sql.next()) {
        stunum = sql.value(0).toInt();
    }
    return stunum;
}

QList<StuInfo> stumgrSQL::getPageStu(quint32 pagenum, quint32 uiCnt)
{
    QList<StuInfo> listoutput;
    QSqlQuery sql(mydb);
    //设置一页30个，limit是限制查找多少个，offset从第几个开始查找。
    QString strsql = QString("SELECT * FROM STUDENT ORDER BY STUDENTID LIMIT %1 OFFSET %2")
                         .arg(uiCnt)
                         .arg(pagenum * uiCnt);
    sql.exec(strsql);
    StuInfo info;
    while (sql.next()) {
        info.studentid = sql.value(0).toInt();
        info.sname = sql.value(1).toString();
        info.age = sql.value(2).toInt();
        info.grade = sql.value(3).toInt();
        info.sclass = sql.value(4).toInt();
        info.phonenumber = sql.value(5).toString();
        listoutput.push_back(info);
    }
    return listoutput;
}

bool stumgrSQL::addStu(StuInfo info)
{
    QSqlQuery sql(mydb);
    QString strSQL = QString("INSERT INTO STUDENT VALUES(NULL,'%1',%2,%3,%4,'%5')")
                         .arg(info.sname)
                         .arg(info.age)
                         .arg(info.grade)
                         .arg(info.sclass)
                         .arg(info.phonenumber);
    return sql.exec(strSQL);
}

bool stumgrSQL::addStu(QList<StuInfo> LStu)
{
    QSqlQuery sql(mydb);
    bool isok;
    mydb.transaction(); //事务是由一条或多条SQL语句组成的逻辑执行单元, 可以比喻成一个容器, 里面放的就是一堆SQL语句,
    //这些语句要么全部执行成功, 要么一个都无法执行成功(原子性)
    for (auto info : LStu) {
        QString strSQL = QString("INSERT INTO STUDENT VALUES(NULL,'%1',%2,%3,%4,'%5');")
                             .arg(info.sname)
                             .arg(info.age)
                             .arg(info.grade)
                             .arg(info.sclass)
                             .arg(info.phonenumber);
        sql.exec(strSQL);
    }
    mydb.commit();
    isok = mydb.lastError().isValid();
    if (!isok)
        QMessageBox::information(NULL, "info", "插入成功");
    else
        QMessageBox::information(NULL, "info", "插入失败");
    sql.finish();
    return isok;
}

bool stumgrSQL::delStu(int id)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("DELETE FROM STUDENT WHERE STUDENTID = %1").arg(id);
    return sql.exec(strsql);
}

QList<StuInfo> stumgrSQL::searchStuName(QString stuName)
{
    QList<StuInfo> listoutput;
    QSqlQuery sql(mydb);
    //使用sql语句进行搜索
    //使用通配符，所以当输入框为空的时候，功能相当于刷新
    QString strsql = QString("SELECT * FROM STUDENT WHERE SNAME like '\%%1\%';").arg(stuName);
    bool isok = sql.exec(strsql);
    if (!isok)
        QMessageBox::information(NULL, "INFO", "搜索失败");
    StuInfo info;
    while (sql.next()) {
        info.studentid = sql.value(0).toInt();
        info.sname = sql.value(1).toString();
        info.age = sql.value(2).toInt();
        info.grade = sql.value(3).toInt();
        info.sclass = sql.value(4).toInt();
        info.phonenumber = sql.value(5).toString();
        listoutput.push_back(info);
    }
    return listoutput;
}

StuInfo stumgrSQL::searchStuId(int id)
{
    QSqlQuery sql(mydb);
    StuInfo info;
    info.studentid = -1;
    QString strsql = QString("SELECT * FROM STUDENT WHERE STUDENTID = %1").arg(id);
    bool isok = sql.exec(strsql);
    if (!isok) {
        QMessageBox::information(NULL, "info", "查询错误" + sql.lastError().text());
    }
    if (sql.next()) {
        info.studentid = sql.value(0).toInt();
        info.sname = sql.value(1).toString();
        info.age = sql.value(2).toInt();
        info.grade = sql.value(3).toInt();
        info.sclass = sql.value(4).toInt();
        info.phonenumber = sql.value(5).toString();
    }

    return info;
}

void stumgrSQL::clearStuTable()
{
    QSqlQuery sql(mydb);
    QString strsql = QString("DELETE FROM STUDENT;ALTER TABLE student AUTO_INCREMENT = 1");
    sql.exec(strsql);
}

void stumgrSQL::clearUserTable()
{
    QSqlQuery sql(mydb);
    QString strsql = QString("DELETE FROM USER");
    sql.exec(strsql);
}

bool stumgrSQL::updateStu(StuInfo info)
{
    QSqlQuery sql(mydb);
    QString strSQL = QString("UPDATE STUDENT SET SNAME = '%1',AGE = %2,GRADE = %3,SCLASS = "
                             "%4,PHONENUMBER = '%5' WHERE STUDENTID = %6")
                         .arg(info.sname)
                         .arg(info.age)
                         .arg(info.grade)
                         .arg(info.sclass)
                         .arg(info.phonenumber)
                         .arg(info.studentid);
    return sql.exec(strSQL);
}

QList<UserInfo> stumgrSQL::getAllUser()
{
    QList<UserInfo> listoutput;
    QSqlQuery sql(mydb);
    QString strsql = QString("SELECT * FROM USER");
    sql.exec(strsql);
    UserInfo info;
    while (sql.next()) {
        info.username = sql.value(0).toString();
        info.password = sql.value(1).toString();
        info.auth = sql.value(2).toString();
        listoutput.push_back(info);
    }
    return listoutput;
}

QList<UserInfo> stumgrSQL::searchUserName(QString userName)
{
    QList<UserInfo> listoutput;
    QSqlQuery sql(mydb);
    //使用sql语句进行搜索
    //使用通配符，所以当输入框为空的时候，功能相当于刷新
    QString strsql = QString("SELECT * FROM USER WHERE USERNAME like '\%%1\%';").arg(userName);
    bool isok = sql.exec(strsql);
    if (!isok)
        QMessageBox::information(NULL, "INFO", "搜索失败");
    UserInfo info;
    while (sql.next()) {
        info.username = sql.value(0).toString();
        info.password = sql.value(1).toString();
        info.auth = sql.value(2).toString();
        listoutput.push_back(info);
    }
    return listoutput;
}

QString stumgrSQL::loginCheck(QString strUser, QString strpassword)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("SELECT * FROM USER WHERE USERNAME = '%1' AND PASSWORD = '%2'")
                         .arg(strUser)
                         .arg(strpassword);
    sql.exec(strsql);
    QString rtstr = "false";
    if (sql.next()) {
        rtstr = sql.value(2).toString();
    }
    return rtstr;
}

bool stumgrSQL::updateUser(UserInfo info)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("UPDATE USER SET PASSWORD = '%1',AUTH = '%2' WHERE USERNAME = '%3'")
                         .arg(info.password)
                         .arg(info.auth)
                         .arg(info.username);
    return sql.exec(strsql);
}

bool stumgrSQL::addUser(UserInfo input)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("INSERT INTO USER VALUES('%1','%2','%3')")
                         .arg(input.username)
                         .arg(input.password)
                         .arg(input.auth);
    return sql.exec(strsql);
}

bool stumgrSQL::delUser(QString strUserName)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("DELETE FROM USER WHERE USERNAME = '%1'").arg(strUserName);
    return sql.exec(strsql);
}

QList<TeacherInfo> stumgrSQL::getAllTeacher()
{
    QList<TeacherInfo> listoutput;
    QSqlQuery sql(mydb);
    QString strsql = QString("SELECT * FROM TEACHER");
    sql.exec(strsql);
    TeacherInfo info;
    while (sql.next()) {
        info.teacherid = sql.value(0).toInt();
        info.name = sql.value(1).toString();
        info.age = sql.value(2).toInt();
        listoutput.push_back(info);
    }
    return listoutput;
}

QList<TeacherInfo> stumgrSQL::searchTcName(QString tcname)
{
    QList<TeacherInfo> listoutput;
    QSqlQuery sql(mydb);
    //使用sql语句进行搜索
    //使用通配符，所以当输入框为空的时候，功能相当于刷新
    QString strsql = QString("SELECT * FROM TEACHER WHERE NAME like '\%%1\%';").arg(tcname);
    bool isok = sql.exec(strsql);
    if (!isok)
        QMessageBox::information(NULL, "INFO", "搜索失败");
    TeacherInfo info;
    while (sql.next()) {
        info.teacherid = sql.value(0).toInt();
        info.name = sql.value(1).toString();
        info.age = sql.value(2).toInt();
        listoutput.push_back(info);
    }
    return listoutput;
}

bool stumgrSQL::addTeacher(TeacherInfo info)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("INSERT INTO TEACHER VALUES(%1,'%2',%3)")
                         .arg(info.teacherid)
                         .arg(info.name)
                         .arg(info.age);
    return sql.exec(strsql);
}

bool stumgrSQL::updateTeacher(TeacherInfo info)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("UPDATE TEACHER SET NAME = '%1',AGE = %2 WHERE TEACHERID = %3")
                         .arg(info.name)
                         .arg(info.age)
                         .arg(info.teacherid);
    return sql.exec(strsql);
}

bool stumgrSQL::delTeacher(int id)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("DELETE FROM TEACHER WHERE TEACHERID = '%1'").arg(id);
    return sql.exec(strsql);
}

QString stumgrSQL::getTcName(int id)
{
    QSqlQuery sql(mydb);
    QString tcname;
    QString strsql = QString("SELECT NAME FROM TEACHER WHERE TEACHERID = %1").arg(id);
    if (sql.exec(strsql)) {
        if (sql.next()) {
            tcname = sql.value(0).toString();
        }
        return tcname;
    } else {
        QMessageBox::information(NULL, "info", "没有该教师");
        return "无";
    }
}

QList<CourseInfo> stumgrSQL::getAllCourse()
{
    QList<CourseInfo> listoutput;
    QSqlQuery sql(mydb);
    QString strsql = QString("SELECT * FROM COURSE");
    sql.exec(strsql);
    CourseInfo info;
    while (sql.next()) {
        info.courseid = sql.value(0).toInt();
        info.coursename = sql.value(1).toString();
        info.teacherid = sql.value(2).toInt();
        info.teachername = getTcName(info.teacherid);
        listoutput.push_back(info);
    }
    return listoutput;
}

QString stumgrSQL::getCourseName(int id)
{
    QSqlQuery sql(mydb);
    QString cname;
    QString strsql = QString("SELECT CNAME FROM COURSE WHERE COURSEID = %1").arg(id);
    if (sql.exec(strsql)) {
        if (sql.next()) {
            cname = sql.value(0).toString();
        }
        return cname;
    } else {
        QMessageBox::information(NULL, "info", "没有该课程");
        return "无";
    }
}

QList<ScoreInfo> stumgrSQL::getStuScore(int studentid)
{
    QList<ScoreInfo> listoutput;
    QSqlQuery sql(mydb);
    QString strsql = QString("SELECT * FROM STUSCORE WHERE STUDENTID = %1").arg(studentid);
    sql.exec(strsql);
    ScoreInfo info;
    while (sql.next()) {
        info.id = sql.value(0).toInt();
        info.courseid = sql.value(1).toInt();
        info.coursename = getCourseName(info.courseid);
        info.score = sql.value(2).toInt();
        info.studentid = sql.value(3).toInt();
        listoutput.push_back(info);
    }
    return listoutput;
}

QList<ScoreInfo> stumgrSQL::getAllScore()
{
    QList<ScoreInfo> listoutput;
    QSqlQuery sql(mydb);
    QString strsql = QString("SELECT * FROM STUSCORE");
    sql.exec(strsql);
    ScoreInfo info;
    while (sql.next()) {
        info.id = sql.value(0).toInt();
        info.courseid = sql.value(1).toInt();
        info.coursename = getCourseName(info.courseid);
        info.score = sql.value(2).toInt();
        info.studentid = sql.value(3).toInt();
        listoutput.push_back(info);
    }
    return listoutput;
}

bool stumgrSQL::addScore(ScoreInfo info)
{
    QSqlQuery sql(mydb);
    QString strsql = QString("INSERT INTO STUSCORE VALUES(NULL,%1,%2,%3)")
                         .arg(info.courseid)
                         .arg(info.score)
                         .arg(info.studentid);
    return sql.exec(strsql);
}

bool stumgrSQL::updateScore(ScoreInfo info)
{
    QSqlQuery sql(mydb);
    QString strsql
        = QString("UPDATE STUSCORE SET SCORE = %1 WHERE ID = %2").arg(info.score).arg(info.id);

    return sql.exec(strsql);
}

bool stumgrSQL::delScore(int id)
{
    QSqlQuery sql(mydb);
    QString strsql
        = QString("DELETE FROM STUSCORE WHERE ID = %1").arg(id);

    return sql.exec(strsql);
}
