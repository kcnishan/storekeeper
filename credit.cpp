#include "credit.h"
#include "ui_credit.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>

Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
    QFile file("credit");
  file.open(QIODevice::ReadOnly);
      { // QMessageBox::information(0,"INFO",file.errorString());

        QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());}
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_pushButton_clicked()
{

}
