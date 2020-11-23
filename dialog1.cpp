#include "dialog1.h"
#include "ui_dialog1.h"
#include <QPixmap>

#include<chrono>
Dialog1::Dialog1(QWidget *parent,Sequence<int>* Seq,int Size) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    size=Size;
    seq=Seq;
    QString str;
    ui->setupUi(this);
    QPixmap pix(":/resource/img/Leo.png");
    int w=ui->label->width();
    int h=ui->label->height();

    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    for(int i=0;i<Size;i++)
    {
        str=QString(str)+" "+(QString::number(seq->Get(i)));


    }


    ui->Box->setText(str);
}

Dialog1::~Dialog1()
{
    delete ui;
}


void Dialog1::on_pushButton_clicked()
{
    if(ui->Shell->isChecked())
    {
        shell_sort<int>* sort= new shell_sort<int>;
        auto start = std::chrono::system_clock::now();
        sort->Sort(seq, comp);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        double time=elapsed.count();
        QString str = QString::number(time);
        ui->time->setText(str);
        QString str1;
        for(int i=0;i<size;i++)
        {
            str1=QString(str1)+" "+(QString::number(seq->Get(i)));


        }


        ui->textEdit->setText(str1);


    }
    if(ui->Q_Sort->isChecked())
    {
        q_sort<int>* sort= new q_sort<int>;
        auto start = std::chrono::system_clock::now();
        sort->Sort(seq, comp);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        double time=elapsed.count();
        QString str = QString::number(time);
        ui->time->setText(str);
        QString str1;
        for(int i=0;i<size;i++)
        {
            str1=QString(str1)+" "+(QString::number(seq->Get(i)));


        }


        ui->textEdit->setText(str1);
    }
    if(ui->insert->isChecked())
    {
        InsertSorter<int>* sort= new InsertSorter<int>;
        auto start = std::chrono::system_clock::now();
        sort->Sort(seq, comp);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        double time=elapsed.count();
        QString str = QString::number(time);
        ui->time->setText(str);
        QString str1;
        for(int i=0;i<size;i++)
        {
            str1=QString(str1)+" "+(QString::number(seq->Get(i)));


        }


        ui->textEdit->setText(str1);
    }
}
