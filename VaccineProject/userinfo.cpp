#include "userinfo.h"
#include "ui_userinfo.h"
#include "dataset.h"
#include "userprofile.h"

userinfo::userinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userinfo)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/viren/Desktop/Moonrise.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

userinfo::~userinfo()
{
    delete ui;
}

void userinfo::on_pushButton_saveUserData_clicked()
{
    QString n = ui->lineEdit_name->text();
    std::string name = n.toUtf8().constData();
    QString s = ui->lineEdit_surname->text();
    std::string surname = s.toUtf8().constData();
    QString a = ui->lineEdit_dob->text();
    int age = a.toInt();
    QString se = ui->comboBox_sex->currentText();
    std::string sex = se.toUtf8().constData();
    QString v = ui->comboBox_vaccine->currentText();
    std::string vaccine = v.toUtf8().constData();
    QString e = ui->comboBox_effect->currentText();
    std::string effect = e.toUtf8().constData();

    userprofile userP ( name , surname, vaccine, effect, sex, age);

    DataSet dataset ;
    dataset.addUser(userP);

    hide();
}


void userinfo::on_pushButton_cancel_clicked()
{
    close();
}

