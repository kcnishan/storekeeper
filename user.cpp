#include "user.h"
#include "ui_user.h"
#include "login.h"
#include"display.h"
#include"sales.h"
user::user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked()
{
    this->close();
    Login aa;
    aa.setModal(true);
    aa.exec();

}

void user::on_search_clicked()
{
    //this->close();
    Display display;
    display.setModal(true);
    display.exec();
}


void user::on_sale_clicked()
{
    sales sa;
    sa.setModal(true);
    sa.exec();
}
