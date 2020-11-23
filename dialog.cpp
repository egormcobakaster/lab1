#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "dialog1.h"
Dialog::Dialog(QWidget *parent, Sequence<int>* Seq, int Size) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    size=Size;
    seq=Seq;
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::resirvedText(QString str)
{
    ui->resirvedText->setText(str);
}




void Dialog::on_pushButton_clicked()
{
    if (size>seq->GetLength())
    {
        seq->Append(ui->elem->text().toInt());
    }
    ui->elem->setText(" ");
    ui->resirvedText->setText(QString::number(size-seq->GetLength()));

}

void Dialog::on_pushButton_2_clicked()
{
    hide();
    Dialog1 *fm = new Dialog1(this,seq,seq->GetLength());
    fm->show();
}
