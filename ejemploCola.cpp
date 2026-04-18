// ejemploCola.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Cola.h"
using namespace std;
int main()
{
    Cola q;
    int opcion = -1;
    char d;
    int e;
    do {
        cout << "----- MENU -----" << endl;
        cout << "1. Llenar cola"<<endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Mostrar cola"<<endl;
        cout << "4. Mostrar tamano de cola" << endl;
        cout << "0. Salir" << endl;

        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el elemento porfavor: " << endl;
            cin >> d;
            e = q.put(d);
            if (e != -1) {
                cout << "Elemento insertado correctamente" << endl;
            }
            else {
                cout << "No se pudo insertar el elemento" << endl;
            }
            break;
        case 2:
            e = q.get();
            if (e != -1) {
                cout << "El elemento eliminado fue " <<char(e) << endl;
            }
            break;
        case 3:
            if (!q.empty()) {
                q.verCola();
            }
            else {
                cout << "La cola esta vacia"<<endl;
            }
            break;
        case 4:
            cout<<q.size()<<endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Ingresar opcion valida"<<endl;
        }
    } while (opcion != 0);

    cout << "\nPara terminar oprima <Enter> ...";
    cin.get();
    return 0;
}
