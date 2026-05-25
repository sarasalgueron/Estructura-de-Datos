#pragma once
#ifndef PANTALLACLIENTE_H
#define PANTALLACLIENTE_H

#include <QDialog>
#include "gestorCitas.h"
#include "gestorClientes.h"

namespace Ui {
    class PantallaCliente;
}

class PantallaCliente : public QDialog
{
    Q_OBJECT

public:
    explicit PantallaCliente(gestorCitas& g, gestorClientes& gc, QWidget* parent = nullptr);
    ~PantallaCliente();

private slots:
    void on_btnVerCitas_clicked();
    void on_btnReservarCita_clicked();
    void on_btnSalir_clicked();
    void on_btnCitaspendientes_clicked();

private:
    Ui::PantallaCliente* ui;
    gestorCitas& gestor;
    gestorClientes& gestorCli;
    int contadorId = 1;
};

#endif // PANTALLACLIENTE_H
