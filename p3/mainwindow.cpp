#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include "showmsg.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));
    connect(ui->sendVoid,SIGNAL(clicked()),this,SIGNAL(SendVoidMsg()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_clicked()
{
    this->close();
}

void MainWindow::on_sendButton_clicked()
{
    emit SendMsg(tr("This is a Message!"));
}

const QString &MainWindow::nickName()
{
    return m_nickName;
}

int MainWindow::count()
{
    return m_count;
}

void MainWindow::setCount(int nNewCount)
{
    if(nNewCount == m_count)
    {
        return;
    }
    m_count = nNewCount;
    emit countChanged(nNewCount);
}

void MainWindow::setNickName(const QString &strNewName)
{
    if(strNewName == m_nickName)
    {
        return;
    }
    m_nickName = strNewName;
    emit nickNameChanged(strNewName);
}





