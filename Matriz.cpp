#include "Matriz.h"
#include <iostream>
#include <string>
Matriz::Matriz() {
	n = 0;
}
void Matriz::cargarMatriz(Vector v[], int tam) {
	n = tam;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			mat[i][j].setN(n);
			for (int k = 0; k < n;k++) {
				mat[i][j].setDato(k, v[i].getDato(j));
			}
		}
	}
}
void Matriz::mostrarMatriz() {
	for (int i = 0;i < n;i++) {
		cout << "Fila " << i <<": "<<endl;
		for (int j = 0;j < n;j++) {
			cout << "Vector " << j << ": " << endl;
			mat[i][j].mostrarVector();
		}
	}
}
