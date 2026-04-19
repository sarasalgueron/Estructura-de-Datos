#include "ColaDinamica.h"
#include <iostream>
using namespace std;
ColaDinamica::ColaDinamica() {
	inicio = NULL;
	final = NULL;
}
void ColaDinamica::encolar() {
	int valor;
	string valor2;
	Nodo2* aux = new Nodo2;

	system("cls");
	cout << "Ingresa el id del proceso: ";
	cin >> valor;
	cout << "Ingresa el nombre del proceso: ";
	cin.ignore();
	getline(cin, valor2);
	aux->dato = valor;
	aux->nombre = valor2;
	aux->siguiente = NULL;

	if (colaVacia()) {
		inicio = aux;
	}
	else {
		final->siguiente = aux;
		cout << "Elemento insertado en cola" << endl;
	}
	final = aux;
	system("pause");
}
void ColaDinamica::desencolar() {
	Nodo2* temp;
	if (colaVacia()) {
		system("cls");
		cout << "La cola esta vacia"<<endl;
		system("pause");
	}
	else {
		temp = inicio;
		inicio = inicio->siguiente;
		system("cls");
		cout << "El elemento eliminado es: " << temp->dato << "-" << temp->nombre << endl;
		if (inicio == NULL) {
			final = NULL;
		}
		delete temp;
		system("pause");
	}
	
}
void ColaDinamica::mostrar() {
	Nodo2* aux2 = inicio;
	if (colaVacia()) {
		system("cls");
		cout << "La cola esta vacia" << endl;
		system("pause");
	}
	else {
		system("cls");
		cout << "Procesos:\n" << endl;
		while (aux2 != NULL) {
			cout << aux2->dato << "-" << aux2->nombre << endl;
			aux2 = aux2->siguiente;
		}
		system("pause");
	}
}
int ColaDinamica::tamano() {
	Nodo2* temp = inicio;
	int contador = 0;
	if (colaVacia()) {
		return contador;
	}
	else {
		while (temp != NULL) {
			contador++;
			temp = temp->siguiente;
		}
	}
	return contador;
}

bool ColaDinamica::colaVacia() {
	return (inicio == NULL);
}