#ifndef LOGIN_H
#define LOGIN_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    explicit Login(QWidget *parent = 0);
    ~Login();


public:
    void connclose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb =QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("S:/Project/build-MY_store-Desktop-Debug/database.db");
        if(!mydb.open())
            return false;
        else
            return true;
    }

private slots:
    void on_adra_clicked();

    void on_usra_clicked();

    void on_adbut_clicked();

    void on_usbut_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

private:
    Ui::Login *ui;
    //QSqlDatabase mydb;

};

#endif // LOGIN_H
