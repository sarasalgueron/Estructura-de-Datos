// pilasIguales.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Pila.h"
#include <iostream>
using namespace std;
int main()
{
	Pila p;
	Pila p2;
	int opcion;
	int elemento;
	do {
		cout << "----- MENU -----"<<endl;
		cout << "1. Apilar" << endl;
		cout << "2. Desapilar" << endl;
		cout << "3. Mostrar pila" << endl;
		cout << "4. Mostrar cima"<<endl;
		cout << "5. Limpiar pila" << endl;
		cout << "6. Ver si dos pilas son iguales" << endl;
		cout << "0. Salir" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "Ingrese el elemento a colocar en la pila: " << endl;
			cin >> elemento;
			p.Apilar(elemento);
			break;
		case 2:
			p.Desapilar();
			break;
		case 3:
			p.VerPila();
			break;
		case 4:
			cout<<"El elemento en la cima de la pila es: "<<p.CimaPila()<<endl;
			break;
		case 5:
			p.LimpiarPila();
			break;
		case 6:
			elemento = 1;
			p2.Apilar(elemento);
			elemento = 2;
			p2.Apilar(elemento);
			elemento = 3;
			p2.Apilar(elemento);

			if (p.Iguales(p2)) {
				cout << "Si son iguales" << endl;
			}
			else {
				cout << "No son iguales" << endl;
			}
			break;
		case 0:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Ingrese una opcion valida" << endl;
			
		}
	} while (opcion != 0);
}
