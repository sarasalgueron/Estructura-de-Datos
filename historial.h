#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "gestorClientes.h"

#include <QDialog>

namespace Ui {
    class Historial;
}

class Historial : public QDialog
{
    Q_OBJECT

public:
    explicit Historial(gestorClientes& gc, QWidget* parent = nullptr);
    ~Historial();

private slots:
    void on_btnBuscar_clicked();
    void on_btnSalir_clicked();
private:
    Ui::Historial* ui;
    gestorClientes& gestorCli;

};

#endif // HISTORIAL_H