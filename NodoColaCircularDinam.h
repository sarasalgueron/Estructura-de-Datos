#pragma once
#include <iostream>
using namespace std;
struct Nodo {
    string valor;
    Nodo* sig;

    Nodo(string v) : valor(v), sig(nullptr) {}
};

