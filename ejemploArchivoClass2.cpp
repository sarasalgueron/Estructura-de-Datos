// ejemploArchivoClass2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <iostream>
#include <fstream>
#include "ABMamigo.h"
using namespace std;
int main()
{
    ABMamigo* amig = new ABMamigo("amigOO.dat");
    int opcion;
   
    do {
        cout << "----- MENU -----" <<endl;
        cout << "1. Registrar " << endl;
        cout << "2. Eliminar " << endl;
        cout << "3. Modificar " << endl;
        cout << "4. Listar" << endl;
        cout << "5. Buscar" << endl;
        cout << "0. Salir" << endl;

        
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            amig->adicionarNuevo();
            break;
        case 2:
            amig->eliminarReg();
            break;
        case 3:
            amig->modificarReg();
            break;
        case 4:
            amig->listar();
            break;
        case 5:
            amig->buscarReg();
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Ingrese una opcion valida" << endl;
        }
    } while (opcion != 0);
     
}
