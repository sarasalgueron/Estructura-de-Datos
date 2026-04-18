#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;
class Pila
{
	Nodo* inicio;
public:
	Pila();
	void push();
	void pop();
	void show();
	void top();
	void size();
};

