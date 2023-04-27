#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
    checkMoney();
}

void Widget::checkMoney() {
    if(money >= 100) {
        ui->pbCoffee->setEnabled(true);
    } else ui->pbCoffee->setEnabled(false);
    if(money >= 150) {
        ui->pbTea->setEnabled(true);
    } else ui->pbTea->setEnabled(false);
    if(money >= 200) {
        ui->pbMilk->setEnabled(true);
    } else ui->pbMilk->setEnabled(false);
}

int Widget::countMoney(int unit) {
    int count = 0;
    while(money >= unit) {
        money -= unit;
        count++;
    }
    return count;
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msg;
    int coin500;
    int coin100;
    int coin50;
    int coin10;;
    char temp[150];

    coin500 = countMoney(500);
    coin100 = countMoney(100);
    coin50 = countMoney(50);
    coin10 = countMoney(10);

    sprintf(temp,"500 : %d\n100 : %d\n50 : %d\n10 : %d\n", coin500, coin100, coin50, coin10);

    msg.information(nullptr,"Changes",temp);
    money = 0;
    checkMoney();
    ui->lcdNumber->display(money);
}
