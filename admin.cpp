#include "admin.h"
#include "ui_admin.h"
#include "login.h"
#include "addgoods.h"
#include"display.h"
#include"update.h"
#include"adduser.h"
#include"addnew.h"
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    this->close();
    Login aa;
    aa.setModal(true);
    aa.exec();

}

void Admin::on_add_clicked()
{   this->close();
    AddGoods yy;
    yy.setModal(true);
    yy.exec();


}

void Admin::on_search_clicked()
{
    //this->close();
    Display display;
    display.setModal(true);
    display.exec();  
}

void Admin::on_edit_clicked()
{
    this->close();
    Update update;
    update.setModal(true);
    update.exec();

}


void Admin::on_adduser_clicked()
{
    Addnew ad;
    ad.setModal(this);
    ad.exec();

}
