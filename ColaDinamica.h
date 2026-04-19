#pragma once
#include "Nodo2.h"
class ColaDinamica
{
	Nodo2* inicio;
	Nodo2* final;
public:
	ColaDinamica();
	void encolar();
	void desencolar();
	void mostrar();
	int tamano();
	bool colaVacia();
};

