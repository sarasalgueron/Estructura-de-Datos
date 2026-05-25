#include "pantallaadmin.h"
#include "formulariocita.h"
#include "ui_pantallaadmin.h"
#include <QHeaderView>
#include <QTableWidgetItem>
#include "Cola.h"
#include "Cita.h"
#include "Servicio.h"
#include "historial.h"
#include "Diseno.h"
PantallaAdmin::PantallaAdmin(gestorCitas& g, gestorClientes& gc, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::PantallaAdmin)
    , gestor(g)
    , gestorCli(gc)
{
    ui->setupUi(this);

    // Configurar columnas de la tabla
    ui->TablaCola->setColumnCount(5);
    ui->TablaCola->setHorizontalHeaderLabels({ "Nombre", "Turno", "Servicio", "Diseno", "Hora" });
    ui->TablaCola->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->TablaCola->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TablaCola->setSelectionBehavior(QAbstractItemView::SelectRows);

    actualizarTabla();
}

PantallaAdmin::~PantallaAdmin()
{
    delete ui;
}

void PantallaAdmin::actualizarTabla()
{
    Cola<Cita> cola = gestor.getColaDia();
    int fila = 0;
    ui->TablaCola->setRowCount(cola.getTamano());
    ui->LabelContador->setText("Citas pendientes" + QString::number(cola.getTamano()));
    while (!cola.estaVacia()) {
        Cita c = cola.verFrente();
        cola.desencolar();
        ui->TablaCola->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(c.getCliente())));
        ui->TablaCola->setItem(fila, 1, new QTableWidgetItem(QString::number(fila + 1)));
        ui->TablaCola->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(c.getServicio().getNombre())));
        ui->TablaCola->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(c.getDiseno().getNombre())));
        ui->TablaCola->setItem(fila, 4, new QTableWidgetItem(QString::fromStdString(c.getHora())));
        fila++;
    }

}

void PantallaAdmin::on_btnAtender_clicked()
{
    if (!gestor.getColaDia().estaVacia()) {
        Cita c = gestor.getColaDia().verFrente();
        gestor.completarCita(c);
        actualizarTabla();
    }
}
void PantallaAdmin::on_btnNuevaCita_clicked()
{
    FormularioCita formulario(gestor, gestorCli, contadorId, this);
    formulario.exec();
    actualizarTabla();
}
void PantallaAdmin::on_btnHistorial_clicked() {
    Historial ventanaHistorial(gestorCli, this);
    ventanaHistorial.exec();
}
void PantallaAdmin::on_btnSALIR_clicked()
{
    this->close();
}