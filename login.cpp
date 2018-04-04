#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "admin.h"
#include "user.h"
#include <QDebug>
#include"adduser.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


}

Login::~Login()
{
    delete ui;
}

void Login::on_adra_clicked()
{

}

void Login::on_usra_clicked()
{

}

void Login::on_adbut_clicked()
{
    QString username,password;
    username=ui->adus->text();
    password=ui->adpa->text();

    //qDebug()<<password;

     connOpen();

    QSqlQuery any;

    //select * from login where username='' and password ='' or '1' = '1'

    any.prepare("select * from login where username='"+username+"'and password='"+password+"'");
    if(any.exec())
    {
        if(any.next())
        {
             connclose();
            this->close();
            Admin aa;
            aa.setModal(true);
            aa.exec();


        }

        else
        {
            QMessageBox::warning(this,tr("LOGIN FAILED"),tr("Sorry the Login username and password combination you entered is not valid please use the valid one"));
           ui->adus->clear();
           ui->adpa->clear();
        }

}
}

void Login::on_usbut_clicked()
{
    QString username,password;
    username=ui->usua->text();
    password=ui->uspa->text();

     connOpen();

    QSqlQuery any;
    any.prepare("select * from login where saleus='"+username+"'and salepass='"+password+"'");

    if(any.exec())
    {
        if(any.next())
        {
            connclose();
            this->close();
            user aa;
            aa.setModal(true);
            aa.exec();
        }

        else
        {
            QMessageBox::warning(this,tr("LOGIN FAILED"),tr("Sorry the Login username and password combination you entered is not valid please use the valid one"));
            ui->usua->clear();
            ui->uspa->clear();
        }
    }
}

void Login::on_checkBox_clicked()
{
    adduser ad;
    ad.setModal(this);
    ad.exec();
}

void Login::on_checkBox_2_clicked()
{
    adduser aa;
    aa.setModal(this);
    aa.exec();
}
