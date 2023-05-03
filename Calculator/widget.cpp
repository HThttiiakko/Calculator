
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
        QStack<int> s_num, s_opt;  //模板类存为int

        char opt[128] = {0};
        int i = 0, tmp = 0, num1, num2;

        //把QString转换成char *
        QByteArray ba;
        ba.append(exp);   //把QString转换成QByteArray
        strcpy(opt, ba.data());  //data可以把QByteArray转换成const char *

        while (opt[i] != '\0' || s_opt.empty() != true)
        {
            if (opt[i] >= '0' && opt[i] <= '9')
            {
                tmp = tmp * 10 + opt[i] - '0';
                i++;
                if (opt[i] < '0' || opt[i] > '9')
                {
                    s_num.push(tmp);
                    tmp = 0;
                }
            }
            else           //操作符
            {
                if (s_opt.empty() == true || Priority(opt[i]) > Priority(s_opt.top()) ||
                    (s_opt.top() == '(' && opt[i] != ')'))
                {
                    s_opt.push(opt[i]);
                    i++;
                    continue;
                }

                if (s_opt.top() == '(' && opt[i] == ')')
                {
                    s_opt.pop();
                    i++;
                    continue;
                }

                if (Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == ')' && s_opt.top() != '(') ||
                    (opt[i] == '\0' && s_opt.empty() != true))
                {
                    char ch = s_opt.top();
                    s_opt.pop();
                    switch(ch)
                    {
                    case '+':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 + num2);
                        break;
                    case '-':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 - num2);
                        break;
                    case '*':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 * num2);
                        break;
                    case '/':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 / num2);
                        break;
                    }
                }
            }
        }
        ui->lineEdit->setText(QString::number(s_num.top()));//将int类型转换为QString类型
        exp.clear();
}

int Widget::Priority(char ch)
{
        switch(ch)
        {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
        }
}
