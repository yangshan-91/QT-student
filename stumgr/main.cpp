#include "mainwindow.h"
#include "page_login.h"
#include <QApplication>
#include "stumgrsql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();//不显示空的主界面，就显示login界面，因为创建mainwindow的时候初始化就会执行login界面的show函数
    //stumgrSQL mysql;
    return a.exec();
}
