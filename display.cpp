#include "display.h"
#include "ui_display.h"
#include"login.h"

Display::Display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
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

Display::~Display()
{
    delete ui;
}

void Display::on_pushButton_clicked()
{
Display aa;
//ui->aa.adbut
}

void Display::on_go_clicked()
{
    QString search;
    search=ui->search->text();
    Login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *any=new QSqlQuery (conn.mydb);
    modal->setQuery(*any);
    any->prepare("select Item, Item_Code,Cost_price,Selling_Price,Quantity from entries where Item like '%"+search+"%' ");
    if(any->exec())
    {
        qDebug()<<"done";
    }
    modal->setQuery(*any);
    ui->tableView->setModel(modal);

}

void Display::on_search_textChanged(const QString &arg1)
{
    QString search;
    search=ui->search->text();
    Login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *any=new QSqlQuery (conn.mydb);
    modal->setQuery(*any);
    any->prepare("select Item, Item_Code,Cost_price,Selling_Price,Quantity from entries where Item like '%"+search+"%' ");
    if(any->exec())
    {
        qDebug()<<"done";
    }
    modal->setQuery(*any);
    ui->tableView->setModel(modal);
}
