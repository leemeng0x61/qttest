#include <QCoreApplication>
#include <QApplication>
#include <QTextBrowser>
#include <QDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //打印字符串和数字混搭
    streamOut<<QObject::tr("7*7 == ")<<7*7<<endl;
    //显示现在的字符串对象
    qDebug()<<strOut;
    //内存输入流
    QString strIn = QObject::tr("800  abcd  123.789999");
    QTextStream streamIn(&strIn);
    int numDec = 0;
    QString strSub;
    double dblReal = 0.0;
    //输入到变量里
    streamIn>>numDec>>strSub>>dblReal;
    //显示
    qDebug()<<numDec;
    qDebug()<<strSub;
    qDebug()<<fixed<<dblReal;   //定点数显示

    return a.exec();
}
