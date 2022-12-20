#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bor.add_string(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_3->clear();
    vector<string> list;
    list = bor.searchEnd(ui->lineEdit_3->text().toStdString());
    for(auto i:list)
    {
        ui->plainTextEdit->insertPlainText(QString::fromStdString(i+"\n"));
        ui->plainTextEdit_2->insertPlainText(QString::fromStdString(*bor[i]+"\n"));
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    bor.treeFromFile((ui->lineEdit_4->text()).toStdString());
}
void MainWindow::on_pushButton_4_clicked()
{
    bor.treeToFile((ui->lineEdit_4->text()).toStdString());
}

