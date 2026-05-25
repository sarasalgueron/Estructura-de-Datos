#pragma once
#include <string>
using namespace std;
class Persona {
protected:
	int id;
	string nombre;
	int telefono;
public:
	Persona() {
		id = 0;
		nombre = "";
		telefono = 0;
	}
	Persona(int _id, string _nombre, int _telefono) {
		id = _id;
		nombre = _nombre;
		telefono = _telefono;
	}
	int getId() {
		return id;
	}
	string getNombre() {
		return nombre;
	}
	int getTelefono() {
		return telefono;
	}
};
