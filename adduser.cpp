#include "adduser.h"
#include "ui_adduser.h"
#include"login.h"
#include"changedialog.h"
adduser::adduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adduser)
{
    ui->setupUi(this);


}

adduser::~adduser()
{
    delete ui;
}

void adduser::on_pushButton_clicked()
{
    Login op;

    QString username,nickname,friendname,uncle;
    //sn=ui->sn->text();
   friendname=ui->line_friend->text();
    username=ui->line_username->text();
    uncle=ui->line_uncle->text();
    nickname=ui->line_nickname->text();


    op.connOpen();
    QSqlQuery ent;
    ent.prepare("select * from login where (username='"+username+"'and ad_friendname='"+friendname+"'and ad_nickname='"+nickname+"'and ad_unclename='"+uncle+"')or(saleus='"+username+"'and us_friendname='"+friendname+"'and us_nickname='"+nickname+"'and us_unclename='"+uncle+"')");
    if(ent.exec())
    {
        if(ent.next())
        {
            op.connclose();
            this->close();
             ChangeDialog aa;
             aa.setModal(this);
             aa.exec();
        }

    }
}
