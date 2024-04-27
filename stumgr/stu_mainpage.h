#ifndef STU_MAINPAGE_H
#define STU_MAINPAGE_H

#include <QWidget>
#include "stumgrsql.h"
namespace Ui {
class Stu_mainpage;
}

class Stu_mainpage : public QWidget
{
    Q_OBJECT

public:
    StuInfo loginstu;
    //更新学生个人主页信息
    void updatePageInfo();
    explicit Stu_mainpage(QWidget *parent = nullptr);
    ~Stu_mainpage();
    //更新课程表信息
    void updateCourseInfo();
signals:
    void StuPageExit();
private slots:
    void on_btn_exit_clicked();


    void on_btn_classinfo_clicked();

    void on_btn_scoreinfo_clicked();

private:
    Ui::Stu_mainpage *ui;

};

#endif // STU_MAINPAGE_H
