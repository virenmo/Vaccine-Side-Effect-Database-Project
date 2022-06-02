#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include "dataset.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/viren/Desktop/CoverMain.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    DataSet dataset;
    QString qs;
    qs.setNum(dataset.get_amountofUsers());
    ui->label_number->setStyleSheet("color: white");
    ui->label_number->setText(qs);
    ui->label_3->setStyleSheet("color: white;");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_userdata_clicked() {

    userInfo = new userinfo(this);
    userInfo->show();

}


void MainWindow::on_pushButton_check_age_clicked() {

    userprofile usr2;
    DataSet dataset;
    QString qs;
    qs.setNum(dataset.get_avgUserAge());

    QMessageBox::information(this, "Average Age", "The Average Age is "+qs);
}


void MainWindow::on_pushButton_check_vaccine_clicked() {

    DataSet dataset;
    QString qs = QString::fromStdString(dataset.get_avgVaccine());

    QMessageBox::information(this, "Most Common Vaccine", "The most Common Vaccine is "+qs);
}

void MainWindow::on_pushButton_check_sex_clicked() {

    DataSet dataset;
    QString qs = QString::fromStdString( dataset.get_avgSex() );

    QMessageBox::information(this, "Most Common Sex", "Most Common Sex is " +qs );
}


void MainWindow::on_pushButton_check_effect_clicked() {

    DataSet dataset;
    QString qs = QString::fromStdString( dataset.get_mostCommonSideEffect() );

    QMessageBox::information(this, "Most Common Side Effect " , "Most Common Side Effect is "+qs );
}


void MainWindow::on_pushButton_check_leastCommonEffect_clicked() {

    DataSet dataset;
    QString qs = QString::fromStdString( dataset.get_leastCommonSideEffect() );

    QMessageBox::information(this, "Least Common Side Effect", "Least Common Side Effect is "+qs);
}



void MainWindow::on_pushButton_clicked()
{
   close();
}



