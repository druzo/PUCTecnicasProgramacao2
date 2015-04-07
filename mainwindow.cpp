#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "complexo.h"
#include "matriz.h"
#include "QStandardItemModel"
#include <QtWidgets/QPlainTextEdit>
#include "testetemplate.h"

QPlainTextEdit *Saida;
TesteTemplate<int> testeTemp;


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

    ui->qtdeColunas->setText("10");
    ui->qtdeLinhas->setText("10");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Matriz<int> mata(ui->qtdeLinhas->text().toInt(), ui->qtdeColunas->text().toInt());
    Matriz<int> matb(ui->qtdeLinhas->text().toInt(), ui->qtdeColunas->text().toInt());
    Matriz<int> matc(ui->qtdeLinhas->text().toInt(), 3);

    mata.gerarValoresRandomicos();
    matb.gerarValoresRandomicos();
    matc.gerarValoresRandomicos();

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
    Matriz<int> x = mata + matb;
    Matriz<int> y = mata - matb;
    Matriz<int> matResultado = ((x + y) - mata + matb) * matc;
    matResultado.print(modelo);


}
