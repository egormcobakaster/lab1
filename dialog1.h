#ifndef DIALOG1_H
#define DIALOG1_H
#include "Header.h"
#include <QDialog>
#include"Sorter.h"
namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    int size;
    Sequence<int>* seq;
    explicit Dialog1(QWidget *parent = nullptr, Sequence<int>* Seq=nullptr, int Size=0);
    ~Dialog1();

private slots:

    void on_pushButton_clicked();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
