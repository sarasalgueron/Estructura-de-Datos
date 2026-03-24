// arrayDeArrays.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include "Vector.h"
#include "Matriz.h"

// vector de vectores
void cargarVectorDeVectores(Vector v[], int n);
void mostrarVectorDeVectores(Vector v[], int n);
int main() {
	int n;
	do {
		cout << "Porfavor ingresar el tamanio: " << endl;
		cin >> n;
	} while (n > MAX || n <= 0);

	Vector vec[MAX];
	cargarVectorDeVectores(vec, n);
	mostrarVectorDeVectores(vec, n);

	Matriz mat;

	mat.cargarMatriz(vec, n);
	mat.mostrarMatriz();
	

}
void cargarVectorDeVectores(Vector v[], int n) {
	for (int i = 0;i < n;i++) {
		v[i].cargarVector(n);
	}
}
void mostrarVectorDeVectores(Vector v[], int n) {
	for (int i = 0;i < n;i++) {
		cout << "Vector "<< i <<": " << endl;
		v[i].mostrarVector();
	}
}

