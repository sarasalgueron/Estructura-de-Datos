// pilasIguales.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Pila.h"
#include <iostream>
using namespace std;
int main()
{
    Pila a;
    Pila b;
    //int n;
    //do {
        //cout << "Ingrese numero de elementos de la pila";
        //cin >> n;
    //} while (n > 0 || n <= 0);


    int e = 6;
    int e2 = 8;

    a.Apilar(e);
    a.Apilar(e2);
    a.Apilar(e);
    a.VerPila();

    b.Apilar(e);
    b.Apilar(e2);
    b.VerPila();

    bool res = a.Iguales(b);
    if (res == true) {
        cout << "Son iguales";
    }
    else {
        cout << "No son iguales";
    }
}