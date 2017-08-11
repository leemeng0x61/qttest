#include "mainwindow.h"
#include <QApplication>
#include "showmsg.h"
#include <QMetaClassInfo>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ShowMsg s;
    QObject::connect(&w,SIGNAL(SendVoidMsg()),&s,SLOT(RecvMsgvoid()));
    QObject::connect(&w,SIGNAL(SendMsg(QString)),&s,SLOT(RecvMsg(QString)));
    QObject::connect(&w,SIGNAL(valueChanged(double)),&s,SLOT(RecvDouble(double)));
    QObject::connect(&w,SIGNAL(nickNameChanged(QString)),&s,SLOT(RecvNickName(QString)));
    QObject::connect(&w,SIGNAL(countChanged(int)),&s,SLOT(RecvValue(int)));



    w.setNickName("Did");
    qDebug()<<w.nickName();
    w.setCount(100);
    qDebug()<<w.count();
    //通过 setProperty() 函数 和 property() 函数
    w.setProperty("value", 2.3456);
    qDebug()<<fixed<<w.property("value").toDouble();

    //    const QMetaObject *pMO = w.metaObject();
    QObject *pObj = &w;
    const QMetaObject *pMO = pObj->metaObject();
    int nInfoCount = pMO->classInfoCount();
    for(int i=0; i<nInfoCount; i++)
    {
        QMetaClassInfo info = pMO->classInfo(i);
        qDebug()<<info.name()<<"\t"<<info.value();
    }
    //基本信息

    qDebug()<<"Class Name: "<<pMO->className();
    qDebug()<<"Object Name: "<<w.objectName();

    //判断是否为基类
    qDebug()<<w.inherits("QWidget");
    qDebug()<<w.inherits("nothing");

    w.show();

    return a.exec();
}
