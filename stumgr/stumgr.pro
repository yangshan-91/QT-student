QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dlg_addscore.cpp \
    dlg_addstu.cpp \
    dlg_addtc.cpp \
    dlg_adduser.cpp \
    dlg_dbconnect.cpp \
    main.cpp \
    mainwindow.cpp \
    page_login.cpp \
    stu_mainpage.cpp \
    stumgrsql.cpp

HEADERS += \
    dlg_addscore.h \
    dlg_addstu.h \
    dlg_addtc.h \
    dlg_adduser.h \
    dlg_dbconnect.h \
    mainwindow.h \
    page_login.h \
    stu_mainpage.h \
    stumgrsql.h

FORMS += \
    dlg_addscore.ui \
    dlg_addstu.ui \
    dlg_addtc.ui \
    dlg_adduser.ui \
    dlg_dbconnect.ui \
    mainwindow.ui \
    page_login.ui \
    stu_mainpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
