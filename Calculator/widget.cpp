
#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMaximumSize(313, 429);
    this->setMinimumSize(313, 429);

    this->setWindowTitle("简单计算器");

    QFont f("微软雅黑", 14);    //更改字体和大小
        ui->lineEdit->setFont(f);

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton1_clicked()
{
    exp += "1";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton2_clicked()
{
    exp += "2";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton9_clicked()
{
    exp += "9";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton3_clicked()
{
    exp += "3";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton4_clicked()
{
    exp += "4";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton5_clicked()
{
    exp += "5";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton6_clicked()
{
    exp += "6";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton7_clicked()
{
    exp += "7";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton8_clicked()
{
    exp += "8";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButton0_clicked()
{
    exp += "0";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonzuokuo_clicked()
{
    exp += "(";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonyoukuo_clicked()
{
    exp += ")";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonchu_clicked()
{
    exp += "/";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonmul_clicked()
{
    exp += "*";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonpuls_clicked()
{
    exp += "+";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonjian_clicked()
{
    exp += "-";
    ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonclear_clicked()
{
    exp.clear();
    ui->lineEdit->clear();
}


void Widget::on_pushButtondel_clicked()
{
        exp.chop(1);
        ui->lineEdit->setText(exp);
}


void Widget::on_pushButtonequal_clicked()
{

}
