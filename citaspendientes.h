#pragma once
#ifndef CITASPENDIENTES_H
#define CITASPENDIENTES_H

#include <QDialog>
#include "gestorCitas.h"

namespace Ui {
    class CitasPendientes;
}

class CitasPendientes : public QDialog
{
    Q_OBJECT

public:
    explicit CitasPendientes(gestorCitas& g, QWidget* parent = nullptr);
    ~CitasPendientes();

private slots:
    void on_btnBuscar_clicked();

private:
    Ui::CitasPendientes* ui;
    gestorCitas& gestor;
};

#endif // CITASPENDIENTES_H
