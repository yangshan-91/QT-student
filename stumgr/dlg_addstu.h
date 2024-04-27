#ifndef DLG_ADDSTU_H
#define DLG_ADDSTU_H

#include <QDialog>
#include "stumgrsql.h"
#include <QMessageBox>
namespace Ui {
class Dlg_AddStu;
}

class Dlg_AddStu : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_AddStu(QWidget *parent = nullptr);
    ~Dlg_AddStu();
    void updateStu(StuInfo info);
    void addStu();
    void setAOUType(bool AddOrUpdate);
private slots:
    void on_btn_cancel_clicked();

    void on_btn_save_clicked();

private:
    Ui::Dlg_AddStu *ui;
    bool isAddOrUpdate;//True为add，false为Update
};

#endif // DLG_ADDSTU_H
