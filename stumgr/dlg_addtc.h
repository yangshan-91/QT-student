#ifndef DLG_ADDTC_H
#define DLG_ADDTC_H

#include <QDialog>
#include "stumgrsql.h"
#include <QMessageBox>
namespace Ui {
class Dlg_AddTc;
}

class Dlg_AddTc : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_AddTc(QWidget *parent = nullptr);
    ~Dlg_AddTc();
    void setAOUType(bool AddOrUpdate);
    void addTeacher();
    void updateTeacher(TeacherInfo info);
private slots:
    void on_btn_cancel_clicked();

    void on_btn_save_clicked();

private:
    Ui::Dlg_AddTc *ui;
    bool isAddOrUpdate;//True为add，false为Update
};

#endif // DLG_ADDTC_H
