#pragma once
#define MAX 200
#include "Cliente.h"
#include <fstream>
#include <sstream>
class gestorClientes {
	// registrarCliente(), buscarCliente(), listarClientes()
	Cliente clientes[MAX];
	int totalClientes = 0;
public:
	void registrarCliente(Cliente c) {
		clientes[totalClientes] = c;
		totalClientes++;
	}
	Cliente* buscarCliente(string nombre) {
		for (int i = 0;i < totalClientes;i++) {
			if (clientes[i].getNombre() == nombre) {
				return &clientes[i];
			}
		}
		return nullptr;
	}
	Cliente* listarClientes() {
		return clientes;
	}

	void guardarArchivo() {
		// verificar que el archivo existe
		ofstream archivo("clientes.txt");
		if (!archivo.is_open()) {
			return;
		}
		for (int i = 0;i < totalClientes;i++) {
			archivo << clientes[i].getId() << ", " << clientes[i].getNombre() << ", " << clientes[i].getTelefono() << ", "  << endl;
		}
		archivo.close();
	}
	void cargarArchivo() {
		ifstream archivo("clientes.txt");

		if (!archivo.is_open()) {
			return;
		}
		string linea;
		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string sId, sNombre, sTelefono;

			getline(ss, sId, ',');
			getline(ss, sNombre, ',');
			getline(ss, sTelefono, ',');

			// convertir strings a los tipos correctos
			int id = stoi(sId);
			int tel = stoi(sTelefono);

			Cliente c(id, sNombre, tel);
			registrarCliente(c);
		}
		archivo.close();

	}

};
