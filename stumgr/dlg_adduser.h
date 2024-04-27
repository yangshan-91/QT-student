#ifndef DLG_ADDUSER_H
#define DLG_ADDUSER_H

#include <QDialog>
#include <stumgrsql.h>
#include <QMessageBox>
namespace Ui {
class dlg_AddUser;
}

class dlg_AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_AddUser(QWidget *parent = nullptr);
    ~dlg_AddUser();
    void setAOUType(bool AddOrUpdate);
    void addUser();
    void updateUser(UserInfo info);

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::dlg_AddUser *ui;
    bool isAddOrUpdate;//True为add，false为Update
};

#endif // DLG_ADDUSER_H
