// colasDinamicas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ColaDinamica.h"
using namespace std;
int main()
{
    ColaDinamica c;
    int opcion;
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Encolar" << endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "4. Tamano de cola" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            c.encolar();
            break;
        case 2:
            c.desencolar();
            break;
        case 3:
            c.mostrar();
            break;
        case 4:
            cout<<"El tamano de la cola es: "<<c.tamano()<<endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
        }
        
    } while (opcion != 0);
}

