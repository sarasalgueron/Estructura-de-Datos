#include "Pila.h"
#include <iostream>
#include "pila.h"

using namespace std;

Pila::Pila()
{
    cima = -1;
}

bool Pila::Apilar(int& elemento)
{
    bool res;
    if (cima == MAX - 1)
    {
        cout << "Desbordamiento de Pila (Overflow)" << endl;
        res = false;
    }
    else

    {
        cima++;
        pila[cima] = elemento;
        res = true;
    }
    return res;


}

bool Pila::Desapilar()
{
    bool res;
    if (cima == -1)
    {
        cerr << "Se esta intentando quitar un elemento de una pila vacia (underflow)" << endl;
        res = false;
    }
    else

    {
        cima--;
        res = true;
    }
    return res;


}

void Pila::VerPila()
{
    for (int i = 0; i <= cima; i++)
        cout << pila[i] << endl;

}


int Pila::CimaPila()
{
    if (PilaVacia())//(cima == -1)
    {
        cerr << "Se esta intentando quitar un elemento de una pila vacia (underflow)" << endl;
        return -1;
    }
    else

    {
        return pila[cima];
    }

}

bool Pila::PilaVacia()
{
    return cima == -1;
}

void Pila::LimpiarPila()
{
    cima = -1;
}


bool Pila::Iguales(Pila p)
{
    //int a, b;
    //int array[MAX];

    bool iguales = false;

    int i = cima;
    if (cima == p.getCima()) {
        while ((i >= 0) && (p.CimaPila() == pila[i]))
        {
            i--;
            p.Desapilar();
        }
        if (i < 0 && p.PilaVacia()) {
            iguales = true;
        }
    }

    return iguales;
}
int Pila::getCima() {
    return cima;
}
