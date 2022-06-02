#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userinfo.h"
#include "userprofile.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_userdata_clicked();

    void on_pushButton_check_age_clicked();

    void on_pushButton_check_vaccine_clicked();

    void on_pushButton_check_sex_clicked();

    void on_pushButton_check_effect_clicked();

    void on_pushButton_check_leastCommonEffect_clicked();

    void on_pushButton_clicked();

    void on_label_avg_age_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
    userinfo *userInfo;
    userprofile *userP;

};
#endif // MAINWINDOW_H
