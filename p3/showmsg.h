#ifndef SHOWMSG_H
#define SHOWMSG_H

#include <QObject>

class ShowMsg : public QObject
{
    Q_OBJECT
public:
    explicit ShowMsg(QObject *parent = nullptr);

signals:

public slots:
    void RecvMsg(QString str);
    void RecvMsgvoid();
    void RecvDouble(double doubleNumber);
    void RecvNickName(const QString& string);
    void RecvValue(int value);
};

#endif // SHOWMSG_H
