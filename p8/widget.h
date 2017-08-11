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
    void on_pushButtonOpenHtml_clicked();

    void on_pushButtonForward_clicked();

    void on_pushButtonBackward_clicked();

    void on_textBrowser_backwardAvailable(bool arg1);

    void on_textBrowser_forwardAvailable(bool arg1);

    void on_textBrowser_textChanged();

    void on_pushButtonExit_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
