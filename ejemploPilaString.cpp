// pilasIguales.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Pila.h"
#include <iostream>
using namespace std;
int main()
{
    Pila a;
    Pila b;
    string s = "sara";
    string s2 = "hola";

    a.Apilar(s);
    a.Apilar(s);
    a.VerPila();

    b.Apilar(s);
    b.Apilar(s2);
    b.VerPila();

    bool res = a.Iguales(b);
    if (res == true) {
        cout << "Son iguales";
    }
    else {
        cout << "No son iguales";
    }
}