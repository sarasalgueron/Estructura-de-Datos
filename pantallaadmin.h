#pragma once
#ifndef PANTALLAADMIN_H
#define PANTALLAADMIN_H
#include "gestorCitas.h"
#include "gestorClientes.h"
#include <QDialog>

namespace Ui {
    class PantallaAdmin;
}

class PantallaAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit PantallaAdmin(gestorCitas& g, gestorClientes& gc, QWidget* parent = nullptr);
    ~PantallaAdmin();
private slots:
    void on_btnAtender_clicked();
    void on_btnNuevaCita_clicked();
    void on_btnHistorial_clicked();
    void on_btnSALIR_clicked();
    void actualizarTabla();
private:
    Ui::PantallaAdmin* ui;
    gestorCitas& gestor;
    gestorClientes& gestorCli;
    int contadorId = 1;
};

#endif // PANTALLAADMIN_H