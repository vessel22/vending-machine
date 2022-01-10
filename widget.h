#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget;}
QT_END_NAMESPACE

class Change{

public:
    Change();
    Change(int m500_,int m100_,int m50_,int m10_);
    ~Change();
    int* getNum();

private:
    int m500;
    int m100;
    int m50;
    int m10;
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int money = 0 ;
    void changeMoney(int coin);
    void setControl();
    Change getChange();
    void setZero();

private slots:
    void on_pbCoin500_clicked();

    void on_pbCoin100_clicked();

    void on_pbCoin50_clicked();

    void on_pbCoin10_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbMlik_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
