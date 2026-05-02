#pragma once
#include "Nodo.h"
class ColaCircularDinam {
private:
    Nodo* frente;
    Nodo* final;

public:
    ColaCircularDinam();

    ~ColaCircularDinam();

    // Encola un nuevo elemento
    void encolar(const string& valor);

    // Desencola y devuelve el valor
    string desencolar();

    // ¿La cola está vacía?
    bool estaVacia();

    // Mostrar elementos recorriendo la cola
    void mostrar();
};
