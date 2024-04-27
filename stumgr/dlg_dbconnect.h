#ifndef DLG_DBCONNECT_H
#define DLG_DBCONNECT_H

#include <QDialog>
#include "stumgrsql.h"
namespace Ui {
class dlg_dbconnect;
}

class dlg_dbconnect : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_dbconnect(QWidget *parent = nullptr);
    ~dlg_dbconnect();

private slots:
    void on_btn_login_clicked();
    void on_btn_exit_clicked();

signals:
    void sendDBConnectSuccess();
private:
    Ui::dlg_dbconnect *ui;
    stumgrSQL *m_ptrdbcsql;
};

#endif // DLG_DBCONNECT_H
