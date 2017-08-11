#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->checkBox_7->setTristate(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_checkBox_toggled(bool checked)
{
    if (checked)qDebug()<<tr(__FUNCTION__);
    CheckHobbies();
}

void Widget::on_checkBox_2_toggled(bool checked)
{
    if (checked)qDebug()<<tr(__FUNCTION__);
    CheckHobbies();

}

void Widget::on_checkBox_3_toggled(bool checked)
{
    if (checked)qDebug()<<tr(__FUNCTION__);
    CheckHobbies();

}

void Widget::on_checkBox_4_toggled(bool checked)
{
    if (checked)qDebug()<<tr(__FUNCTION__);
    CheckHobbies();

}

void Widget::on_checkBox_5_toggled(bool checked)
{
    if (checked)qDebug()<<tr(__FUNCTION__);
    CheckHobbies();
QDesktopServices::openUrl( QUrl("file:///D:/QtProjects") );
}

void Widget::on_checkBox_6_toggled(bool checked)
{
    if (checked)qDebug()<<tr(__FUNCTION__);
    CheckHobbies();

}

void Widget::on_pushButton_clicked()
{
    QString str = tr("Interesting:\n");
    if(ui->checkBox->isChecked())str+=tr("Reading\n");
    if(ui->checkBox->isChecked())str+=tr("Climbing \n");
    if(ui->checkBox->isChecked())str+=tr("Swimming\n");
    if(ui->checkBox->isChecked())str+=tr("Dazing\n");
    if(ui->checkBox->isChecked())str+=tr("Shopping\n");
    if(ui->checkBox->isChecked())str+=tr("Eatting\n");

    QMessageBox::information(this,"Interesting",str);

}

void Widget::on_commandLinkButton_clicked()
{
    QDesktopServices::openUrl(QUrl("file:///"));
}

void Widget::on_commandLinkButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.p-v-q.com"));
}

void Widget::CheckHobbies()
{
    int count = 0;  //兴趣计数
    if(ui->checkBox->isChecked())count++;
    if(ui->checkBox_2->isChecked())count++;
    if(ui->checkBox_3->isChecked())count++;
    if(ui->checkBox_4->isChecked())count++;
    if(ui->checkBox_5->isChecked())count++;
    if(ui->checkBox_6->isChecked())count++;

     //根据兴趣计数设置三态按钮的状态
     if( count <= 0)
     {
         ui->checkBox_7->setCheckState(Qt::Unchecked);
         return;
     }
     else if( count < 6 )
     {
         ui->checkBox_7->setCheckState(Qt::PartiallyChecked);
         return;
     }
     else
     {
         ui->checkBox_7->setCheckState(Qt::Checked);
         return;
     }
}
