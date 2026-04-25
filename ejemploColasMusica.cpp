// ejemploColasMusica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;
void Encolar(Nodo*& inicio, Nodo*& fin);
void Desencolar(Nodo*& inicio);
void Mostrar(Nodo*& inicio);
int main()
{
    Nodo* inicio = NULL, * fin = NULL; //Punteros libres para el manejo de la cola
    int opc = 0, respuesta = 0;
    do {
        cout << "1. LA COLA ESTA VACIA?" << endl;
        cout << "2. ENCOLAR" << endl;
        cout << "3. DESENCOLAR" << endl;
        cout << "4. FINALIZAR" << endl;
        cout << "5. MOSTRAR COLA" << endl;
        cout << "Opcion: "; cin >> opc;

        switch (opc) {
        case 1:
            if (inicio == NULL)
                cout << "La cola se encuentra vacia" << endl;
            else
                cout << "Existe elemento(s) dentro de la cola" << endl;
            break;
        case 2:
            Encolar(inicio, fin);
            break;
        case 3:
            Desencolar(inicio);
            break;
        case 5:
            Mostrar(inicio);
        }

    } while (opc != 4);

}
void Encolar(Nodo*& inicio, Nodo*& fin) { //Punteros enviados por referencia      
    Nodo* Elemento = new Nodo; //Creacion del nodo      
    if (inicio == NULL) {
        inicio = fin = Elemento; //Le asigno la direccion del primer nodo          
        cout << "Codigo: "; cin >> Elemento->cancion.Codigo;
        cin.ignore();
        cout << "Titulo: "; getline(cin, Elemento->cancion.Titulo);
        cout << "Artista: "; getline(cin, Elemento->cancion.Artista);
        cout << "Genero: "; getline(cin, Elemento->cancion.Genero);


    }
    else {
        fin->puntero = Elemento; //Asigno el puntero del anterior elemento al nuevo
        fin = Elemento; //Cambio la direccion del ultimo nodo creado 
        cout << "Codigo: "; cin >> Elemento->cancion.Codigo;
        cin.ignore();
        cout << "Titulo: "; getline(cin, Elemento->cancion.Titulo);
        cout << "Artista: "; getline(cin, Elemento->cancion.Artista);
        cout << "Genero: "; getline(cin, Elemento->cancion.Genero);


    }

} void Desencolar(Nodo*& inicio) {
    if (inicio != NULL) {
        cout << "Codigo: " << inicio->cancion.Codigo << endl;
        cout << "Titulo: " << inicio->cancion.Titulo << endl;
        cout << "Artista: " << inicio->cancion.Artista << endl;
        cout << "Genero: " << inicio->cancion.Genero << endl;
        inicio = inicio->puntero; // Cambio Inicio al siguiente nodo
    }
    else {
        cout << "La cola se encuentra vacia" << endl;
    }
}
void Mostrar(Nodo*& inicio) {
    Nodo* aux = inicio;
    if (inicio == NULL) {
        cout << "La cola esta vacia" << endl;
    }
    else {
        while (aux != NULL) {
            cout << "Codigo: " << aux->cancion.Codigo << endl;
            cout << "Titulo: " << aux->cancion.Titulo << endl;
            cout << "Artista: " << aux->cancion.Artista << endl;
            cout << "Genero: " << aux->cancion.Genero << endl;

            aux = aux->puntero; // Cambio Inicio al siguiente nodo
        }
    }
}
