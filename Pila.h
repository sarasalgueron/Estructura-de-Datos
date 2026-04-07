#pragma once
using namespace std;
#include <string>
#define MAX 100
class Pila
{
private:
    string pila[MAX];
    int cima;

public:
    Pila();
    bool Apilar(string& elemento);
    bool Desapilar();
    string CimaPila();
    void LimpiarPila();
    void VerPila();
    bool PilaVacia();
    bool Iguales(Pila p);
    int getCima();

};