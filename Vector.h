#pragma once
#define MAX 10
#include <iostream>
#include <string>
using namespace std;
class Vector

{
	private:
		string datos[MAX];
		int n;
	public:
		Vector();
		void cargarVector(int tam);
		void mostrarVector();
		void setN(int tam);
		int getN();
		void setDato(int pos, string dato);
		string getDato(int pos);

};

