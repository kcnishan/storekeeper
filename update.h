#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>

namespace Ui {
class Update;
}

class Update : public QDialog
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = 0);
    ~Update();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_go_clicked();

    void on_search_line_textChanged(const QString &arg1);

private:
    Ui::Update *ui;
};

#endif // UPDATE_H
