#pragma once

#define MAX 100
class Pila
{
private:
    int pila[MAX];
    int cima;

public:
    Pila();
    bool Apilar(int& elemento);
    bool Desapilar();
    int CimaPila();
    void LimpiarPila();
    void VerPila();
    bool PilaVacia();
    bool Iguales(Pila p);
    int getCima();

};