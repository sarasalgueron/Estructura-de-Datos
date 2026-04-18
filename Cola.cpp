#include "Cola.h"

Cola::Cola() {
    cabeza = 0;
    cola = 0;
    ITEMS = 0;
    ITEMSIZE = 1;
}

// destructor
Cola::~Cola() {}

// regresa 1 (true) si la lista está vacia
int Cola::empty() { return ITEMS == 0; }

// insertar elemento a la lista
int Cola::put(int d)
{
    if (ITEMS == MAX_SIZE) return -1;
    if (cola >= MAX_SIZE) { cola = 0; }
    alma[cola] = d;
    cola++;
    ITEMS++;
    return d;
}

// retirar elemento de la lista
int Cola::get()
{
    char d;
    if (empty()) return -1;
    if (cabeza >= MAX_SIZE) { cabeza = 0; }
    d = alma[cabeza];
    cabeza++;
    ITEMS--;
    return d;
}

// regresa el numero de elementos en lista
int Cola::size() { return ITEMS; }

 // fin de la clase Queue

void Cola::verCola() {
    for (int i = cabeza;i < cola;i++) {
        cout << "Item " << i << ": " << alma[i]<<endl;
    }
}

