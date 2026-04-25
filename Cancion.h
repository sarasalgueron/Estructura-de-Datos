#pragma once
#include<iostream>
using namespace std;
class Cancion
{
public:
    double Codigo;
    string Titulo;
    string Artista;
    string Genero;
    Cancion() {
        Codigo = 0;
        Titulo = "Desconocido";
        Artista = "Desconocido";
        Genero = "Desconocido";
    }
};

