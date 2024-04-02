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

void MainWindow::on_pushButton_clicked()
{
    ui->output->clear();
    binaryInt.clear();
    binaryFr.clear();
    binaryTotal.clear();
    binaryFr = "";
    str = ui->input->text();
    value = str.toDouble(&correct);
    if (!correct && str[0] != '-') {
            QMessageBox::critical(nullptr, "Ошибка", "Неправильный ввод. Попробуйте снова.");
        return;
    }
    else {
        value = qAbs(value);
        integer = value / 1;
        fractional = value - integer;
        converting_integer(integer, binaryInt);
        if (value == 0 || str == "-0") {
            ui->output->setText("0");
            return;
        }
        else if (str[0] == '-') {
            binaryInt += ".1";
        }
        else {
            binaryInt += ".0";
        }
        std::reverse((binaryInt).begin(), binaryInt.end());
        if (fractional) {
            binaryInt = binaryInt + '.';
            converting_fractional(fractional, binaryFr);
        }
        binaryFr = binaryFr.left(11);
        binaryTotal = binaryInt + binaryFr;
        ui->output->setText(binaryTotal);
    }
}

int MainWindow::converting_integer(int &integer, QString &binary) {
    if (integer / 2 == 0) {
        binary += QString::number(integer % 2);
        return 0;
    }
    else {
        binary += QString::number(integer % 2);
        integer /= 2;
        return converting_integer(integer, binary);
    }
}

int MainWindow::converting_fractional(double &fractional, QString &binary)
{
    if (qAbs(fractional * 2 - 1) <= epsilon) {
        binary += '1';
        return 0;
    }
    else {
        fractional *=2;
        if (fractional >= 1) {
            binary += '1';
            fractional--;
        }
        else {
            binary += '0';
        }
        return converting_fractional(fractional, binary);
    }
}
