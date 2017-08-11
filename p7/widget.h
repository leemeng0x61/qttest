#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextCharFormat>
#include <QPushButton>
#include <QIntValidator>

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
    void on_pushButtonBold_clicked(bool checked);

    void on_pushButtonItalic_clicked(bool checked);

    void on_pushButtonUnderline_clicked(bool checked);

    void on_pushButtonFgcolor_clicked();

    void on_pushButtonbgcolor_clicked();

    void on_lineEdit_editingFinished();

    void on_textEdit_currentCharFormatChanged(const QTextCharFormat &format);

    void on_textEdit_textChanged();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
