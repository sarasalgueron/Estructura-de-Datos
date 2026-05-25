#include "formulariocita.h"
#include "ui_formulariocita.h"
#include "Cita.h"
#include "Servicio.h"
#include "Cliente.h"
#include <QMessageBox>

FormularioCita::FormularioCita(gestorCitas& g, gestorClientes& gc, int& contador, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FormularioCita)
    , gestor(g)
    , gestorCli(gc)
    , contadorId(contador)
{
    ui->setupUi(this);
    ui->comboServicio->addItem("Manicure");
    ui->comboServicio->addItem("Nail Art");
    ui->comboServicio->addItem("Pedicure");
    ui->comboServicio->addItem("Gelish");
}

FormularioCita::~FormularioCita()
{
    delete ui;
}

void FormularioCita::on_btnGuardar_clicked()
{
    string nombre = ui->inputNombre->text().toStdString();
    if (nombre.empty()) {
        QMessageBox::warning(this, "Error", "Por favor ingresa el nombre");
        return;
    }

    Servicio s(ui->comboServicio->currentIndex() + 1,
        30,
        ui->comboServicio->currentText().toStdString(),
        15.0);

    int dia = ui->dateEdit->date().day();
    int mes = ui->dateEdit->date().month();
    int hora = ui->timeEdit->time().hour();
    int minutos = ui->timeEdit->time().minute();

    Diseno d;
    Cita c(contadorId++, nombre, s, d, mes, dia, minutos, hora);

    // Agregar cita a la cola del día
    gestor.reservarCita(c);

    // Buscar clienta, si no existe registrarla
    Cliente* clienta = gestorCli.buscarCliente(nombre);
    if (clienta == nullptr) {
        Cliente nuevaCliente(contadorId, nombre, 0);
        nuevaCliente.agregarCita(c);
        gestorCli.registrarCliente(nuevaCliente);
    }
    else {
        clienta->agregarCita(c);
    }

    QMessageBox::information(this, "Éxito", "Cita registrada correctamente!");
    this->close();
}