#ifndef FORMULARIOCITA_H
#define FORMULARIOCITA_H

#include <QDialog>
#include "gestorCitas.h"
#include "gestorClientes.h"

namespace Ui {
    class FormularioCita;
}

class FormularioCita : public QDialog
{
    Q_OBJECT

public:
    explicit FormularioCita(gestorCitas& g, gestorClientes& gc, int& contador, QWidget* parent = nullptr);
    ~FormularioCita();

private slots:
    void on_btnGuardar_clicked();

private:
    Ui::FormularioCita* ui;
    gestorCitas& gestor;
    gestorClientes& gestorCli;
    int& contadorId;
};

#endif // FORMULARIOCITA_H