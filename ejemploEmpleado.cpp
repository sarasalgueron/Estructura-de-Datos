// ejemploEmpleado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Empleado.h"
int main()
{
    Empleado e1("Sara", "Salguero", "Analista");

    e1.mostrarInformacion();

    e1.cambiarCargo("Jefe de Proyecto");

    e1.corregirApellido("Perez-Ramirez");

    e1.mostrarInformacion();

    e1.depurarNombre();
}