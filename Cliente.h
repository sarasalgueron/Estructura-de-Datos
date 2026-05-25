#pragma once
#include "Pila.h"
#include "Cita.h"
#include "Persona.h"
class Cliente: public Persona {
	Pila<Cita> historial;
public:
	Cliente(): Persona() {}
	Cliente(int _id, string _nombre, int _telf) : Persona(_id, _nombre, _telf) {}

	void setTelefono(int _telefono) {
		telefono = _telefono;
	}

	Pila<Cita> verHistorial() {
		return historial;
	}

	void agregarCita(Cita c) {
		historial.apilar(c);
	}
};
