#include "pantallacliente.h"
#include "ui_pantallacliente.h"
#include "formulariocita.h"
#include "historial.h"
#include <QMessageBox>
#include "citaspendientes.h"
PantallaCliente::PantallaCliente(gestorCitas& g, gestorClientes& gc, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::PantallaCliente)
    , gestor(g)
    , gestorCli(gc)
{
    ui->setupUi(this);
}

PantallaCliente::~PantallaCliente()
{
    delete ui;
}

void PantallaCliente::on_btnVerCitas_clicked()
{
    Historial ventanaHistorial(gestorCli, this);
    ventanaHistorial.exec();
}

void PantallaCliente::on_btnCitaspendientes_clicked()
{
    CitasPendientes ventana(gestor, this);
    ventana.exec();
}

void PantallaCliente::on_btnReservarCita_clicked()
{
    FormularioCita formulario(gestor, gestorCli, contadorId, this);
    formulario.exec();
}

void PantallaCliente::on_btnSalir_clicked()
{
    this->close();
}