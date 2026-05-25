#include "citaspendientes.h"
#include "ui_citaspendientes.h"
#include <QHeaderView>
#include <QTableWidgetItem>
#include "Cola.h"
#include "Cita.h"
#include"Diseno.h"

CitasPendientes::CitasPendientes(gestorCitas& g, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::CitasPendientes)
    , gestor(g)
{
    ui->setupUi(this);
    ui->tablaCita->setColumnCount(5);
    ui->tablaCita->setHorizontalHeaderLabels({ "Turno", "Servicio","Diseno", "Hora", "Estado" });
    ui->tablaCita->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablaCita->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablaCita->setSelectionBehavior(QAbstractItemView::SelectRows);
}

CitasPendientes::~CitasPendientes()
{
    delete ui;
}

void CitasPendientes::on_btnBuscar_clicked()
{
    string nombre = ui->inputNombre->text().toStdString();
    Cola<Cita> cola = gestor.getColaDia();
    int fila = 0;
    ui->tablaCita->setRowCount(0);
    int turno = 1;

    while (!cola.estaVacia()) {
        Cita c = cola.verFrente();
        cola.desencolar();

        if (c.getCliente() == nombre) {
            // Convertir estado a texto
            QString estadoTexto;
            if (c.getEstado() == PENDIENTE) estadoTexto = "Pendiente";
            else if (c.getEstado() == COMPLETADA) estadoTexto = "Completada";
            else estadoTexto = "Cancelada";

            ui->tablaCita->insertRow(fila);
            ui->tablaCita->setItem(fila, 0, new QTableWidgetItem(QString::number(turno)));
            ui->tablaCita->setItem(fila, 1, new QTableWidgetItem(
                QString::fromStdString(c.getServicio().getNombre())));
            ui->tablaCita->setItem(fila, 2, new QTableWidgetItem(
                QString::fromStdString(c.getDiseno().getNombre())));
            ui->tablaCita->setItem(fila, 3, new QTableWidgetItem(
                QString::fromStdString(c.getHora())));
            ui->tablaCita->setItem(fila, 4, new QTableWidgetItem(estadoTexto));
            fila++;
        }
        turno++;
    }

    if (fila == 0) {
        ui->label_2->setText("No se encontraron citas para " +
            QString::fromStdString(nombre));
    }
    else {
        ui->label_2->setText("Citas encontradas: " + QString::number(fila));
    }
}