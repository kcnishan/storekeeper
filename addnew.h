#ifndef ADDNEW_H
#define ADDNEW_H

#include <QDialog>

namespace Ui {
class Addnew;
}

class Addnew : public QDialog
{
    Q_OBJECT

public:
    explicit Addnew(QWidget *parent = 0);
    ~Addnew();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Addnew *ui;
};

#endif // ADDNEW_H
