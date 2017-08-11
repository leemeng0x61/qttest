#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QCryptographicHash>
#include <QRegExp>
#include <QRegExpValidator>
#include <QIntValidator>
#include <QCompleter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEditPsw->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setInputMask("HH:HH:HH:HH:HH:HH:HH");

    QRegExp re("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}"
               "(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegExpValidator *rev = new QRegExpValidator(re);
    ui->lineEdit_2->setValidator(rev);
    QIntValidator *portv = new QIntValidator(0,65535);
    ui->lineEdit_3->setValidator(portv);

    QStringList listDayOfWeek;
    listDayOfWeek<<"Monday"<<"Tuesday"<<"Wednesday"
                <<"Thursday"<<"Friday"<<"Saturday"<<"Sunday";
    QCompleter *cpQCompleter = new QCompleter(listDayOfWeek);
    cpQCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEditDay->setCompleter(cpQCompleter);

    QStringList listYear;
    listYear<<"2016"<<"2015"
            <<"2008"<<"2006"
            <<"1999"<<"1991";
    listYear.sort();
    //构建补全器
    QCompleter *cpYear = new QCompleter(listYear);
    //设置给 lineEditYear
    ui->lineEditYear->setCompleter(cpYear);
    //何夕名字列表
    QStringList listHeXi;
    listHeXi<<"何百夕"<<"何千夕"<<"何万夕"<<"何亿夕";
    //中文没有大小写敏感，也不要排序
    //构建补全器
    QCompleter *cpHexi = new QCompleter(listHeXi);
    //设置给 lineEditHeXi
    ui->lineEditHexi->setCompleter(cpHexi);
}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonLogin_clicked()
{
    //判断用户名密码是否为空
    if( ui->lineEditUser->text().isEmpty()
            || ui->lineEditPsw->text().isEmpty() )
    {
        QMessageBox::warning(this, tr("警告信息"), tr("用户名或密码为空，不能登录。"));
        return;
    }
    //用户名
    m_UserName = ui->lineEditUser->text();
    //计算密码 Hash
    m_Password = QCryptographicHash::hash( ui->lineEditPsw->text().toUtf8(),
                                           QCryptographicHash::Sha3_256 );
    //构造消息
    //添加用户名
    QString strMsg = tr("用户名：") + m_UserName+ tr("\r\n") + tr("密码 Hash：");
    //把每个 Hash 字节转成一对十六进制字符显示
    // 256 bit 对应 32 字节，变成 64 个十六进制字符打印
    strMsg += m_Password.toHex();

    qDebug()<<strMsg;
    //弹窗显示，注意：实际应用中会将用户名和密码 Hash 与数据库或配置文件里的做比较，而不是弹窗
    QMessageBox::information(this, tr("用户信息"), strMsg);
}

void Widget::on_pushButtonExit_clicked()
{
    this->close();
}

void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug()<<"MAC: "<<arg1;
}

void Widget::on_lineEdit_2_textChanged(const QString &arg1)
{
    qDebug()<<"IP: "<<arg1;
}

void Widget::on_lineEdit_3_textChanged(const QString &arg1)
{
    qDebug()<<"Port: "<<arg1;
}

void Widget::on_lineEditDay_textChanged(const QString &arg1)
{

}

void Widget::on_lineEditYear_textChanged(const QString &arg1)
{

}

void Widget::on_lineEditHexi_textChanged(const QString &arg1)
{

}
