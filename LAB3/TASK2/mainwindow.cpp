#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap image("/home/konstantin/QTProjects/OAIP_LABS/LAB3/TASK2/condition.png");
    ui->label_2->setPixmap(image);
    ui->label_2->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    strM = ui->lineEditM->text();
    strN = ui->lineEditN->text();
    m = strM.toLongLong(&correctM);
    n = strN.toLongLong(&correctN);
    if (!correctM && !correctN) {
        QMessageBox::critical(nullptr, "Ошибка", "Вы ввели неправильно оба числа!");
    }
    else if (!correctM) {
        QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод числа m!");
        return;
    }
    else if (!correctN) {
        QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод числа n!");
        return;
    }
    if (m == 0) {
        answer = n + 1;
    }
    else if (m > 0 && n == 0) {

    }
    else if (m > 0 && n > 0) {

    }
    else {
        QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод!"
                                                 " Числа должны быть неотрицательными и целыми");
    }
}

