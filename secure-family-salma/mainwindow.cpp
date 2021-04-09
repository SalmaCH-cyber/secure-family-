#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portes.h"
#include "electomenage.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    portes *m = new portes();
    m->show();
}

void MainWindow::on_pushButton_2_clicked()
{
   ELECTOMENAGE *m = new ELECTOMENAGE();
   m->show();
}
