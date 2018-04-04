#ifndef SALES_H
#define SALES_H

#include <QDialog>

namespace Ui {
class sales;
}

class sales : public QDialog
{
    Q_OBJECT

public:
    explicit sales(QWidget *parent = 0);
    ~sales();

private slots:
    void on_fontComboBox_activated(const QString &arg1);

    void on_combo_currentTextChanged(const QString &arg1);

    void on_combo_activated(const QString &arg1);

private:
    Ui::sales *ui;
};

#endif // SALES_H
