#include "historial.h"
#include "ui_historial.h"
#include <QHeaderView>
#include <QTableWidgetItem>

Historial::Historial(gestorClientes& gc, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Historial)
    , gestorCli(gc)
{
    ui->setupUi(this);

    // Configurar columnas de la tabla
    ui->tablaHistorial->setColumnCount(4);
    ui->tablaHistorial->setHorizontalHeaderLabels({ "Servicio", "Diseno", "Hora","Estado" });
    ui->tablaHistorial->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaHistorial->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablaHistorial->setSelectionBehavior(QAbstractItemView::SelectRows);
}

Historial::~Historial()
{
    delete ui;
}

void Historial::on_btnBuscar_clicked()
{
    string nombre = ui->inputnombre->text().toStdString();
    Cliente* c = gestorCli.buscarCliente(nombre);

    if (c != nullptr) {
        ui->resultado->setText("Clienta encontrada: " +
            QString::fromStdString(nombre));

        Pila<Cita> historial = c->verHistorial();
        ui->tablaHistorial->setRowCount(0);
        int fila = 0;

        while (!historial.estaVacia()) {
            Cita cita = historial.verCima();
            historial.desapilar();

            QString estadoTexto;
            if (cita.getEstado() == PENDIENTE) estadoTexto = "Pendiente";
            else if (cita.getEstado() == COMPLETADA) estadoTexto = "Completada";
            else estadoTexto = "Cancelada";

            ui->tablaHistorial->insertRow(fila);
            ui->tablaHistorial->setItem(fila, 0, new QTableWidgetItem(
                QString::fromStdString(cita.getServicio().getNombre())));
            ui->tablaHistorial->setItem(fila, 1, new QTableWidgetItem(
                QString::fromStdString(cita.getDiseno().getNombre())));
            ui->tablaHistorial->setItem(fila, 2, new QTableWidgetItem(
                QString::fromStdString(cita.getHora())));
            ui->tablaHistorial->setItem(fila, 3, new QTableWidgetItem(estadoTexto));
            fila++;
        }
    }
    else {
        ui->resultado->setText("Clienta no encontrada");
        ui->tablaHistorial->setRowCount(0);
    }
}
void Historial::on_btnSalir_clicked()
{
    this->close();
}