#pragma once
#include "Vector.h"
class Matriz
{
	private:
		Vector mat[MAX][MAX];
		int n;
	public:
		Matriz();
		void cargarMatriz(Vector v[],int tam);
		void mostrarMatriz();
};

