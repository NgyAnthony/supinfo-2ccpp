#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "home.h"
#include "table.h"

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

void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->homeWidget);
}

void MainWindow::on_tableButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->tableWidget);
}
