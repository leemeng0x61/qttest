#include "widget.h"
#include "ui_widget.h"
#include <QTextBrowser>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QUrl>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
    ui->textBrowser->setOpenExternalLinks(true);
    ui->pushButtonBackward->setEnabled(false);
    ui->pushButtonForward->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonOpenHtml_clicked()
{
    QUrl urlFile = QFileDialog::getOpenFileUrl(this, "open HTML", QUrl(), "HTML files(*.htm *.html)");
    //URL 非空，才进行打开操作
    if( ! urlFile.isEmpty())
    {
        //打印文件链接
        qDebug()<<urlFile;
        //设置浏览的源文件
        ui->textBrowser->setSource(urlFile);
    }
}

void Widget::on_pushButtonForward_clicked()
{
    ui->textBrowser->forward();
}

void Widget::on_pushButtonBackward_clicked()
{
    ui->textBrowser->backward();
}

void Widget::on_textBrowser_backwardAvailable(bool arg1)
{
    ui->pushButtonBackward->setEnabled(arg1);
}

void Widget::on_textBrowser_forwardAvailable(bool arg1)
{
    ui->pushButtonForward->setEnabled(arg1);
}

void Widget::on_textBrowser_textChanged()
{
    QString str = ui->textBrowser->toHtml();
    ui->plainTextEdit->setPlainText(str);

}

void Widget::on_pushButtonExit_clicked()
{
   this->close();
}
