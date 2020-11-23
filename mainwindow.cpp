#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "dialog.h"
#include "dialog.cpp"
#include "dialog1.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix(":/resource/img/Ninja Turtles.png");
    int w=ui->label->width();
    int h=ui->label->height();
    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    w=ui->label_3->width();
    h=ui->label_3->height();
    QPixmap pix1(":/resource/img/Don.png");
    ui->label_3->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
    w=ui->label_4->width();
    h=ui->label_4->height();
    QPixmap pix2(":/resource/img/Michelangelo.png");
    ui->label_4->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
    w=ui->label_5->width();
    h=ui->label_5->height();
    QPixmap pix3(":/resource/img/Raf (1).png");
    ui->label_5->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));

}
void MainWindow::resirvedelem(QString str)
{
    elem=str;
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


    if(ui->notrand->isChecked())
    {

            if(ui->Array->isChecked()){
                ArraySequence<int>* Arrint=new ArraySequence<int>;
                for(int i=0;i<ui->size->text().toInt();i++)
                {
                    int size=(ui->size->text()).toInt();
                    Dialog *fm = new Dialog(this,Arrint,size);
                    connect(this, &MainWindow::sendText, fm, &Dialog::resirvedText);
                    emit sendText(ui->size->text());

                    fm->show();
                }
            }
            else
            {
                ListSequence<int>* Arrint=new ListSequence<int>;
                for(int i=0;i<ui->size->text().toInt();i++)
                {
                    Dialog *fm = new Dialog(this,Arrint,Arrint->GetLength());
                    connect(this, &MainWindow::sendText, fm, &Dialog::resirvedText);
                    emit sendText(ui->size->text());

                    fm->show();
                }
            }

    }
    else
    {
        if(ui->Array->isChecked()){
            ArraySequence<int>* Arrint=new ArraySequence<int>;
            for(int i=0;i<ui->size->text().toInt();i++)
            {
                int elem=1 + rand() % 200;
                Arrint->Append(elem);
            }
            Dialog1 *fm = new Dialog1(this,Arrint,Arrint->GetLength());
            fm->show();
        }
        else
        {
            ListSequence<int>* Arrint=new ListSequence<int>;
            for(int i=0;i<ui->size->text().toInt();i++)
            {
                int elem=1 + rand() % 200;
                Arrint->Append(elem);
            }
            Dialog1 *fm = new Dialog1(this,Arrint,Arrint->GetLength());
            fm->show();
        }

    }



}
