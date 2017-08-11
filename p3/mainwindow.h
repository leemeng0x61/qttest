#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //new add
    Q_PROPERTY(QString nickName MEMBER m_nickName NOTIFY nickNameChanged)
    Q_PROPERTY(int count MEMBER m_count NOTIFY countChanged)
    Q_PROPERTY(double value MEMBER m_value NOTIFY valueChanged)

    const QString& nickName();
    int count();

    Q_CLASSINFO("Version", "1.0.0")
    Q_CLASSINFO("Author", "Winland")
    Q_CLASSINFO("Site", "https://lug.ustc.edu.cn/sites/qtguide/")

signals :
    void SendMsg(QString str);
    void SendVoidMsg();
    void nickNameChanged(const QString& strNewName);
    void countChanged(int nNewCount);
    void valueChanged(double dblNewValue);

public slots:
    void on_button_clicked();
    void on_sendButton_clicked();
    void setCount(int newCount);
    void setNickName(const QString& newNickName);

private:
    Ui::MainWindow *ui;
    //prviate value
    QString m_nickName;
    int m_count;
    double m_value;
};

#endif // MAINWINDOW_H
