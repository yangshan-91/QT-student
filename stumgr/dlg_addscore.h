#ifndef DLG_ADDSCORE_H
#define DLG_ADDSCORE_H

#include <QDialog>
#include "stumgrsql.h"
#include <QMessageBox>
namespace Ui {
class dlg_addscore;
}

class dlg_addscore : public QDialog
{
    Q_OBJECT

public:
    explicit dlg_addscore(QWidget *parent = nullptr);
    ~dlg_addscore();
    void updateScore(ScoreInfo info);
    void addScore();
    void setAOUType(bool AddOrUpdate);
private slots:
    void on_btn_save_clicked();

    void on_btn_exit_clicked();

private:
    Ui::dlg_addscore *ui;
    bool isAddOrUpdate; //True为add，false为Update
    ScoreInfo UPINFO;//传入进来要修改的成绩，只能改成绩
};

#endif // DLG_ADDSCORE_H
