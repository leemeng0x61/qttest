#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_pGenderGroup = new QButtonGroup(this);
    m_pStatusGroup = new QButtonGroup(this);

    m_pGenderGroup->addButton(ui->radioButtonMan,0);
    m_pGenderGroup->addButton(ui->radioButtonWoman,1);

    m_pStatusGroup->addButton(ui->radioButtonBang,0);
    m_pStatusGroup->addButton(ui->radioButtonMeng,1);
    m_pStatusGroup->addButton(ui->radioButtonYao,2);

    connect(m_pGenderGroup,SIGNAL(buttonClicked(int)),this,SLOT(RecvGenderID(int)));
    connect(m_pStatusGroup,SIGNAL(buttonClicked(int)),this,SLOT(RecvStatusID(int)));
}

void Widget::RecvGenderID(int id)
{
    switch(id){
    case 0:
        qDebug()<<tr("男");
        break;
    case 1:
        qDebug()<<tr("女");
        break;
    default:
        break;
    }
}
void Widget::RecvStatusID(int id)
{
    switch(id){
    case 0:
        qDebug()<<tr("BangBangde");
        break;
    case 1:
        qDebug()<<tr("MengMengde");
        break;
    case 2:
        qDebug()<<tr("GaiChiYaole");
        break;
    default:
        break;
    }
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_radioButton0to19_toggled(bool checked)
{
    if(checked)qDebug()<<tr("0-19");else qDebug()<<tr("uncheck 0-19");

}

void Widget::on_radioButton20to39_toggled(bool checked)
{

    if(checked)qDebug()<<tr("20-39");else qDebug()<<tr("uncheck 20-39");
}

void Widget::on_radioButton40to59_toggled(bool checked)
{
    if(checked)qDebug()<<tr("40-59");else qDebug()<<tr("uncheck 40-59");

}

void Widget::on_radioButton60to_toggled(bool checked)
{
    if(checked)qDebug()<<tr("60-");else qDebug()<<tr("uncheck 60-");

}

void Widget::on_pushButton_clicked()
{    //结果字符串
    QString strResult;
    //性别分组
    int nGenderID = m_pGenderGroup->checkedId();    //获取被选中的 id
    switch (nGenderID) {
    case 0:
        strResult += tr("性别：男\r\n");
        break;
    case 1:
        strResult += tr("性别：女\r\n");
        break;
    default:
        strResult += tr("性别：未选中\r\n");
        break;
    }
    //状态分组
    int nStatusID = m_pStatusGroup->checkedId();    //获取被选中的 id
    switch (nStatusID) {
    case 0:
        strResult += tr("状态：棒棒哒\r\n");
        break;
    case 1:
        strResult += tr("状态：萌萌哒\r\n");
        break;
    case 2:
        strResult += tr("状态：该吃药了\r\n");
        break;
    default:
        strResult += tr("状态：未选中\r\n");
        break;
    }
    //年龄段四个按钮判断
    if( ui->radioButton0to19->isChecked() )
    {
        strResult += tr("年龄段：0-19\r\n");
    }
    else if( ui->radioButton20to39->isChecked() )
    {
        strResult += tr("年龄段：20-39\r\n");
    }
    else if( ui->radioButton40to59->isChecked() )
    {
        strResult += tr("年龄段：40-59\r\n");
    }
    else if( ui->radioButton60to->isChecked() )
    {
        strResult += tr("年龄段：60 以上\r\n");
    }
    else
    {
        strResult += tr("年龄段：未选中\r\n");
    }
    //strResult 获取信息完毕，弹窗显示
    QMessageBox::information(this, tr("综合信息"), strResult);
}
