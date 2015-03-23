#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complexo.h"
#include "matriz.h"
#include "QStandardItemModel"
#include <QtWidgets/QPlainTextEdit>

QPlainTextEdit *Saida;
Matriz mata(10,10);
Matriz matb(10,10);
Matriz matc(10,3);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Saida = ui->plainTextEdit;

    QStandardItemModel *model = new QStandardItemModel();
    ui->tabelaA->setModel(model);

    model = new QStandardItemModel();
    ui->tabelaB->setModel(model);

    model = new QStandardItemModel();
    ui->tabelaC->setModel(model);

    model = new QStandardItemModel();
    ui->tabelaResultado->setModel(model);

    mata.gerarValoresRandomicos();
    matb.gerarValoresRandomicos();
    matc.gerarValoresRandomicos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Complexo comp;
    Complexo b(9);
    Complexo c (3, 2);
    comp = b + 5;
    comp = comp - c;
    comp = comp * b;
    comp = comp + c * (b + 7);
    comp.print();

    QStandardItemModel *modelo = (QStandardItemModel*)ui->tabelaA->model();
    mata.print(modelo);

    modelo = (QStandardItemModel*)ui->tabelaB->model();
    matb.print(modelo);

    modelo = (QStandardItemModel*)ui->tabelaC->model();
    matc.print(modelo);

    modelo = (QStandardItemModel*)ui->tabelaResultado->model();
    Matriz x = mata + matb;
    Matriz y = mata - matb;
    Matriz matResultado = ((x + y) - mata + matb) * matc;
    matResultado.print(modelo);
}
