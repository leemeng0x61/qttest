#include "showmsg.h"
#include <qmessagebox.h>
#include <qdebug.h>

ShowMsg::ShowMsg(QObject *parent) : QObject(parent)
{

}

void ShowMsg::RecvMsg(QString str)
{
    QMessageBox::information(NULL,tr("show"),str);
}

void ShowMsg::RecvMsgvoid()
{
    QMessageBox::information(NULL,tr("show"),"str");
}

void ShowMsg::RecvDouble(double doubleNumber)
{
    qDebug()<<"RecvDouble: "<<fixed<<doubleNumber;
}

void ShowMsg::RecvNickName(const QString &string)
{
    qDebug()<<"RecvNickName: "<<fixed<<string;
}

void ShowMsg::RecvValue(int value)
{
    qDebug()<<"RecvValue: "<<fixed<<value;
}
