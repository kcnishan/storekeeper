#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>

namespace Ui {
class Display;
}

class Display : public QDialog
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    ~Display();

private slots:
    void on_pushButton_clicked();

    void on_go_clicked();

    void on_search_textChanged(const QString &arg1);

private:
    Ui::Display *ui;
};

#endif // DISPLAY_H
