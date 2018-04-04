#ifndef STOREKEEPER_H
#define STOREKEEPER_H
#include <QMainWindow>
#include"credit.h"

namespace Ui {
class StoreKeeper;
}

class StoreKeeper : public QMainWindow
{
    Q_OBJECT

public:
    explicit StoreKeeper(QWidget *parent = 0);
    ~StoreKeeper();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::StoreKeeper *ui;
};

#endif // STOREKEEPER_H
