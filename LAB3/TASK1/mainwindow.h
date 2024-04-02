#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    int converting_integer(int &integer, QString &binary);
    int converting_fractional(double &fractional, QString &binary);

private:
    Ui::MainWindow *ui;
    const double epsilon = 1e-3;
    double value, fractional;
    int integer;
    QString binaryInt, binaryFr, binaryTotal, str;
    bool correct = true;
};
#endif // MAINWINDOW_H
