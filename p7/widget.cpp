#include "widget.h"
#include "ui_widget.h"
#include <signal.h>
#include <QDebug>
#include <QFont>
#include <QColorDialog>
#include <QBrush>
#include <QFontComboBox>
#include <QTextEdit>
#include <QLineEdit>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButtonBold->setCheckable(true);
    ui->pushButtonItalic->setCheckable(true);
    ui->pushButtonUnderline->setCheckable(true);

    QIntValidator *intValidator = new QIntValidator(0,70);
    ui->lineEdit->setValidator(intValidator);
    ui->lineEdit->setText(QString("").setNum(9));

    connect(ui->fontComboBox,SIGNAL(currentIndexChanged(QString)),ui->textEdit,SLOT(setFontFamily(QString)));


    ui->textEdit->setHtml("<b>粗体字的行<br></b>"
                          "<i>斜体字的行<br></i>"
                          "<u>下划线的行<br></u>"
                          "<font style=\"color:red;\">文本前景色<br></font>"
                          "<font style=\"background:yellow;\">文字背景色<br></font>"
                          "<font style=\"font-size:18pt;\">字号大小变化的行<br></font>"
                          "<font style=\"font-family:黑体;\">字体家族变化的行<br></font>"
                          );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonBold_clicked(bool checked)
{
    if(checked)
        ui->textEdit->setFontWeight(QFont::Bold);   //粗体
    else
        ui->textEdit->setFontWeight(QFont::Normal); //普通
}

void Widget::on_pushButtonItalic_clicked(bool checked)
{
    ui->textEdit->setFontItalic(checked);
}

void Widget::on_pushButtonUnderline_clicked(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
}

void Widget::on_pushButtonFgcolor_clicked()
{
    QColor qcl=QColorDialog::getColor(Qt::black);
    if(qcl.isValid()){
        ui->textEdit->setTextColor(qcl);
        QString strss = tr("color: %1").arg(qcl.name());
         ui->pushButtonFgcolor->setStyleSheet(strss);
    }
}

void Widget::on_pushButtonbgcolor_clicked()
{
    QColor qcl=QColorDialog::getColor(Qt::white);
    if(qcl.isValid()){
        ui->textEdit->setTextBackgroundColor(qcl);
        QString strss = tr("background: %1").arg(qcl.name());
         ui->pushButtonbgcolor->setStyleSheet(strss);
    }
}

void Widget::on_lineEdit_editingFinished()
{
    int s = ui->lineEdit->text().toInt();
    ui->textEdit->setFontPointSize(s);
}

void Widget::on_textEdit_currentCharFormatChanged(const QTextCharFormat &format)
{
    //粗体检测
        if(format.fontWeight() == QFont::Bold)
            ui->pushButtonBold->setChecked(true);
        else
            ui->pushButtonBold->setChecked(false);
        //斜体检测
        ui->pushButtonItalic->setChecked( format.fontItalic() );
        //下划线检测
        ui->pushButtonUnderline->setChecked( format.fontUnderline() );

        //文字前景色画刷，不一定有
        QBrush brushText = format.foreground();
        if( brushText != Qt::NoBrush )//有前景色画刷
        {
            QColor clrText = brushText.color();
            QString strSS = tr("color: %1").arg( clrText.name() );
            ui->pushButtonFgcolor->setStyleSheet( strSS );
        }
        else//没有前景色画刷 Qt::NoBrush
        {
            ui->pushButtonFgcolor->setStyleSheet("");
        }
        //文字背景画刷，不一定有
        QBrush brushBG = format.background();
        if( brushBG != Qt::NoBrush )//有背景色画刷
        {
            QColor clrBG = brushBG.color();
            QString strSSBG = tr("background: %1").arg(clrBG.name());
            ui->pushButtonbgcolor->setStyleSheet(strSSBG);
        }
        else//没背景画刷 Qt::NoBrush
        {
            ui->pushButtonbgcolor->setStyleSheet("");
        }

        //对于字号和字体家族检测，一定要用 QFont 的函数，不要用 QTextCharFormat 的函数
        //QTextCharFormat 的字号和字体家族函数不准，经常为 0 或空串
        QFont curFont = format.font();      //获取 QFont 成员
        int nFontSize = curFont.pointSize();//字号检测
        //如果是 px 形式， QFont::​pointSize() 函数返回 -1
        if( -1 == nFontSize ) //如果 pt 是 -1，是 px 格式
        {
            //如果是 px ，换算成 pt
            nFontSize = (int)( curFont.pixelSize() * 9.0 / 12.0 ) ;
        }
        ui->lineEdit->setText( QString("").setNum(nFontSize) );

        //字体家族检测
        QString strFontFamily = curFont.family();
        ui->fontComboBox->setCurrentText( strFontFamily );
}

void Widget::on_textEdit_textChanged()
{
    qDebug()<<ui->textEdit->toHtml()<<endl;   //打印丰富文本
    //qDebug()<<ui->textEdit->toPlainText();  //打印普通无格式文本
}
