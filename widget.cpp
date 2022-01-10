#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

Change::Change()
    :m500(0),m100(0),m50(0),m10(0){}

Change::Change(int m500_,int m100_,int m50_,int m10_)
    :m500(m500_),m100(m100_),m50(m50_),m10(m10_){}

Change::~Change(){}

int* Change::getNum(){
    int* box = new int[4];
    box[0] = this->m500;
    box[1] = this->m100;
    box[2] = this->m50;
    box[3] = this->m10;
    return box;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMlik->setEnabled(money >= 100);
}

Change Widget::getChange(){
    int box = this->money;
    int m500 = box/500;
    int m100 = (box-500*m500)/100;
    int m50 = (box-500*m500-100*m100)/50;
    int m10 = (box-500*m500-100*m100-50*m50)/10;
    return Change(m500,m100,m50,m10);
}

void Widget::setZero(){
    this->money = 0;
    ui->lcdNumber->display(money);
    setControl();
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMlik_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbReset_clicked()
{
    int* result = getChange().getNum();
    QString text =
            "500 won : " + QString::number(result[0])+
            "\n100 won : " + QString::number(result[1])+
            "\n 50 won : " + QString::number(result[2])+
            "\n 10 won : " + QString::number(result[3]);
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.exec();
    setZero();
    delete[] result;
}

