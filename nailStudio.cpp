#include <QMessageBox>
#include <QInputDialog>
#include <functional>
#include <QCloseEvent>
#include "nailStudio.h"
#include "Cola.h"
#include "pantallacliente.h"
#include "Pila.h"
#include "Servicio.h"
#include "Diseno.h"
#include "Cita.h"
#include "pantallaadmin.h"
#include "Cliente.h"
nailStudio::nailStudio(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    gestorCli.cargarArchivo();
    gestor.cargarArchivo();

}

nailStudio::~nailStudio()
{
}
void nailStudio::on_BtnAdm_clicked()
{
    bool ok;
    QString contrasena = QInputDialog::getText(
        this, "Acceso Administradora",
        "Ingresa la contrasena:",
        QLineEdit::Password, "", &ok
    );

    if (ok) {
        // Hash de "admin2026"
        size_t hashGuardado = std::hash<string>{}("admin2026");
        size_t hashIngresado = std::hash<string>{}(contrasena.toStdString());

        if (hashIngresado == hashGuardado) {
            PantallaAdmin ventana(gestor, gestorCli, this);
            ventana.exec();
        }
        else {
            QMessageBox::warning(this, "Error", "Contrasena incorrecta");
        }
    }
}

void nailStudio::on_BtnCliente_clicked()
{
    PantallaCliente ventanaCliente(gestor, gestorCli, this);
    ventanaCliente.exec();
}
void nailStudio::closeEvent(QCloseEvent* event) {
    gestorCli.guardarArchivo();
    gestor.guardarArchivo();
    event->accept();
}