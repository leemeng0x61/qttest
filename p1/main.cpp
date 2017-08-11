#include "mainwindow.h"
#include <QApplication>
#include <QTextBrowser>
#include <QDebug>

void TestSerialIn(const QByteArray& baIn)

{
   //输入流
   QDataStream dsIn(baIn); //只读的流，构造函数用常量引用
   //设置Qt串行化版本
   dsIn.setVersion(QDataStream::Qt_5_0);//使用Qt 5.0 版本流
   //变量
   int nVersion;
   double dblValue;
   QString strName;
   //串行化输入
   dsIn>>nVersion>>dblValue>>strName;

   //打印
   qDebug()<<nVersion;
   qDebug()<<fixed<<dblValue;
   qDebug()<<strName;
}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
    int nVersion = 1;

    double dblValue = 125.78999;
    QString strName = QObject::tr("This an example.");
    //字节数组保存结果
    QByteArray baResult;
    //串行化的流
    QDataStream ddOut(&baResult, QIODevice::ReadWrite);  //做输出，构造函数用指针
    //设置Qt串行化版本
    ddOut.setVersion(QDataStream::Qt_5_0);//使用Qt 5.0 版本流
    //串行化输出
    ddOut<<nVersion<<dblValue<<strName;
    //显示长度
    qDebug()<<baResult.length()<<"\t"<<qstrlen(baResult.data());
    //返回对象
    TestSerialIn(baResult);
//    return a.exec();
    return 0;
}
