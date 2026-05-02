// colaCircularEstatica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ColaCircular.h"
#include <string>
#include <sstream>
using namespace std;
int main()
{
    ColaCircular cola;
    string linea;

    cout << "Ingrese palabras separadas por espacios: ";
    getline(cin, linea);

    stringstream ss(linea);
    string palabra;

    // Separar y encolar
    while (ss >> palabra) {
        if (!cola.encolar(palabra)) {
            cout << "Cola llena. No se pudo insertar: " << palabra << endl;
        }
    }

    // Mostrar contenido
    cola.mostrar();

    // Atender (vaciar la cola)
    cout << "\nAtendiendo cola...\n";
    while (!cola.estaVacia()) {
        cout << "Atendido: " << cola.desencolar() << endl;
    }

    return 0;
}
