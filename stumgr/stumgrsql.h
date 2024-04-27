#ifndef STUMGRSQL_H
#define STUMGRSQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
struct StuInfo
{
    int studentid;
    QString sname;
    quint8 age;
    quint16 grade;
    quint16 sclass;
    QString phonenumber;
};

struct UserInfo
{
    QString username;
    QString password;
    QString auth;
};

struct CourseInfo
{
    int courseid;
    QString coursename;
    int teacherid;
    QString teachername;
};
struct TeacherInfo
{
    int teacherid;
    QString name;
    int age;
};

struct ScoreInfo
{
    int id;
    int courseid;
    QString coursename;
    int score;
    int studentid;
};

class stumgrSQL : public QObject
{
    Q_OBJECT
public:
    static stumgrSQL *ptrstuSql;
    static stumgrSQL *getinstance()
    {
        if (nullptr == ptrstuSql) {
            ptrstuSql = new stumgrSQL;
        }
        return ptrstuSql;
    }
    explicit stumgrSQL(QObject *parent = nullptr);
    //初始化，打开数据库
    bool init(QString username, QString password);
    //查询所有学生数量
    quint32 getStuCnt();
    //查询第几页学生数据,一页查多少个，从第0页开始的
    QList<StuInfo> getPageStu(quint32 pagenum, quint32 uiCnt); //参数：页数，查询数量。

    //增加学生
    bool addStu(StuInfo info);        //先一次只能加一个学生
    bool addStu(QList<StuInfo> LStu); //一次添加多个学生
    //删除学生
    bool delStu(int id); //通过学号主键删除
    //通过姓名搜索学生
    QList<StuInfo> searchStuName(QString stuName);
    //返回学号为ID的学生的信息
    StuInfo searchStuId(int id);

    //清空学生表
    void clearStuTable();
    //清空用户表
    void clearUserTable();
    //修改学生表
    bool updateStu(StuInfo info);

    //查询用户表
    QList<UserInfo> getAllUser();
    //通过用户名搜索用户
    QList<UserInfo> searchUserName(QString userName);
    //登录查询用户名密码是否正确
    QString loginCheck(QString strUser, QString strpassword);

    //更新用户信息
    bool updateUser(UserInfo info);

    //添加用户：
    bool addUser(UserInfo input);
    //删除用户
    bool delUser(QString strUserName);
    //获取所有教师
    QList<TeacherInfo> getAllTeacher();
    //搜索教师名
    QList<TeacherInfo> searchTcName(QString tcname);
    //添加教师
    bool addTeacher(TeacherInfo info);
    //更新教师信息
    bool updateTeacher(TeacherInfo info);
    //删除教师
    bool delTeacher(int id);
    //获取教师编号为id的老师名字
    QString getTcName(int id);
    //获取课程信息
    QList<CourseInfo> getAllCourse();
    //获取课程号为id的课程名
    QString getCourseName(int id);
    //获取个人分数信息，可以用作搜索。
    QList<ScoreInfo> getStuScore(int studentid);
    //获取所有学生的分数
    QList<ScoreInfo> getAllScore();
    //增加一条成绩记录
    bool addScore(ScoreInfo info);
    //更新成绩信息
    bool updateScore(ScoreInfo info);
    //删除成绩记录
    bool delScore(int id);

signals:
private:
    QSqlDatabase mydb;
};

#endif // STUMGRSQL_H
