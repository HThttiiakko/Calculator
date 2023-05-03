
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
#include <string.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton9_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton0_clicked();

    void on_pushButtonzuokuo_clicked();

    void on_pushButtonyoukuo_clicked();

    void on_pushButtonchu_clicked();

    void on_pushButtonmul_clicked();

    void on_pushButtonpuls_clicked();

    void on_pushButtonjian_clicked();

    void on_pushButtonclear_clicked();

    void on_pushButtondel_clicked();


    void on_pushButtonequal_clicked();

private:
    Ui::Widget *ui;
    QString exp;

    int Priority(char ch);
};

#endif // WIDGET_H
