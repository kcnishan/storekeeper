#include "sales.h"
#include "ui_sales.h"
#include"login.h"
sales::sales(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sales)
{
    ui->setupUi(this);
   /* QString search;
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
    */
}

sales::~sales()
{
    delete ui;
}

void sales::on_fontComboBox_activated(const QString &arg1)
{

}

void sales::on_combo_currentTextChanged(const QString &arg1)
{

}

void sales::on_combo_activated(const QString &arg1)
{
    Login conn;
    QSqlQueryModel *modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *any=new QSqlQuery (conn.mydb);
    modal->setQuery(*any);
    any->prepare("select Item from entries");
    any->exec();
    modal->setQuery(*any);
    ui->combo->setModel(modal);
    conn.connclose();

}
