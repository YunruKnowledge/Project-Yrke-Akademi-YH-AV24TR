#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int firstNum;
int secondNum;
int resoult;

void MainWindow::on_btnAdd_clicked()
{
    firstNum = ui->inpFirstNum->text().toInt();
    secondNum = ui->inpSecondNum->text().toInt();

    resoult = firstNum + secondNum;
    ui->outResoult->setText(QString::number(resoult));
}


void MainWindow::on_btnSub_clicked()
{
    firstNum = ui->inpFirstNum->text().toInt();
    secondNum = ui->inpSecondNum->text().toInt();

    resoult = firstNum - secondNum;
    ui->outResoult->setText(QString::number(resoult));
}


void MainWindow::on_btnDevide_clicked()
{
    firstNum = ui->inpFirstNum->text().toInt();
    secondNum = ui->inpSecondNum->text().toInt();

    resoult = firstNum / secondNum;
    ui->outResoult->setText(QString::number(resoult));
}


void MainWindow::on_btnMulti_clicked()
{
    firstNum = ui->inpFirstNum->text().toInt();
    secondNum = ui->inpSecondNum->text().toInt();

    resoult = firstNum * secondNum;
    ui->outResoult->setText(QString::number(resoult));
}

