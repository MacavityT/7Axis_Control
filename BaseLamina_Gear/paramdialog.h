#ifndef PARAMDIALOG_H
#define PARAMDIALOG_H
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
#include <QDialog>
#include <QSettings>
#include<QMessageBox>
#include "LTDMC.h"

namespace Ui {
class ParamDialog;
}

class ParamDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParamDialog(QWidget *parent = 0);
    ~ParamDialog();
    void set_configure_parameter();
    void disp_configure_parameter();
    void lock_ui(bool);

signals:
//    void signal_parameters_changed();

private slots:
    void on_CHANGE_clicked();

    void on_ALL_CONFIRM_clicked();

    void on_CLOSE_clicked();

private:
    Ui::ParamDialog *ui;
};

#endif // PARAMDIALOG_H
