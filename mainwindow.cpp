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
    QString ingresoDatos =ui->ingresoDatos->toPlainText();
    DatosCliente cliente(ingresoDatos.toStdString());

    ui->linecedula->setText(QString::fromStdString(cliente.getCedula()));
    ui->nombres->setText(QString::fromStdString(cliente.getNombre()));
    ui->apellido->setText(QString::fromStdString(cliente.getApellido()));
    ui->direccion->setText(QString::fromStdString(cliente.getDireccion()));
    ui->telefono->setText(QString::fromStdString(cliente.getTelefono()));
    ui->email->setText(QString::fromStdString(cliente.getEmail()));
}


void MainWindow::on_actionplantilla_para_insertar_datos_triggered()
{
    Dialog ventana;
    ventana.exec();
}

