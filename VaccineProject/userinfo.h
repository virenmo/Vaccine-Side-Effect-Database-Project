#ifndef USERINFO_H
#define USERINFO_H

#include <QMainWindow>

namespace Ui {
class userinfo;
}

class userinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit userinfo(QWidget *parent = nullptr);
    ~userinfo();

private slots:
    void on_pushButton_saveUserData_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::userinfo *ui;
};

#endif // USERINFO_H
