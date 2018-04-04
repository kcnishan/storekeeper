#include "addgoods.h"
#include "ui_addgoods.h"
#include "login.h"
#include <QMessageBox>
#include<QDebug>
#include"admin.h"

AddGoods::AddGoods(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGoods)
{
    ui->setupUi(this);
}

AddGoods::~AddGoods()
{
    delete ui;
}

void AddGoods::on_save_clicked()
{
    Login op;
    bool ok;
    double c, s;
    int quant;
    QString sn, item,code,quantity,cp,sp,a[5];

    item=ui->item->text();
    code=ui->code->text();
    c=ui->cp->text().toDouble(&ok);
    s=ui->sp->text().toDouble(&ok);

    cp=QString::number(c);
    sp=QString::number(s);
    quant=ui->quantity->text().toInt(&ok,10);
    quantity=QString::number(quant);
    op.connOpen();
    QSqlQuery ent;


    /*QList<QString> errors;

    if(item == ""){
        errors.push_back("Item cannot be empty");
    }
    if(code == ""){

    }

    if(errors.size() == 0){


    } else {
        QString =
    }*/
if(!(item==QString("")||code==""||cp=="0"||cp==""||sp==""||sp=="0"||quantity==""||quantity=="0"))
{
    ent.prepare("insert into entries ( Item ,Item_Code,Cost_Price, Selling_Price,Quantity )values('"+item+"','"+code+"','"+cp+"','"+sp+"','"+quantity+"')");
if(ent.exec())
    {
        QMessageBox::information(this,tr("Information"),tr("Saved"));
        op.connclose();

        ui->item->clear();
        ui->code->clear();
        ui->cp->clear();
        ui->sp->clear();
        ui->quantity->clear();
    }
 else{
     QMessageBox::critical(this,tr("Information"),ent.lastError().text());
    }
}
/*else
{
    QMessageBox::information(this,tr("FAILED"),tr("DATA TYPE MISMATCHED:TRY AGAIN"));
}*/

if(item=="")
{

  //  a[0]="Item cannot be left open";
  ui->item->clear();
 }
 if(code=="")
{
//a[1]="You didn't enter code correctly";
ui->code->clear();
}

if(cp=="0"||cp=="")
{
//a[2]="You cannot leave the cost price empty or 0";
ui->cp->clear();
}

if(sp=="0"|| sp=="")
{
//a[3]="You cannot leave the selling price empty or 0";
ui->sp->clear();
}

if(quantity=="0"||quantity=="")
{
a[4]="You cannot leave qauntity empty or 0";
ui->quantity->clear();
}


}


void AddGoods::on_back_clicked()
{   this->close();
    Admin aa;
    aa.setModal(true);
    aa.exec();
}
