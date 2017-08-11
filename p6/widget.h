#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButtonExit_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEditDay_textChanged(const QString &arg1);

    void on_lineEditYear_textChanged(const QString &arg1);

    void on_lineEditHexi_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    QString m_UserName;
    QByteArray m_Password;
};

#endif // WIDGET_H
