#ifndef USER_H
#define USER_H

#include <QDialog>

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = 0);
    ~user();

private slots:
    void on_pushButton_clicked();

    void on_search_clicked();

    void on_sale_clicked();

private:
    Ui::user *ui;
};

#endif // USER_H
