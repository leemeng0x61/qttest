#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QComboBox>
#include <QPushButton>
#include <QDateEdit>
#include <QMessageBox>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBoxCareer->setEditable(true);
    ui->dateEdit->setCalendarPopup(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_comboBoxSex_currentIndexChanged(int index)
{
   if(index<0)return;
   qDebug()<<"Gender:"<<ui->comboBoxSex->itemText(index);
}

void Widget::on_comboBoxCareer_currentTextChanged(const QString &arg1)
{
    qDebug()<<"Career:"<<arg1;
}

void Widget::on_dateEdit_dateChanged(const QDate &date)
{
    qDebug()<<date.toString("yyyy-MM-dd");

}

void Widget::on_pushButton_2_clicked()
{
    QString strResult;  //结果字符串
    //获取姓名
    strResult += tr("姓名：%1\r\n").arg( ui->lineEdit->text() );
    //性别
    strResult += tr("性别：%1\r\n").arg( ui->comboBoxSex->currentText() );
    //职业
    strResult += tr("职业：%1\r\n").arg( ui->comboBoxCareer->currentText() );
    //生日
    strResult += tr("生日：%1\r\n").arg( ui->dateEdit->date().toString() );
    //QDate::toString() 如果不带参数格式，自动按照本地化语言的日期格式返回字符串
    //额外功能，根据当前时间和用户生日，计算用户当前岁数
    QDateTime dtCur = QDateTime::currentDateTime();
    //计算岁数
    int nYears = dtCur.date().year() - ui->dateEdit->date().year();
    strResult += tr("岁数：%1").arg(nYears);
    QMessageBox::information(this, tr("信息"), strResult);
}

void Widget::on_pushButton_clicked()
{
   this->close();
}
