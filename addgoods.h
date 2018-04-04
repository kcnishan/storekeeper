#ifndef ADDGOODS_H
#define ADDGOODS_H

#include <QDialog>

namespace Ui {
class AddGoods;
}

class AddGoods : public QDialog
{
    Q_OBJECT

public:
    explicit AddGoods(QWidget *parent = 0);
    ~AddGoods();

private slots:
    void on_save_clicked();

    void on_back_clicked();

private:
    Ui::AddGoods *ui;
};

#endif // ADDGOODS_H
