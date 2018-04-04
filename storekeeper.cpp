#include "storekeeper.h"
#include "ui_storekeeper.h"
#include "login.h"
StoreKeeper::StoreKeeper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StoreKeeper)
{
    ui->setupUi(this);

}

StoreKeeper::~StoreKeeper()
{
    delete ui;
}

void StoreKeeper::on_pushButton_clicked()
{   this->hide();
    Login aa;
    aa.setModal(true);
    aa.exec();
}

void StoreKeeper::on_pushButton_2_clicked()
{
    Credit credit;
    credit.setModal(this);
    credit.exec();
}
