#include "Vector.h"
Vector::Vector() {
	n = 0;
}
void Vector::cargarVector(int tam) {
	n = tam;
	for (int i = 0;i < n;i++) {
		cout << "Elemento" << i << endl;
		cin >> datos[i];
	}
}
void Vector::mostrarVector() {
	for (int i = 0;i < n;i++) {
		cout << "Elemento "<<i<<": "<<datos[i]<< endl;
		
	}
}
void Vector::setN(int tam) {
	n = tam;
}
int Vector::getN() {
	return n;
}
void Vector::setDato(int pos, string dato) {
	datos[pos] = dato;
}
string Vector::getDato(int pos) {
	return datos[pos];
}
