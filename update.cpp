#include "update.h"
#include "ui_update.h"
#include"login.h"
#include <QMessageBox>
#include"admin.h"
Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
    on_pushButton_clicked();
}

Update::~Update()
{
    delete ui;

}

void Update::on_pushButton_2_clicked()
{
    Login op;
    bool ok;
    double c, s;
    int quant;
    QString item,code,quantity,cp,sp,a[5];
    //sn=ui->sn->text();
    item=ui->item->text();
    code=ui->code->text();
    c=ui->cp->text().toDouble(&ok);
    s=ui->sp->text().toDouble(&ok);

    cp= QString::number(c);
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
    ent.prepare("update entries set Item='"+item+"',Item_Code='"+code+"',Cost_Price='"+cp+"',Selling_Price='"+sp+"',Quantity='"+quantity+"' where Item_Code='"+code+"'");
if(ent.exec())
    {
        QMessageBox::information(this,tr("Edit"),tr("Updated"));
        op.connclose();
       // ui->sn->clear();
        ui->item->clear();
        ui->code->clear();
        ui->cp->clear();
        ui->sp->clear();
        ui->quantity->clear();
    }
 else{
     QMessageBox::critical(this,tr("Edit"),ent.lastError().text());
    }
}
/*else
{
    QMessageBox::information(this,tr("FAILED"),tr("DATA TYPE MISMATCHED:TRY AGAIN"));
}*/

if(item=="")
{

    a[0]="Enter the Item name";
  ui->item->clear();
 }
 if(code=="")
{
a[1]="Enter the item code";
ui->code->clear();
}

if(cp=="0"||cp=="")
{
a[2]="Enter the Cost Price(NRs.)";
ui->cp->clear();
}

if(sp=="0"|| sp=="")
{
a[3]="Enter the Selling Price(NRs.)";
ui->sp->clear();
}

if(quantity=="0"||quantity=="")
{
a[4]="Enter the appropriate quantity";
ui->quantity->setText(a[4]);
}

on_pushButton_clicked();


}

void Update::on_pushButton_clicked()
{
    Login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);
    qry->prepare("select Item ,Item_Code,Cost_Price, Selling_Price,Quantity from entries");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connclose();
}

void Update::on_tableView_activated(const QModelIndex &index)
{
    //QString item,code,date,cp,sp;
    QString val=ui->tableView->model()->data(index).toString();
    Login log;
    if(!log.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;

    }
    log.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from entries where Item='"+val+"' or Item_Code='"+val+"' or Cost_Price='"+val+"' or Selling_Price='"+val+"' or Quantity='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
    {
           // ui->sn->setText(qry.value(0).toString());
            ui->item->setText(qry.value(1).toString());
            ui->code->setText(qry.value(2).toString());
            ui->cp->setText(qry.value(3).toString());
            ui->sp->setText(qry.value(4).toString());
            ui->quantity->setText(qry.value(5).toString());

    }
        log.connclose();
    }
    else
    {
        QMessageBox::critical(this,tr("ERROR::"),qry.lastError().text());
    }
}

void Update::on_pushButton_3_clicked()
{
    this->close();
    Admin admin;
    admin.setModal(true);
    admin.exec();
}

void Update::on_go_clicked()
{
    QString search;
    search=ui->search_line->text();
    Login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *any=new QSqlQuery (conn.mydb);
    modal->setQuery(*any);
    any->prepare("select Item, Item_Code,Cost_price,Selling_Price,Quantity from entries where Item like '"+search+"' ");
    any->exec();
    modal->setQuery(*any);
    ui->tableView->setModel(modal);
    conn.connclose();
}

void Update::on_search_line_textChanged(const QString &arg1)
{
    QString search;
    search=ui->search_line->text();
    Login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *any=new QSqlQuery (conn.mydb);
    modal->setQuery(*any);
    any->prepare("select Item, Item_Code,Cost_price,Selling_Price,Quantity from entries where Item like '%"+search+"%' ");
    any->exec();
    modal->setQuery(*any);
    ui->tableView->setModel(modal);
    conn.connclose();
}
