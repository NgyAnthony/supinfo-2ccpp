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


void MainWindow::on_actionMove_to_Home_triggered()
{
    Home *home = new Home();
    setCentralWidget(home);
}

void MainWindow::on_actionMove_to_Table_triggered()
{
    Table *table = new Table();
    setCentralWidget(table);
}
