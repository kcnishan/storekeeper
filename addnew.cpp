#include "addnew.h"
#include "ui_addnew.h"
#include"login.h"
#include<QMessageBox>

Addnew::Addnew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addnew)
{
    ui->setupUi(this);
}

Addnew::~Addnew()
{
    delete ui;
}

void Addnew::on_pushButton_clicked()
{
    Login op;
    QString username, password,us_friendname,us_nickname,us_unclename;
    username=ui->line_username->text();
    password=ui->lineEdit_password->text();
    us_friendname=ui->line_friendname->text();
    us_nickname=ui->line_nickname->text();
    us_unclename=ui->line_unclename->text();

    op.connOpen();
    QSqlQuery ent;



if(!(username==""||password==""||us_friendname==""||us_nickname==""||us_unclename==""))
{
    ent.prepare("insert into login ( saleus ,salepass,us_friendname,us_nickname,us_unclename )values('"+username+"','"+password+"','"+us_friendname+"','"+us_nickname+"','"+us_unclename+"')");
if(ent.exec())
    {
        QMessageBox::information(this,tr("Information"),tr("Saved"));
        op.connclose();

       this->close();
    }
 else{
     QMessageBox::critical(this,tr("Information"),ent.lastError().text());
    }
}


if(username=="")
{


  ui->line_username->clear();
 }
 if(password=="")
{

ui->lineEdit_password->clear();
}

if(us_friendname=="")
{

ui->line_friendname->clear();
}

if(us_nickname=="")
{

ui->line_nickname->clear();
}

if(us_unclename=="")
{
ui->line_unclename->clear();
}


}
